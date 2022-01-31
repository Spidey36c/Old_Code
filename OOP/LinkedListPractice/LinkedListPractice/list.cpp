#include <iostream>
#include "list.h"
using std::cout;
using std::endl;


list::list() : m_head(nullptr)
{
	cout << "list default ctor" << endl;
}

list::list(const list & obj):m_head(nullptr)
{
	if (obj.m_head != nullptr)
	{
		Node * travel = obj.m_head;
		Node * new_travel = m_head;

		m_head = new Node(travel->m_data);
		new_travel = m_head;
		travel = travel->m_next;

		while (travel != nullptr)
		{
			new_travel->m_next = (new Node(travel->m_data));
			travel = travel->m_next;
			new_travel = new_travel->m_next;
		}
	}
}


list::~list()
{
	cout << "list dtor" << endl;
	purge();
}

list & list::operator=(const list & rhs)
{
	// 1. check for self assignment
	if (this != &rhs)
	{
		// 2. purge left hand side
		purge();
		// 3. perform deep copy
		if (rhs.m_head != nullptr)
		{
			Node * travel = rhs.m_head;
			Node * new_travel = m_head;

			m_head = new Node(travel->m_data);
			new_travel = m_head;
			travel = travel->m_next;

			while (travel != nullptr)
			{
				new_travel->m_next = (new Node(travel->m_data));
				travel = travel->m_next;
				new_travel = new_travel->m_next;
			}
		}
	}
	// 4. return reference to self
	return *this;
}

void list::prepend(person data)
{
	Node * nn = new Node(data);

	nn->m_next = m_head;
	m_head = nn;
}

void list::append(person data)
{
	Node * nn = new Node(data);

	if (m_head == nullptr)
	{
		m_head = nn;
	}
	else
	{
		Node * travel = m_head;
		while (travel->m_next != nullptr)
		{
			travel = travel->m_next;
		}
		travel->m_next = nn;
	}
}

void list::insertOrdered(person data)
{
	Node * nn = new Node(data);

	if ((m_head == nullptr) || (nn->m_data < m_head->m_data))
	{
		nn->m_next =  m_head;
		m_head = nn;
	}
	else
	{
		Node * travel = m_head;
		Node * trail = nullptr;
		while ((travel != nullptr) && (travel->m_data < nn->m_data))
		{
			trail = travel;
			travel = travel->getNext();
		}
		trail->setNext(nn);
		nn->setNext(travel);
	}
}

void list::purge()
{
	Node * trail = m_head;

	while (m_head != nullptr)
	{
		m_head = m_head->getNext();
		delete trail;
		trail = m_head;
	}
}
