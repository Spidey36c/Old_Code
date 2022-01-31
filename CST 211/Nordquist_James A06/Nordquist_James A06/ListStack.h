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

template<typename T>
ListStack<T>::ListStack(): m_size(0)
{
}

template<typename T>
ListStack<T>::ListStack(const ListStack & copy) : m_data(copy.m_data), m_size(copy.m_size)
{
}

template<typename T>
ListStack<T>::~ListStack()
{
	m_size = 0;
	m_data.Purge();
}

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

template<typename T>
void ListStack<T>::Push(T data)
{
	m_data.Append(data);
	m_size++;
}

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

template<typename T>
int ListStack<T>::Size()
{
	return m_size;
}

template<typename T>
bool ListStack<T>::IsEmpty()
{
	return m_size == 0 ? true : false;
}

#endif
