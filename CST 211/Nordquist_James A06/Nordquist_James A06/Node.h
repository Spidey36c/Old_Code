/************************************
* Author: James Nordquist
* Filename: Node.h
* Date Created: 1/9/19
* Modifications: 1/9/19 - Friended List class
*
*************************************/
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

template<typename T>
Node<T>::Node(): m_data(0), m_next(nullptr), m_prev(nullptr)
{

}

template<typename T>
Node<T>::Node(T data): m_data(data), m_next(nullptr), m_prev(nullptr)
{

}

template<typename T>
Node<T>::~Node()
{

}

template<typename T>
Node<T>::Node(const Node& copy): m_data(copy.m_data), m_next(nullptr), m_prev(nullptr) //setting the next and previous pointers to the same as copies is not necessary
{

}

template<typename T>
Node<T> & Node<T>::operator=(const Node & rhs)
{
	if (*this != &rhs)
	{
		m_data = rhs.m_data; //still don't think copying the next and prev pointers is necessary, as it could lead to more issues.
	}
	return *this;
}

template<typename T>
Node<T> * Node<T>::GetNext() const
{
	return m_next;
}

template<typename T>
void Node<T>::SetNext(Node * next)
{
	m_next = next;
}

template<typename T>
Node<T> * Node<T>::GetPrevious() const
{
	return m_prev;
}

template<typename T>
void Node<T>::SetPrevious(Node * prev)
{
	m_prev = prev;
}

template<typename T>
inline T Node<T>::GetData()
{
	return m_data;
}
#endif