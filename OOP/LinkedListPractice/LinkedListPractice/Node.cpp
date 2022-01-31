#include <iostream>
#include "Node.h"
#include "person.h"
using std::cout;
using std::endl;

Node::Node(person data): m_data(data), m_next(nullptr)
{
	cout << "Node 1 arg ctor..." << endl;
}


Node::~Node()
{
	cout << "Node dtor called" << endl;
}

void Node::setNext(Node * next)
{
	m_next = next;
}

Node * Node::getNext()
{
	return m_next;
}

const person & Node::getData()
{
	return m_data;
}
