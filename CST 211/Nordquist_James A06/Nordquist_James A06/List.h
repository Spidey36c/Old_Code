/************************************
* Author: James Nordquist
* Filename: List.h
* Date Created: 1/9/19
* Modifications: 
*
*************************************/
#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include "Exception.H"
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class List
{
public:
	List();
	List(const List & copy);
	~List();
	List & operator =(const List & rhs);
	bool IsEmpty();
	const T & First();
	const T & Last();
	void Prepend(T data);
	void Append(T data);
	void Purge();
	void Extract(T data);
	void InsertAfter(T olddata, T newdata);
	void InsertBefore(T olddata, T newdata);
	Node<T> * GetHead() const;
	Node<T> * GetTail() const;
	void printForwards();
	void printBackwards();
private:
	Node<T> * m_head; 
	Node<T>* m_tail; //don't think we would need a setter for head and tail
};

template<typename T>
List<T>::List() : m_head(nullptr), m_tail(nullptr)
{

}

template<typename T>
List<T>::List(const List & copy)
{
	if (copy.m_head != nullptr)
	{
		Node<T> * travel = copy.m_head;
		Node<T> * new_travel = m_head;
		Node<T> * new_trail;

		m_head = new Node<T>(travel->m_data);
		new_travel = m_head;
		travel = travel->m_next;
		new_trail = new_travel;
		
		while (travel != nullptr)
		{
			new_travel->m_next = (new Node<T>(travel->m_data));

			travel = travel->m_next;
			new_travel = new_travel->m_next;
			new_travel->m_prev = new_trail; 
			new_trail = new_trail->m_next;	
		}
		m_tail = new_travel;
	}
}

template<typename T>
List<T>::~List()
{
	Purge(); //tail and head should both be nullptr from purge
}

template<typename T>
List<T> & List<T>::operator=(const List & rhs)
{
	if (this != &rhs)
	{
		Purge();
		if (rhs.m_head != nullptr)
		{
			Node<T> * travel = rhs.m_head;
			Node<T> * new_travel = m_head;
			Node<T> * new_trail;

			m_head = new Node<T>(travel->m_data);
			new_travel = m_head;
			travel = travel->m_next;
			new_trail = new_travel;

			while (travel != nullptr)
			{
				new_travel->m_next = (new Node<T>(travel->m_data));
				travel = travel->m_next;
				new_travel = new_travel->m_next;
				new_travel->m_prev = new_trail;
				new_trail = new_trail->m_next;
			}
			m_tail = new_travel;
		}
	}

	return *this;
}

template<typename T>
bool List<T>::IsEmpty()
{
	return m_head == nullptr ? true : false;
}

template<typename T>
const T & List<T>::First()
{
	return m_head->m_data;
}

template<typename T>
inline const T & List<T>::Last()
{
	return m_tail->m_data;
}

template<typename T>
void List<T>::Prepend(T data)
{
	Node<T> * nn = new Node<T>(data);
	if (IsEmpty() == true)
	{
		m_head = nn;
		m_tail = m_head; //only 1 element in array now
	}
	else if(m_head->m_next == nullptr) //only 1 element in array
	{
		nn->m_next = m_head;
		m_head->m_prev = nn;
		m_head = nn;
		m_tail = m_head->m_next; //2 elements in array now
	}
	else //2 or more elements in list
	{
		nn->m_next = m_head;
		m_head->m_prev = nn;
		m_head = nn;
	}
}

template<typename T>
void List<T>::Append(T data)
{
	Node<T> * nn = new Node<T>(data);
	if (IsEmpty() == true)
	{
		m_head = nn;
		m_tail = m_head;
	}
	else //The list has at least 1 element
	{
		m_tail->m_next = nn;
		nn->m_prev = m_tail;
		m_tail = nn;
	}
}

template<typename T>
void List<T>::Purge()
{
	Node<T> * trail = m_head;

	while (m_head != nullptr)
	{
		m_head = m_head->m_next;
		delete trail;
		trail = m_head;
	}
	m_tail = m_head;
}

template<typename T>
void List<T>::Extract(T data)
{
	bool found = false;
	Node<T> * travel = m_head; //is there a faster way to go through the list without iterating?
	Node<T> * trail;
	
	while (travel != nullptr && found == false)
	{
		if (travel->m_data == data)
		{
			found = true;
		}
		trail = travel;
		travel = travel->m_next;
	}

	if (found == false)
	{
		throw Exception("Node not found.");
	}
	else
	{
		if (trail != m_head && trail != m_tail) //if we are not at the end or beginning of list
		{
			Node<T> * temp;
			temp = trail->m_prev;
			temp->m_next = travel;
			travel->m_prev = temp;
			delete trail;
		}
		else if(trail == m_head)
		{
			m_head = travel;
			m_head->m_prev = nullptr;
			delete trail;
		}
		else //we are at the end of the list
		{
			Node<T> * temp;
			temp = trail->m_prev;
			m_tail = temp;
			m_tail->m_next = nullptr;
			delete trail;
		}
	}

}

template<typename T>
void List<T>::InsertAfter(T newdata, T olddata)
{
	bool found = false;
	Node<T> * travel = m_head;
	Node<T> * trail;

	while (travel != nullptr && found == false)
	{
		if (travel->m_data == olddata)
		{
			found = true;
		}
		trail = travel;
		travel = travel->m_next;
	}

	if (found == false)
	{
		throw Exception("Node does not exist.");
	}
	else
	{
		Node<T> * nn = new Node<T>(newdata);
		if (trail == m_tail) //could just use Append, but I think it might be smarter to not
		{
			trail->m_next = nn;
			nn->m_prev = m_tail;
			m_tail = nn;
		}
		else
		{
			trail->m_next = nn;
			travel->m_prev = nn;
			nn->m_next = travel;
			nn->m_prev = trail;
		}
	}
}

template<typename T>
void List<T>::InsertBefore(T newdata, T olddata)
{
	bool found = false;
	Node<T> * travel = m_head;
	Node<T> * trail;

	while (travel != nullptr && found == false)
	{
		if (travel->m_data == olddata)
		{
			found = true;
		}
		trail = travel;
		travel = travel->m_next;
	}

	if (found == false)
	{
		throw Exception("Node does not exist.");
	}
	else
	{
		Node<T> * nn = new Node<T>(newdata);
		if (trail == m_head) //could use prepend but don't want to
		{
			trail->m_prev = nn;
			nn->m_next = trail;
			m_head = nn;
		}
		else
		{
			Node<T> * temp;
			temp = trail->m_prev;
			temp->m_next = nn;
			trail->m_prev = nn;
			nn->m_prev = temp;
			nn->m_next = trail;
		}
	}

}


template<typename T>
Node<T> * List<T>::GetHead() const
{
	return m_head;
}

template<typename T>
Node<T> * List<T>::GetTail() const
{
	return m_tail;
}

template<typename T>
void List<T>::printForwards()
{
	Node<T> * travel = m_head;
	while (travel != nullptr)
	{
		cout << travel->m_data << endl;
		travel = travel->m_next;
	}
}

template<typename T>
void List<T>::printBackwards()
{
	Node<T> * travel = m_tail;
	while (travel != nulltpr)
	{
		cout << travel->m_data << endl;
		travel = travel->m_prev;
	}
}


#endif

