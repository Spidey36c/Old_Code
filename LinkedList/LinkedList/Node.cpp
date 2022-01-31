/*************************************************************
* Author:		James Nordquist
* Filename:		Node.cpp
* Date Created:	6/3/18
* Modifications:	
**************************************************************/
#include <iostream>
using std::cout;
using std::endl;
#include "Node.h"
#include "Song.h"

Node::Node(Song song) :m_next(nullptr), mySong(song)
{

}


Node::~Node()
{

}

void Node::setNext(Node * next)
{
	m_next = next;
}

Node * Node::GetNext()
{
	return m_next;
}

const Song & Node::getData()
{
	return mySong;
}
