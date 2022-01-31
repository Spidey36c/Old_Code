/********************************************************************************************
* Author: James Nordquist
* Filename : Stack.h
* Date Created : 2/3/19
* Modifications Made :
*********************************************************************************************** /
/************************************************************************
* Class:Stack
*
* Purpose: This class is a stack using an array to hold its data
* Manager functions:
* Stack ()
*	data is set to 0
* Stack(int size)
*	the stacks max size is set to size
* Stack (const Stack & copy)
*	Copy Ctor
* operator = (const Stack & copy)
*	op =
* ~Stack()
*	data is set to default or zero
*
* Methods:
* void Push(T data);
*	places data at the end of the array
* T Pop();
*	removes the data at the end of the array and returns the data
* T Peek();
*	returns the data at the end of the array
* int Size();
*	returns the size of the array
* bool IsEmpty();
*	returns true if the stack is empty, otherwise false
* bool IsFull();
*	returns true if the stack is full, otherwise false
* void SetSize(int size);
*	sets the maxsize of the stack
*************************************************************************/
#ifndef STACK_H
#define STACK_H
#include "Array.h"
#include "Exception.h"

template<typename T>
class Stack
{
public:
	Stack();
	Stack(int size);
	Stack(const Stack & copy);
	~Stack();
	Stack & operator =(const Stack & rhs);
	void Push(T data);
	T Pop();
	T Peek();
	int Size();
	bool IsEmpty();
	bool IsFull();
	void SetSize(int size);
private:
	Array<T> m_data;
	int m_size;
	int m_maxsize;
};

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* Object is created
*
* Postcondition:
* Object is instantiated with default values
*
************************************************************************/
template<typename T>
Stack<T>::Stack(): m_data(0), m_size(0), m_maxsize(0)
{
}

/**********************************************************************
* Purpose: one arg ctor
*
* Precondition:
* Object is created with an argument
* size - maximum size for the stack
*
* Postcondition:
* Object is instantiated
*
************************************************************************/
template<typename T>
Stack<T>::Stack(int size): m_data(size), m_size(0), m_maxsize(size)
{
}

/**********************************************************************
* Purpose: copy ctor
*
* Precondition:
* Object is created with another existing object
*
* Postcondition:
* Object is instantiated using the existing objects data
*
************************************************************************/
template<typename T>
Stack<T>::Stack(const Stack & copy):m_data(copy.m_data), m_size(copy.m_size), m_maxsize(copy.m_maxsize)
{
}

/**********************************************************************
* Purpose: dtpr
*
* Precondition:
* Object is deleted or goes out of scope
*
* Postcondition:
* Objects data is set to default values
*
************************************************************************/
template<typename T>
Stack<T>::~Stack()
{
	m_data.SetLength(0);
	m_size = 0;
	m_maxsize = 0;
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
Stack<T> & Stack<T>::operator=(const Stack & rhs)
{
	if (this != &rhs)
	{
		m_data = rhs.m_data;
		m_size = rhs.m_size;
		m_maxsize = rhs.m_maxsize;
	}
	return *this;
}

/**********************************************************************
* Purpose: places new data at the top of the stack
*
* Precondition:
* data - data to be placed in stack
*
* Postcondition:
* data is placed at the top of the stack
*
************************************************************************/
template<typename T>
void Stack<T>::Push(T data)
{
	if (m_size + 1 > m_maxsize)
	{
		throw Exception("Stack Overflow");
	}
	else
	{
		m_data[m_size] = data;
		m_size++;
	}
}

/**********************************************************************
* Purpose: gets the data at the top of the stack then removes the data from the top of the stack
*		   then returns the data
*
* Precondition:
* function is called
*
* Postcondition:
* data is found at top of the stack, data is then removed from the top of the stack
* then the data is returned. If stack is empty, throws an expection
*
************************************************************************/
template<typename T>
T Stack<T>::Pop()
{
	T data;
	if (m_size - 1 < 0)
	{
		throw Exception("Stack Underflow");
	}
	else
	{
		data = m_data[m_size - 1];
		m_size--;
		m_data.SetLength(m_size);
		m_data.SetLength(m_maxsize); //Remove the data
	}
	return data;
}

/**********************************************************************
* Purpose: returns the data at the top of the stack
*
* Precondition:
* function is called
*
* Postcondition:
* data is found at the top of the stack, then removes it, if stack is empty
* throws an exception
*
************************************************************************/
template<typename T>
T Stack<T>::Peek()
{
	T data;
	if (m_size == 0)
	{
		throw Exception("Nothing in stack");
	}
	else
	{
		data = m_data[m_size - 1];
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
int Stack<T>::Size()
{
	return m_size;
}

/**********************************************************************
* Purpose: returns true if the stack is empty, false otherwise
*
* Precondition:
* function is called
*
* Postcondition:
* returns true if m_size is 0, false otherwise
*
************************************************************************/
template<typename T>
bool Stack<T>::IsEmpty()
{
	return m_size == 0 ? true : false;
}

/**********************************************************************
* Purpose: returns true if the stack is full, false otherwise
*
* Precondition:
* function is called
*
* Postcondition:
* returns true if m_size is = m_maxsize, false otherwise
*
************************************************************************/
template<typename T>
bool Stack<T>::IsFull()
{
	return m_size == m_maxsize ? true : false;
}

/**********************************************************************
* Purpose: setter for the maxsize of the stack
*
* Precondition:
* size - desired size of stack
*
* Postcondition:
* max size of stack is reduced, and if the current size is greater than 
* the max size, current size is reduced to match max size
*
************************************************************************/
template<typename T>
void Stack<T>::SetSize(int size)
{
	m_maxsize = size;
	if (m_size > m_maxsize)
	{
		m_size = m_maxsize;
	}
	m_data.SetLength(m_maxsize);
}
#endif


