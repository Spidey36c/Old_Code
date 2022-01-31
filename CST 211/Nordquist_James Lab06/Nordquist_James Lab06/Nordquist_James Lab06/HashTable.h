/*************************************************************
* Author: James Nordquist
* Filename: HashTable.h
* Date Created: 3/12/19
* Modifications:
**************************************************************/
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "HashNode.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::find;
using std::exception;

/************************************************************************
* Class: HashTable
*
* Purpose: This class is a container class for a hash table
*
* Manager functions:
* HashTable();
*	default ctor
* HashTable(int length);
*	one arg ctor
* HashTable(const HashTable & copy);
*	copy ctor
* ~HashTable();
*	dtor
* HashTable & operator =(const HashTable & rhs);
*	op =
*
* Methods:
* void Insert(K key, V value);
*	Inserts a HashNode into the list at the index that the hashfnc(key) returns
* void setHash(int(*hash)(K key));
*	sets hashfnc to a hashing function, and rehashes the table
* V operator [] (K key);
*	returns the node in the list at the hash index if it exists, else throws exception
* void Delete(K key);
*	deletes the node in the list at the hash index if it exists
* void Traverse(void(*visit)(V value));
*	iterates through the table and passes the values to visit function
*************************************************************************/
template<typename V, typename K>
class HashTable
{
public:
	HashTable();
	HashTable(int length);
	HashTable(const HashTable & copy);
	~HashTable();
	HashTable & operator=(const HashTable & rhs);
	void Insert(K key, V value);
	void setHash(int(*hash)(K key)); // store the function ptr in data member
	V operator [] (K key);
	void Delete(K key);
	void Traverse(void(*visit)(V value));
private:
	int (*m_hashfnc)(K key);
	int m_length;
	vector<list<HashNode<V,K>>> m_hash;
};

/**********************************************************************
* Purpose: Default Ctor
*
* Precondition:
* Object is created
*
* Postcondition:
* Object is instantiated with default value
*
************************************************************************/
template<typename V, typename K>
HashTable<V, K>::HashTable() : m_hashfnc(nullptr), m_length(0)
{
}

/**********************************************************************
* Purpose: One arg ctor
*
* Precondition:
* lenght - desired length of table array
*
* Postcondition:
* Object is instantiated with assigned values
*
************************************************************************/
template<typename V, typename K>
HashTable<V, K>::HashTable(int length) : m_hashfnc(nullptr), m_length(length)
{
	m_hash.resize(length);
}

/**********************************************************************
* Purpose: Copy ctor
*
* Precondition:
* Object is created with another object
*
* Postcondition:
* Object is instantiated with the other objects data
*
************************************************************************/
template<typename V, typename K>
HashTable<V, K>::HashTable(const HashTable & copy) : m_hashfnc(copy.m_hashfnc), m_length(copy.m_length), m_hash(copy.m_hash)
{
}

/**********************************************************************
* Purpose: Dtor
*
* Precondition:
* Object is deleted or goes out of scope
*
* Postcondition:
* Object is deleted and values go back to default
*
************************************************************************/
template<typename V, typename K>
HashTable<V, K>::~HashTable()
{
	m_hashfnc = nullptr;
	m_length = 0;
}

/**********************************************************************
* Purpose: op =
*
* Precondition:
* Object is set equal to rhs
*
* Postcondition:
* Object data is the same as rhs
*
************************************************************************/
template<typename V, typename K>
HashTable<V, K> & HashTable<V, K>::operator=(const HashTable & rhs)
{
	if (this != &rhs)
	{
		m_hashfnc = rhs.m_hashfnc;
		m_hash = rhs.m_hash;
		m_length = rhs.m_length;
	}
	return *this;
}

/**********************************************************************
* Purpose: Inserts a node into the table
*
* Precondition:
* key - key passed to the hashing function to find proper index, also the key
*		of node to be inserted
* value - desired value of node
*
* Postcondition:
* inserts HashNode with desired value and key
*
************************************************************************/
template<typename V, typename K>
void HashTable<V, K>::Insert(K key, V value)
{
	int index = m_hashfnc(key);

	HashNode<V, K> temp(value, key);

	m_hash[index].push_back(temp);
}

/**********************************************************************
* Purpose: Setter for hash function
*
* Precondition:
* hash - desired hash function to hash the table
*
* Postcondition:
* rehashes the table based on the new hash function
*
************************************************************************/
template<typename V, typename K>
void HashTable<V, K>::setHash(int(*hash)(K key))
{
	m_hashfnc = hash;
	vector<list<HashNode<V, K>>> temp;
	temp.resize(m_length);

	for (typename vector<list<HashNode<V, K>>>::iterator it = m_hash.begin(); it != m_hash.end(); it++)
	{
		for (typename list<HashNode<V, K>>::iterator lit = it->begin(); lit != it->end(); lit++)
		{
			temp[m_hashfnc(lit->GetKey())].push_back(*lit);
		}
	}

	m_hash = temp;
}

/**********************************************************************
* Purpose: op[]
*
* Precondition:
* key - key to find in table
*
* Postcondition:
* returns node if key is found, otherwise an exception is thrown
*
************************************************************************/
template<typename V, typename K>
V HashTable<V, K>::operator[](K key)
{
	bool found = false;
	V toreturn;
	int index = m_hashfnc(key);

	for (typename list<HashNode<V, K>>::iterator lit = m_hash[index].begin(); lit != m_hash[index].end() && !found; lit++)
	{
		if (lit->GetKey() == key)
		{
			toreturn = lit->GetValue();
			found = true;
		}
	}

	if (!found)
	{
		throw exception("Data not found");
	}

	return toreturn;
}

/**********************************************************************
* Purpose: deletes a node with passed in key if it exists in table
*
* Precondition:
* key - key to find in table
*
* Postcondition:
* deletes HashNode in table if the key exists
*
************************************************************************/
template<typename V, typename K>
void HashTable<V, K>::Delete(K key)
{
	int index = m_hashfnc(key);

	HashNode<V, K> todel;

	todel.SetKey(key);

	m_hash[index].remove(todel);
}

/**********************************************************************
* Purpose: table traversal
*
* Precondition:
* visit - function passed in to do something to the values in the table
*
* Postcondition:
* N/A
*
************************************************************************/
template<typename V, typename K>
void HashTable<V, K>::Traverse(void(*visit)(V value))
{
	if (m_hash.size() == 0)
	{
		throw exception("Hash Table empty");
	}

	for (int i = 0; i < m_hash.size(); i++)
	{
		for (typename list<HashNode<V, K>>::iterator lit = m_hash[i].begin(); lit != m_hash[i].end(); lit++)
		{
			cout << lit->GetValue() << endl;;
		}
	}
}


#endif

