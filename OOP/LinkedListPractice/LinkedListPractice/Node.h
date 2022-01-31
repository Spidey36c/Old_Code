#pragma once
#include "person.h"

class list;

class Node
{
	friend class list;
private:
	Node(person data);
	~Node();
	void setNext(Node * next);
	Node * getNext();
	const person & getData();
	person m_data;
	Node * m_next;
};

