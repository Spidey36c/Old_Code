#pragma once
/*************************************************************
* Author:		James Nordquist
* Filename:		Node.h
* Date Created:	6/3/18
* Modifications:
**************************************************************/
#include "Song.h"

/************************************************************************
* Class: Array
*
* Purpose: This class is for nodes of the list
*
* Manager functions:
* 	Node(Song song);
*		assigns m_next to nullptr and mySong to song
*	void setNext(Node * next)
*		makes m_next = next
*	Node *GetNext()
*		returns m_next
*	const Song & getData()
*		returns mySong as a const ref
*
* Methods:
*	mySong
*		song obj for data
*	m_next
*		the next node in a list
*************************************************************************/
class Node
{
public:
	Node(Song song);
	~Node();
	void setNext(Node * next);
	Node *GetNext();
	const Song & getData();
private:
	Song mySong;
	Node * m_next;
};

