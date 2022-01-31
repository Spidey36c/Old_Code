/*************************************************************
* Author: James Nordquist
* Filename: HashNode.h
* Date Created: 3/12/19
* Modifications: 3/13/19 - added SetKey for using delete function in hash table
**************************************************************/
#ifndef HASHNODE_H
#define HASHNODE_H

/************************************************************************
* Class: HashNode
*
* Purpose: This class is a container class for a hash table
*
* Manager functions:
* HashNode();
*	default ctor
* HashNode(V Value, K Key);
*	two arg ctor
* HashNode(const HashNode & copy);
*	copy ctor
* ~HashNode();
*	dtor
* HashNode & operator =(const HashNode & rhs);
*	op =
*
* Methods:
* bool operator==(const HashNode & rhs);
*	compares two HashNode's Keys
* bool operator==(const K & key);
*	compares this key against the passed in key
* V GetValue();
*	returns the value the node is holding
* void SetKey(K key);
*	setter for key
* K GetKey();
*	getter for key
*************************************************************************/
template<typename V, typename K>
class HashNode
{
public:
	HashNode();
	HashNode(V value, K key);
	HashNode(const HashNode & copy);
	~HashNode();
	HashNode & operator =(const HashNode & rhs);
	bool operator==(const HashNode & rhs);
	bool operator==(const K & key);
	V GetValue();
	void SetKey(K key);
	K GetKey();
private:
	V m_value;
	K m_key;
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
HashNode<V, K>::HashNode()
{
}

/**********************************************************************
* Purpose: Two arg ctor
*
* Precondition:
* value, key - desired values for node
*
* Postcondition:
* Object is instantiated with assigned values
*
************************************************************************/
template<typename V, typename K>
HashNode<V, K>::HashNode(V value, K key): m_value(value), m_key(key)
{
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
HashNode<V, K>::HashNode(const HashNode & copy): m_key(copy.m_key), m_value(copy.m_value)
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
HashNode<V, K>::~HashNode()
{
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
HashNode<V,K> & HashNode<V, K>::operator=(const HashNode & rhs)
{
	if (this != &rhs)
	{
		m_value = rhs.m_value;
		m_key = rhs.m_key;
	}
	return *this;
}

/**********************************************************************
* Purpose: op==
*
* Precondition:
* compares this key and rhs key
*
* Postcondition:
* returns true if they are the same, false otherwise
*
************************************************************************/
template<typename V, typename K>
bool HashNode<V, K>::operator==(const HashNode & rhs)
{
	return m_key == rhs.m_key;
}

/**********************************************************************
* Purpose: op==
*
* Precondition:
* compares this key and passed in key
*
* Postcondition:
* returns true if they are the same, false otherwise
*
************************************************************************/
template<typename V, typename K>
bool HashNode<V, K>::operator==(const K & key)
{
	return m_key == key;
}

/**********************************************************************
* Purpose: Getter for value
*
* Precondition:
* function is called
*
* Postcondition:
* m_value is returned
*
************************************************************************/
template<typename V, typename K>
V HashNode<V, K>::GetValue()
{
	return m_value;
}

/**********************************************************************
* Purpose: Setter for key
*
* Precondition:
* key - desired value for m_key 
*
* Postcondition:
* m_key is set to key
*
************************************************************************/
template<typename V, typename K>
void HashNode<V, K>::SetKey(K key)
{
	m_key = key;
}

/**********************************************************************
* Purpose: Getter for key
*
* Precondition:
* function is called
*
* Postcondition:
* m_key is returned
*
************************************************************************/
template<typename V, typename K>
K HashNode<V, K>::GetKey()
{
	return m_key;
}


#endif

