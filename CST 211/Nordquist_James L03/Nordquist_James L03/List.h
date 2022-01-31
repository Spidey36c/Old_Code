/************************************
* Author: James Nordquist
* Filename: List.h
* Date Created: 1/9/19
* Modifications: 2/11/19 - made a fix to extract, extract didn't expect for head to be the last node
*
*************************************/
/************************************************************************
* Class: List
*
* Purpose: This class creates a card that holds a value and a suit
* Manager functions:
* List ()
*	m_head and m_tail are set to nullptr
* List (const Card & copy)
*	Copy Ctor
* operator = (const Card & copy)
*	op =
* ~Card()
*	data is set to default or zero
*
* Methods:
* bool IsEmpty();
*	returns true if m_head is null
* const T & First();
*	returns a const ref to the data in the first node
* const T & Last();
*	returns a const ref to the data in the last node
* void Prepend(T data);
*	puts the new data in front of the list, and sets m_head to it
* void Append(T data);
*	puts the new data at the end of the list and set m_tail to it
* void Purge();
*	deletes all the data in the list and sets m_head and m_tail to nullptr
* void Extract(T data);
*	deletes a node if it has the same data as the data passed in
* void InsertAfter(T olddata, T newdata);
*	inserts new data after a node if the node has the olddata in it
* void InsertBefore(T olddata, T newdata);
*	inserts new data before a node if the node has the olddata in it
* Node<T> * GetHead() const;
*	returns a node * to the head
* Node<T> * GetTail() const;
*	returns a node * to the tail
* void printForwards();
*	prints the data starting from m_head to m_tail
* void printBackwards();
*	prints the data starting from m_tail to m_head
*************************************************************************/
#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include "Exception.H"
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class List
{
public:
	List();
	List(const List & copy);
	~List();
	List & operator =(const List & rhs);
	bool IsEmpty();
	const T & First();
	const T & Last();
	void Prepend(T data);
	void Append(T data);
	void Purge();
	void Extract(T data);
	void InsertAfter(T olddata, T newdata);
	void InsertBefore(T olddata, T newdata);
	Node<T> * GetHead() const;
	Node<T> * GetTail() const;
	void printForwards();
	void printBackwards();
private:
	Node<T> * m_head; 
	Node<T>* m_tail; //don't think we would need a setter for head and tail
};

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* Object is created
*
* Postcondition:
* Object is instantiated
*
************************************************************************/
template<typename T>
List<T>::List() : m_head(nullptr), m_tail(nullptr)
{

}

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* Object is created with and existing object
*
* Postcondition:
* Object is instantiated using the existing objects data
*
************************************************************************/
template<typename T>
List<T>::List(const List & copy)
{
	if (copy.m_head != nullptr)
	{
		Node<T> * travel = copy.m_head;
		Node<T> * new_travel = m_head;
		Node<T> * new_trail;

		m_head = new Node<T>(travel->m_data);
		new_travel = m_head;
		travel = travel->m_next;
		new_trail = new_travel;
		
		while (travel != nullptr)
		{
			new_travel->m_next = (new Node<T>(travel->m_data));

			travel = travel->m_next;
			new_travel = new_travel->m_next;
			new_travel->m_prev = new_trail; 
			new_trail = new_trail->m_next;	
		}
		m_tail = new_travel;
	}
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* Object is deleted or goes out of scope
*
* Postcondition:
* List is emptied and data is set to default
*
************************************************************************/
template<typename T>
List<T>::~List()
{
	Purge(); //tail and head should both be nullptr from purge
}

/**********************************************************************
* Purpose: op =
*
* Precondition:
* Object is set to equal another existing Object
*
* Postcondition:
* Object's data is set to the other Objects data
*
************************************************************************/
template<typename T>
List<T> & List<T>::operator=(const List & rhs)
{
	if (this != &rhs)
	{
		Purge();
		if (rhs.m_head != nullptr)
		{
			Node<T> * travel = rhs.m_head;
			Node<T> * new_travel = m_head;
			Node<T> * new_trail;

			m_head = new Node<T>(travel->m_data);
			new_travel = m_head;
			travel = travel->m_next;
			new_trail = new_travel;

			while (travel != nullptr)
			{
				new_travel->m_next = (new Node<T>(travel->m_data));
				travel = travel->m_next;
				new_travel = new_travel->m_next;
				new_travel->m_prev = new_trail;
				new_trail = new_trail->m_next;
			}
			m_tail = new_travel;
		}
	}

	return *this;
}

/**********************************************************************
* Purpose: returns a bool true or false whether m_head is nullptr or not
*
* Precondition:
* function is called
*
* Postcondition:
* returns true if m_head is nullptr, false if not
*
************************************************************************/
template<typename T>
bool List<T>::IsEmpty()
{
	return m_head == nullptr ? true : false;
}

/**********************************************************************
* Purpose: returns const ref of data in the first node
*
* Precondition:
* function is called
*
* Postcondition:
* returns a const ref of m_heads data
*
************************************************************************/
template<typename T>
const T & List<T>::First()
{
	return m_head->m_data;
}

/**********************************************************************
* Purpose: returns const ref of data in the last node
*
* Precondition:
* function is called
*
* Postcondition:
* returns a const ref of m_tails data
*
************************************************************************/
template<typename T>
inline const T & List<T>::Last()
{
	return m_tail->m_data;
}

/**********************************************************************
* Purpose: places new data in front of the list
*
* Precondition:
* data - templated data to be inserted in the list
*
* Postcondition:
* new node is created in list and m_head is set to it
*
************************************************************************/
template<typename T>
void List<T>::Prepend(T data)
{
	Node<T> * nn = new Node<T>(data);
	if (IsEmpty() == true)
	{
		m_head = nn;
		m_tail = m_head; //only 1 element in array now
	}
	else if(m_head->m_next == nullptr) //only 1 element in array
	{
		nn->m_next = m_head;
		m_head->m_prev = nn;
		m_head = nn;
		m_tail = m_head->m_next; //2 elements in array now
	}
	else //2 or more elements in list
	{
		nn->m_next = m_head;
		m_head->m_prev = nn;
		m_head = nn;
	}
}

/**********************************************************************
* Purpose: places new data at the back of the list
*
* Precondition:
* data - templated data to be inserted in the list
*
* Postcondition:
* new node is created in list and m_tail is set to it
*
************************************************************************/
template<typename T>
void List<T>::Append(T data)
{
	Node<T> * nn = new Node<T>(data);
	if (IsEmpty() == true)
	{
		m_head = nn;
		m_tail = m_head;
	}
	else //The list has at least 1 element
	{
		m_tail->m_next = nn;
		nn->m_prev = m_tail;
		m_tail = nn;
	}
}

/**********************************************************************
* Purpose: destroys the list
*
* Precondition:
* function is called explicitly or is called from dtor
*
* Postcondition:
* list is emptied and m_head and m_tail are set to nullptr
*
************************************************************************/
template<typename T>
void List<T>::Purge()
{
	Node<T> * trail = m_head;

	while (m_head != nullptr)
	{
		m_head = m_head->m_next;
		delete trail;
		trail = m_head;
	}
	m_tail = m_head;
}

/**********************************************************************
* Purpose: removes data from the list
*
* Precondition:
* data - templated data to be removed from the list
*
* Postcondition:
* if the data exists in the list, the node is removed, otherwise an exception is thrown
*
************************************************************************/
template<typename T>
void List<T>::Extract(T data)
{
	bool found = false;
	Node<T> * travel = m_head; //is there a faster way to go through the list without iterating?
	Node<T> * trail;
	
	while (travel != nullptr && found == false)
	{
		if (travel->m_data == data)
		{
			found = true;
		}
		trail = travel;
		travel = travel->m_next;
	}

	if (found == false)
	{
		throw Exception("Node not found.");
	}
	else
	{
		if (trail != m_head && trail != m_tail) //if we are not at the end or beginning of list
		{
			Node<T> * temp;
			temp = trail->m_prev;
			temp->m_next = travel;
			travel->m_prev = temp;
			delete trail;
		}
		else if(trail == m_head)
		{
			m_head = travel;
			if (m_head != nullptr)
			{
				m_head->m_prev = nullptr;
			}
			delete trail;
		}
		else //we are at the end of the list
		{
			Node<T> * temp;
			temp = trail->m_prev;
			m_tail = temp;
			m_tail->m_next = nullptr;
			delete trail;
		}
	}

}

/**********************************************************************
* Purpose: places new data in front of a node
*
* Precondition:
* newdata - templated data to be inserted in the list
* olddata - the data used to see if newdata can be inserted
*
* Postcondition:
* if oldata exists in a node, newdata is inserted into the list after olddata
* otherwise an exception is thrown
*
************************************************************************/
template<typename T>
void List<T>::InsertAfter(T newdata, T olddata)
{
	bool found = false;
	Node<T> * travel = m_head;
	Node<T> * trail;

	while (travel != nullptr && found == false)
	{
		if (travel->m_data == olddata)
		{
			found = true;
		}
		trail = travel;
		travel = travel->m_next;
	}

	if (found == false)
	{
		throw Exception("Node does not exist.");
	}
	else
	{
		Node<T> * nn = new Node<T>(newdata);
		if (trail == m_tail) //could just use Append, but I think it might be smarter to not
		{
			trail->m_next = nn;
			nn->m_prev = m_tail;
			m_tail = nn;
		}
		else
		{
			trail->m_next = nn;
			travel->m_prev = nn;
			nn->m_next = travel;
			nn->m_prev = trail;
		}
	}
}

/**********************************************************************
* Purpose: places new data behind a node
*
* Precondition:
* newdata - templated data to be inserted in the list
* olddata - the data used to see if newdata can be inserted
*
* Postcondition:
* if oldata exists in a node, newdata is inserted into the list before olddata
* otherwise an exception is thrown
*
************************************************************************/
template<typename T>
void List<T>::InsertBefore(T newdata, T olddata)
{
	bool found = false;
	Node<T> * travel = m_head;
	Node<T> * trail;

	while (travel != nullptr && found == false)
	{
		if (travel->m_data == olddata)
		{
			found = true;
		}
		trail = travel;
		travel = travel->m_next;
	}

	if (found == false)
	{
		throw Exception("Node does not exist.");
	}
	else
	{
		Node<T> * nn = new Node<T>(newdata);
		if (trail == m_head) //could use prepend but don't want to
		{
			trail->m_prev = nn;
			nn->m_next = trail;
			m_head = nn;
		}
		else
		{
			Node<T> * temp;
			temp = trail->m_prev;
			temp->m_next = nn;
			trail->m_prev = nn;
			nn->m_prev = temp;
			nn->m_next = trail;
		}
	}

}

/**********************************************************************
* Purpose: getter for m_head
*
* Precondition:
* function is called
*
* Postcondition:
*	returns m_head 
*
************************************************************************/
template<typename T>
Node<T> * List<T>::GetHead() const
{
	return m_head;
}

/**********************************************************************
* Purpose: getter for m_tail
*
* Precondition:
* function is called
*
* Postcondition:
*	returns m_head
*
************************************************************************/
template<typename T>
Node<T> * List<T>::GetTail() const
{
	return m_tail;
}

/**********************************************************************
* Purpose: prints the data front to back starting at m_head
*
* Precondition:
* function is called
*
* Postcondition:
* prints every nodes data starting from m_head and ending at m_tail
*
************************************************************************/
template<typename T>
void List<T>::printForwards()
{
	Node<T> * travel = m_head;
	while (travel != nullptr)
	{
		cout << travel->m_data << endl;
		travel = travel->m_next;
	}
}

/**********************************************************************
* Purpose: prints the data back to front starting at m_tail
*
* Precondition:
* function is called
*
* Postcondition:
* prints every nodes data starting from m_tail and ending at m_head
*
************************************************************************/
template<typename T>
void List<T>::printBackwards()
{
	Node<T> * travel = m_tail;
	while (travel != nulltpr)
	{
		cout << travel->m_data << endl;
		travel = travel->m_prev;
	}
}


#endif

