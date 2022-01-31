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
	T getSpecificData(int selection);
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
	T compare1;
	T compare2;
	Node<T> * nn = new Node<T>(data);
	compare1 = (nn->m_data);
	if (m_head != nullptr)
	{
		compare2 = (m_head->m_data);
	}
	if ((m_head == nullptr) || (*compare1 < *compare2))
	{
		nn->m_next = m_head;
		m_head = nn;
	}
	else
	{
		Node<T> * travel = m_head->m_next;
		Node<T> * trail = m_head;
		if (travel != nullptr)
		{
			compare2 = travel->m_data;
		}
		while ((travel != nullptr) && (*compare2 < *compare1))
		{
			trail = travel;
			travel = travel->m_next;
			if (travel != nullptr)
			{
				compare2 = travel->m_data;
			}
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
		delete trail->m_data;
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

template<typename T>
T List<T>::getSpecificData(int selection)
{
	Node<T> *travel = m_head;
	int counter = 1;
	while (travel != nullptr && counter != selection)
	{
		travel = travel->m_next;
		counter++;
	}

	return travel->m_data;
}
