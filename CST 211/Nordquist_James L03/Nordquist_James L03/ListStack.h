/********************************************************************************************
* Author: James Nordquist
* Filename : ListStack.h
* Date Created : 2/3/19
* Modifications Made :
*********************************************************************************************** /
/************************************************************************
* Class:ListStack
*
* Purpose: This class is a stack using a list to hold its data
* Manager functions:
* ListStack ()
*	m_size is set to 0
* ListStack (const ListStack & copy)
*	Copy Ctor
* operator = (const ListStack & copy)
*	op =
* ~ListStack()
*	m_size is set to zero and list is emptied
*
* Methods:
* void Push(T data);
*	Appends the data passed in to the list
* T Pop();
*	Gets the data at the end of the list and removes the last node in the list
*	then returns the data
* T Peek();
*	Gets the data at the end of the list then returns it
* int Size();
*	returns the size of the stack
* bool IsEmpty();
*	returns true if the stack is empty, false otherwise
*************************************************************************/
#ifndef LISTSTACK_H
#define LISTSTACK_H
#include "List.h"
#include "Exception.h"
#include "Node.h"

template<typename T>
class ListStack
{
public:
	ListStack();
	ListStack(const ListStack & copy);
	~ListStack();
	ListStack & operator =(const ListStack & rhs);
	void Push(T data);
	T Pop();
	T Peek();
	int Size();
	bool IsEmpty();
private:
	List<T> m_data;
	int m_size;
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
ListStack<T>::ListStack(): m_size(0)
{
}

/**********************************************************************
* Purpose: copy ctor
*
* Precondition:
* Object is created using another existing object
*
* Postcondition:
* Object is instantiated with the existing objects data
*
************************************************************************/
template<typename T>
ListStack<T>::ListStack(const ListStack & copy) : m_data(copy.m_data), m_size(copy.m_size)
{
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* Object is deleted to goes out of scope
*
* Postcondition:
* Object is destroyed
*
************************************************************************/
template<typename T>
ListStack<T>::~ListStack()
{
	m_size = 0;
	m_data.Purge();
}

/**********************************************************************
* Purpose: op =
*
* Precondition:
* Object is set to equal another object
*
* Postcondition:
* Object's data is set to the same as the other object
*
************************************************************************/
template<typename T>
ListStack<T> & ListStack<T>::operator=(const ListStack & rhs)
{
	if (this != &rhs)
	{
		m_data = rhs.m_data;
		m_size = rhs.m_size;
	}
	return *this;
}

/**********************************************************************
* Purpose: places new data at the top of the stack
*
* Precondition:
* data - data to be placed in the stack
*
* Postcondition:
* data is placed at the end of the list, or at the top of the stack
*
************************************************************************/
template<typename T>
void ListStack<T>::Push(T data)
{
	m_data.Append(data);
	m_size++;
}

/**********************************************************************
* Purpose: removes the data from the top of the stack and returns it
*
* Precondition:
* function is called
*
* Postcondition:
* the data from the end of the list is found and the last node is removed from the list
* then the data is returned
*
************************************************************************/
template<typename T>
T ListStack<T>::Pop()
{
	T data;
	Node<T> *ndata;
	if (m_size == 0)
	{
		throw Exception("Stack Underflow");
	}
	else
	{
		ndata = m_data.GetTail();
		data = ndata->GetData();
		m_data.Extract(data);
		m_size--;
	}
	return data;
}

/**********************************************************************
* Purpose: returns the data from the top of the stack
*
* Precondition:
* function is called
*
* Postcondition:
* the data from the end of the list is found and returned
*
************************************************************************/
template<typename T>
T ListStack<T>::Peek()
{
	T data;
	Node<T> *ndata;
	if (m_size == 0)
	{
		throw Exception("Nothing in stack");
	}
	else
	{
		ndata = m_data.GetTail();
		data = ndata->GetData();
	}
	return data;
}

/**********************************************************************
* Purpose: returns the size of the stack
*
* Precondition:
* function is called
*
* Postcondition:
* returns m_size
*
************************************************************************/
template<typename T>
int ListStack<T>::Size()
{
	return m_size;
}

/**********************************************************************
* Purpose: returns true if the stack is empty, false if it is not
*
* Precondition:
* function is called
*
* Postcondition:
* returns true if m_size is 0, false otherwise
*
************************************************************************/
template<typename T>
bool ListStack<T>::IsEmpty()
{
	return m_size == 0 ? true : false;
}

#endif
