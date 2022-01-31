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

template<typename T>
Stack<T>::Stack(): m_data(0), m_size(0), m_maxsize(0)
{
}

template<typename T>
Stack<T>::Stack(int size): m_data(size), m_size(0), m_maxsize(size)
{
}

template<typename T>
Stack<T>::Stack(const Stack & copy):m_data(copy.m_data), m_size(copy.m_size), m_maxsize(copy.m_maxsize)
{
}

template<typename T>
Stack<T>::~Stack()
{
	m_data.SetLength(0);
	m_size = 0;
	m_maxsize = 0;
}

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

template<typename T>
int Stack<T>::Size()
{
	return m_size;
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	return m_size == 0 ? true : false;
}

template<typename T>
bool Stack<T>::IsFull()
{
	return m_size == m_maxsize ? true : false;
}

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


