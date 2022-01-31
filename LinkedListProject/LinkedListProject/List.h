#pragma once
#include "Node.h"

template <typename T>
class List
{
public:
	List();
	List(const List &obj);
	~List();
	List & operator =(const List & rhs);
	void prepend(T data);
	void append(T data);
	void insertOrdered(T data);
	void purge();
	void display();
private:
	Node<T> *m_head;
};

template<typename T>
List<T>::List(): m_head(nullptr)
{

}

template<typename T>
List<T>::List(const List &obj)
{
	if (obj.m_head != nullptr)
	{
		Node<T> * travel = obj.m_head;
		Node<T> * new_travel = m_head;

		m_head = new Node<T>(travel->m_data);
		new_travel = m_head;
		travel = travel->m_next;

		while (travel != nullptr)
		{
			new_travel->m_next = (new Node<T>(travel->m_data));
			travel = travel->m_next;
			new_travel = new_travel->m_next;
		}
	}
}

template<typename T>
List<T>::~List()
{
	purge();
}

template<typename T>
List<T> & List<T>::operator=(const List & rhs)
{
	if (this != &rhs)
	{
		purge();
		if (rhs.m_head != nullptr)
		{
			Node<T> * travel = rhs.m_head;
			Node<T> * new_travel = m_head;

			m_head = new Node<T>(travel->m_data);
			new_travel = m_head;
			travel = travel->m_next;

			while (travel != nullptr)
			{
				new_travel->m_next = (new Node<T>(travel->m_data));
				travel = travel->m_next;
				new_travel = new_travel->m_next;
			}
		}
	}
	return *this;
}

template<typename T>
void List<T>::prepend(T data)
{
	Node<T> * nn = new Node<T>(data);

	nn->m_next = m_head;
	m_head = nn;
}

template<typename T>
void List<T>::append(T data)
{
	Node<T> * nn = new Node<T>(data);

	if (m_head == nullptr)
	{
		m_head = nn;
	}
	else
	{
		Node<T> * travel = m_head;
		while (travel->m_next != nullptr)
		{
			travel = travel->m_next;
		}
		travel->m_next = nn;
	}
}

template<typename T>
void List<T>::insertOrdered(T data)
{
	Node<T> * nn = new Node<T>(data);

	if ((m_head == nullptr) || (m_head->m_data < nn->m_data))
	{
		nn->m_next = m_head;
		m_head = nn;
	}
	else
	{
		Node<T> * travel = m_head;
		Node<T> * trail = nullptr;
		while ((travel != nullptr) && (nn->m_data < travel->m_data))
		{
			trail = travel;
			travel = travel->m_next;
		}
		trail->m_next = nn;
		nn->m_next = travel;
	}
}

template<typename T>
void List<T>::purge()
{
	Node<T> * trail = m_head;

	while (m_head != nullptr)
	{
		m_head = m_head->getNext();
		delete trail;
		trail = m_head;
	}
}

template<typename T>
void List<T>::display()
{
	Node<T> *travel = m_head;
	while (travel != nullptr)
	{
		cout << travel->m_data << endl;
		travel = travel->m_next;
	}
}
