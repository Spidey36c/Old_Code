#pragma once
/*************************************************************
* Author:		James Nordquist
* Filename:		List.h
* Date Created:	6/3/18
* Modifications:
**************************************************************/
#include <string>
using std::string;
#include "Node.h"
#include "Song.h"

/************************************************************************
* Class: Array
*
* Purpose: This class creates a linked list
*
* Manager functions:
*	List()
*		sets head to nullptr
*	List(const List & obj)
*		copys the contents of one linked list into the end another linked list
*	void prepend(Song song)
*		places a new node before m_head and sets the node to m_head
*	void append(Song song)
*		places a new node at the end of the end of a linked list unless m_head is nullptr
*		then m_head = the new node
*	void insertOrdered(Song song)
*		inserts a new node into the linked list based on a key, in this case the name of the song 
*	void deleteNode(string name)
*		deletes the first node that has the same song name as name
*	void searchSongName(string name)
*		finds the first node that has the same song name as name
*	void searchArtistName(string name)
*		finds the first node that has the same artist name as name
*	void saveToFile(const char * filename)
*		places the contents of the linked list into a specific file
*	void purge()
*		deletes the linked list to avoid memory leaks, is called in dtor and op=
*	void display()
*		outputs the contents of the linked list to the console
* Methods:
*	m_song_name
*		string obj that holds a song name
*	m_next
*		string obj that holds a song name
*************************************************************************/
class List
{
public:
	List();
	List(const List & obj);
	~List();
	List & operator =(const List & rhs);
	void prepend(Song song);
	void append(Song song);
	void insertOrdered(Song song);
	void deleteNode(string name);
	void searchSongName(string name);
	void searchArtistName(string name);
	void saveToFile(const char * filename);
	void purge();
	void display();
private:
	Node * m_head;
};

