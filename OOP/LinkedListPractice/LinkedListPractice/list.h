#pragma once
#include "Node.h"

class list
{
public:
	list();
	list(const list &obj);
	~list();
	list & operator =(const list & rhs);
	void prepend(person data);
	void append(person data);
	void insertOrdered(person data);
	void purge();
private:
	Node *m_head;
};