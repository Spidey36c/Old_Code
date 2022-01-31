/************************************
* Author: James Nordquist
* Filename: Node.h
* Date Created: 1/9/19
* Modifications: 1/9/19 - Friended List class
*
*************************************/
/************************************************************************
* Class: Node
*
* Purpose: This class creates a node to be used in a linked list
* Manager functions:
* Node ()
*	m_next and m_prev are set to nullptr
* Node (const Node & copy)
*	Copy Ctor
* operator = (const Node & copy)
*	op =
* ~Node()
*	data is set to default or zero
*
* Methods:
* Node * GetNext() const; 
*	getter for m_next
* void SetNext(Node * next);
*	setter m_next
* Node * GetPrevious() const; 
*	getter for m_prev
* void SetPrevious(Node * prev);
*	setter for m_prev
* T GetData();
*	getter for m_data
*************************************************************************/
#ifndef NODE_H
#define NODE_H
template<typename T>
class List;

template<typename T>
class Node
{
	friend class List<T>;
public:
	Node();
	Node(T data);
	~Node();
	Node(const Node& copy);
	Node & operator =(const Node& rhs);
	Node * GetNext() const; //redundant from friending list, but doesn't hurt to be here.
	void SetNext(Node * next); //same as getNext.
	Node * GetPrevious() const; //set and get Prev are both redundant from friending list, but having these wont hurt.
	void SetPrevious(Node * prev);
	T GetData(); //no need for having a setter as the 1 arg ctor can be considered the "setter" and we don't need to change the data after construction.
private:
	T m_data;
	Node<T>* m_next;
	Node<T>* m_prev;
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
Node<T>::Node(): m_data(0), m_next(nullptr), m_prev(nullptr)
{

}

/**********************************************************************
* Purpose: one arg ctor
*
* Precondition:
* Object is created with a argument
* data - data for the node to hold
*
* Postcondition:
* Object is instantiated with correct values
*
************************************************************************/
template<typename T>
Node<T>::Node(T data): m_data(data), m_next(nullptr), m_prev(nullptr)
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
Node<T>::~Node()
{

}

/**********************************************************************
* Purpose: copy ctor
*
* Precondition:
* Object is created with an existing object
*
* Postcondition:
* Object is instantiated with the existing objects data
*
************************************************************************/
template<typename T>
Node<T>::Node(const Node& copy): m_data(copy.m_data), m_next(nullptr), m_prev(nullptr) //setting the next and previous pointers to the same as copies is not necessary
{

}

/**********************************************************************
* Purpose: op =
*
* Precondition:
* Object is set to equal another object
*
* Postcondition:
* Object's data is set to the same as the other objects data
*
************************************************************************/
template<typename T>
Node<T> & Node<T>::operator=(const Node & rhs)
{
	if (*this != &rhs)
	{
		m_data = rhs.m_data; //still don't think copying the next and prev pointers is necessary, as it could lead to more issues.
	}
	return *this;
}

/**********************************************************************
* Purpose: getter for m_next
*
* Precondition:
* function is called
*
* Postcondition:
* m_next is returned
*
************************************************************************/
template<typename T>
Node<T> * Node<T>::GetNext() const
{
	return m_next;
}

/**********************************************************************
* Purpose: setter for m_next
*
* Precondition:
* next - node that is the next node in the list
*
* Postcondition:
* m_next is set to next
*
************************************************************************/
template<typename T>
void Node<T>::SetNext(Node * next)
{
	m_next = next;
}

/**********************************************************************
* Purpose: getter for m_prev
*
* Precondition:
* function is called
*
* Postcondition:
* m_prev is returned
*
************************************************************************/
template<typename T>
Node<T> * Node<T>::GetPrevious() const
{
	return m_prev;
}

/**********************************************************************
* Purpose: setter for m_prev
*
* Precondition:
* prev - node that is the previous node in the list
*
* Postcondition:
* m_prev is set to prev
*
************************************************************************/
template<typename T>
void Node<T>::SetPrevious(Node * prev)
{
	m_prev = prev;
}

/**********************************************************************
* Purpose: getter for m_data
*
* Precondition:
* function is called
*
* Postcondition:
* m_data is returned
*
************************************************************************/
template<typename T>
inline T Node<T>::GetData()
{
	return m_data;
}
#endif