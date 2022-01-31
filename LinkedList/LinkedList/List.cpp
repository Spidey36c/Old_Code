/*************************************************************
* Author:		James Nordquist
* Filename:		List.cpp
* Date Created:	6/3/18
* Modifications:
**************************************************************/
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ofstream;
#include "List.h"
#include "Song.h"


List::List():m_head(nullptr)
{

}

List::List(const List & obj)
{

	if (obj.m_head != nullptr)
	{
		Node * travel = obj.m_head;
		while (travel != nullptr)
		{
			append(travel->getData());
			travel = travel->GetNext();
		}
	}
}

List::~List()
{
	purge();
}

List & List::operator=(const List & rhs)
{
	if (this != &rhs)
	{
		purge();

		if (rhs.m_head != nullptr)
		{
			Node * travel = rhs.m_head;
			while (travel != nullptr)
			{
				append(travel->getData());
				travel = travel->GetNext();
			}
		}
	}
	return *this;
}

void List::prepend(Song song)
{
	Node * nn = new Node(song);

	nn->setNext(m_head);
	m_head = nn;
}

void List::append(Song song)
{
	Node * nn = new Node(song);
	if (m_head == nullptr)
	{
		m_head = nn;
	}
	else
	{
		Node * travel = m_head;
		while (travel->GetNext() != nullptr)
		{
			travel = travel->GetNext();
		}
		travel->setNext(nn);
	}
}

void List::insertOrdered(Song song)
{
	Node * nn = new Node(song);

	if ((m_head == nullptr) || (nn->getData() < m_head->getData()))
	{
		nn->setNext(m_head);
		m_head = nn;
	}
	else
	{
		Node * travel = m_head;
		Node * trail = nullptr;
		while ((travel != nullptr) && (travel->getData() < nn->getData()))
		{
			trail = travel;
			travel = travel->GetNext();
		}
		trail->setNext(nn);
		nn->setNext(travel);
	}
}

void List::deleteNode(string name)
{
	Node * travel = m_head;
	Node * trail = nullptr;
	if (m_head == nullptr)
	{
		cout << "Can't delete from an empty list" << endl;
	}
	else if (m_head->getData() == name)
	{
		trail = m_head;
		m_head = m_head->GetNext();
		delete trail;
	}
	else
	{
		while ((travel != nullptr) && (travel->getData() != name))
		{
			trail = travel;
			travel = travel->GetNext();
		}
		
		if (travel != nullptr)
		{
			trail->setNext(travel->GetNext());
			delete travel;
		}
		else
		{
			cout << name << " not found in list" << endl;
		}
	}
}

void List::searchSongName(string name)
{
	Node * travel = m_head;
	while (travel != nullptr && travel->getData().getSongName() != name)
	{
		travel = travel->GetNext();
	}

	if (travel == nullptr)
	{
		cout << name << " was not found in the list" << endl;
	}
	else
	{
		cout << name << " was found and it is by " << travel->getData().getArtistName() << endl;
	}
}

void List::searchArtistName(string name)
{
	Node * travel = m_head;
	bool foundAny = false;
	while (travel != nullptr)
	{
		if (travel->getData().getArtistName() == name)
		{
			if (foundAny == false)
			{
				foundAny = true;
			}
			cout << travel->getData().getSongName() << endl;
		}
		travel = travel->GetNext();
	}

	if (foundAny == false)
	{
		cout << name << " does not have any songs in the list" << endl;
	}
	else
	{
		cout << "Are songs made by " << name << endl;
	}
}

void List::saveToFile(const char * filename)
{
	Node * travel = m_head;
	ofstream fout;
	fout.open(filename);
	if (fout.is_open())
	{
		while (travel != nullptr)
		{
			fout << travel->getData().getSongName() << endl;
			fout << travel->getData().getArtistName() << endl;
			travel = travel->GetNext();
		}
		fout.close();
	}
	else
	{
		cout << "File could not be opened" << endl;
	}
}

void List::purge()
{
	Node * trail = m_head;

	while (m_head != nullptr)
	{
		m_head = m_head->GetNext();
		delete trail;
		trail = m_head;
	}
}

void List::display()
{
	Node * travel = m_head;

	while (travel != nullptr)
	{
		travel->getData().print();
		travel = travel->GetNext();
	}
}
