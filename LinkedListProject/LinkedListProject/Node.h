#pragma once
template <typename T>
class List;

template <typename T>
class Node
{
	friend class List<T>;
private:
	Node(T data);
	~Node();
	void setNext(Node * next);
	Node * getNext();
	const T & getData();
	T m_data;
	Node<T> * m_next;
};

template <typename T>
Node<T>::Node(T data) : m_data(data)
{

}

template<typename T>
Node<T>::~Node()
{

}

template<typename T>
void Node<T>::setNext(Node * next)
{
	m_next = next;
}

template<typename T>
Node<T> * Node<T>::getNext()
{
	return m_next;
}

template<typename T>
const T & Node<T>::getData()
{
	return m_data;
}

