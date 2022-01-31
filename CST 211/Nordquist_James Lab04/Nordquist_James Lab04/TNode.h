/*************************************************************
* Author: James Nordquist
* Filename: TNode.h
* Date Created: 2/16/19
* Modifications: 2/21/19 - Made balance enum for AVL tree
**************************************************************/
/************************************************************************
* Class: TNode
*
* Purpose: This class is a node that holds data
* Manager functions:
* TNode();
*	default ctor, sets m_bf to EH and left and right to nullptr
* TNode(T data);
*	sets m_bf for eh m_data to data and left and right to nullptr
* TNode(const TNode & copy);
*	copy ctor
* ~TNode();
*	dtor sets data back to default
* TNode & operator =(const TNode & rhs);
*	op =
*
* Methods:
* TNode *& GetLeft();
*	returns pointer reference to m_left
* void SetLeft(TNode *left);
*	sets m_left to left
* TNode *& GetRight();
*	returns pointer reference to m_right
* void SetRight(TNode *right);
*	sets m_right to right
* T & GetData();
*	returns a reference to data
* Balance & GetBalance();
*	returns balance
*************************************************************************/
#ifndef TNODE_H
#define TNODE_H

enum Balance
{
	RH = -1, EH = 0, LH = 1
};

template<typename T>
class TNode
{
public:
	TNode();
	TNode(T data);
	TNode(const TNode & copy);
	~TNode();
	TNode & operator =(const TNode & rhs);
	TNode *& GetLeft();
	void SetLeft(TNode *left);
	TNode *& GetRight();
	void SetRight(TNode *right);
	T & GetData();
	Balance & GetBalance();
private:
	Balance m_bf;
	T m_data;
	TNode<T> * m_left;
	TNode<T> * m_right;
};

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* object is created
*
* Postcondition:
* object is instantiated using default values
*
************************************************************************/
template<typename T>
TNode<T>::TNode(): m_left(nullptr), m_right(nullptr), m_data(0), m_bf(EH)
{
}

/**********************************************************************
* Purpose: one arg ctor
*
* Precondition:
* data - desired data for node to hold
*	
* Postcondition:
* object is instantiated with m_data being set to data
*
************************************************************************/
template<typename T>
TNode<T>::TNode(T data): m_data(data), m_left(nullptr), m_right(nullptr), m_bf(EH)
{
}

/**********************************************************************
* Purpose: copy
*
* Precondition:
* object is created with copy
*
* Postcondition:
* objects data is set to copys data but not its left and right
*
************************************************************************/
template<typename T>
TNode<T>::TNode(const TNode & copy): m_data(copy.m_data), m_left(nullptr), m_right(nullptr), m_bf(EH)
{
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* object is deleted or goes out of scope
*
* Postcondition:
* object is set back to default values
*
************************************************************************/
template<typename T>
TNode<T>::~TNode()
{
	m_left = nullptr;
	m_right = nullptr;
	m_data = 0;
	m_bf = EH;
}

/**********************************************************************
* Purpose: op =
*
* Precondition:
* object is set equal to rhs
*
* Postcondition:
* objects data is the same as rhs but not the other objects pointers
*
************************************************************************/
template<typename T>
TNode<T> & TNode<T>::operator=(const TNode & rhs)
{
	if (*this != rhs)
	{
		m_data = rhs.m_data;
		m_bf = EH;
	}
	return *this;
}

/**********************************************************************
* Purpose: getter for left
*
* Precondition:
* function is called
*
* Postcondition:
* m_left is returned with a pointer reference
*
************************************************************************/
template<typename T>
TNode<T> *& TNode<T>::GetLeft()
{
	return m_left;
}

/**********************************************************************
* Purpose: setter for left
*
* Precondition:
* left - pointer to another node
*
* Postcondition:
* m_left is set to left
*
************************************************************************/
template<typename T>
void TNode<T>::SetLeft(TNode * left)
{
	m_left = left;
}

/**********************************************************************
* Purpose: getter for right
*
* Precondition:
* function is called
*
* Postcondition:
* m_right is returned as a pointer reference
*
************************************************************************/
template<typename T>
TNode<T> *& TNode<T>::GetRight()
{
	return m_right;
}

/**********************************************************************
* Purpose: setter for right
*
* Precondition:
* right - pointer to another node
*
* Postcondition:
* m_right is set to right
*
************************************************************************/
template<typename T>
void TNode<T>::SetRight(TNode * right)
{
	m_right = right;
}

/**********************************************************************
* Purpose: getter for data
*
* Precondition:
* function is called
*
* Postcondition:
* m_data is returned as reference so that it can change
*
************************************************************************/
template<typename T>
T & TNode<T>::GetData()
{
	return m_data;
}

/**********************************************************************
* Purpose: getter for balance
*
* Precondition:
* function is called
*
* Postcondition:
* m_bf is returned as reference so that it can be changed
*
************************************************************************/
template<typename T>
Balance &TNode<T>::GetBalance()
{
	return m_bf;
}

#endif

