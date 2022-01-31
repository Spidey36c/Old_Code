/*************************************************************
* Author: James Nordquist
* Filename: Edge.h
* Date Created: 3/7/19
* Modifications: 3/11/19 - added SetWeight and GetWeight
**************************************************************/
#ifndef EDGE_H
#define EDGE_H
#include <iostream>

template<typename V, typename E>
class Vertice;

/************************************************************************
* Class: Edge
*
* Purpose: This class is a connection between two Vertice objects
*
* Manager functions:
* Edge();
*	default ctor
* Edge(E data);
*	one arg ctor
* Edge(const Edge & copy);
*	copy ctor
* ~Edge();
*	dtor
* Edge & operator =(const Edge & rhs);
*	op =
*
* Methods:
* bool operator ==(const Edge & rhs);
*	op== comparing m_data and rhs.m_data
* void SetDest(Vertice<V, E> *dest);
*	setter for m_dest
* Vertice<V, E> * GetDest();
*	getter for m_dest
* void SetData(E data);
*	setter for m_data
* E GetData();
*	getter for m_data
* void SetWeight(int weight);
*	setter for m_weight
* int GetWeight();
*	getter for m_weight
*************************************************************************/
template<typename V, typename E>
class Edge
{
public:
	Edge();
	Edge(E data);
	Edge(const Edge & copy);
	~Edge();
	Edge & operator =(const Edge & rhs);
	bool operator ==(const Edge & rhs);
	void SetDest(Vertice<V, E> *dest);
	Vertice<V, E> * GetDest();
	void SetData(E data);
	E GetData();
	void SetWeight(int weight);
	int GetWeight();
private:
	Vertice<V, E> * m_dest;
	E m_data;
	int m_weight; //not to be used here, just for dijkstra graph implentation later
};

/**********************************************************************
* Purpose: Default Ctor
*
* Precondition:
* Object is created
*
* Postcondition:
* Object is instantiated with default value
*
************************************************************************/
template<typename V, typename E>
Edge<V, E>::Edge(): m_weight(0)
{
}

/**********************************************************************
* Purpose: One arg ctor
*
* Precondition:
* data - data to set m_data
*
* Postcondition:
* Object is instantiated with assigned values
*
************************************************************************/
template<typename V, typename E>
Edge<V, E>::Edge(E data): m_weight(0), m_data(data)
{
}

/**********************************************************************
* Purpose: Copy ctor
*
* Precondition:
* Object is created with another object
*
* Postcondition:
* Object is instantiated with the other objects data
*
************************************************************************/
template<typename V, typename E>
Edge<V, E>::Edge(const Edge & copy): m_weight(copy.m_weight), m_data(copy.m_data), m_dest(copy.m_dest)
{
}

/**********************************************************************
* Purpose: Dtor
*
* Precondition:
* Object is deleted or goes out of scope
*
* Postcondition:
* Object is deleted and values go back to default
*
************************************************************************/
template<typename V, typename E>
Edge<V, E>::~Edge()
{
	m_dest = nullptr;
	m_weight = 0;
}

/**********************************************************************
* Purpose: op =
*
* Precondition:
* Object is set equal to rhs
*
* Postcondition:
* Object data is the same as rhs
*
************************************************************************/
template<typename V, typename E>
Edge<V,E> & Edge<V, E>::operator=(const Edge & rhs)
{
	if (this != &rhs)
	{
		m_dest = rhs.m_dest;
		m_data = rhs.m_data;
		m_weight = rhs.m_weight;
	}
	return *this;
}

/**********************************************************************
* Purpose: op==
*
* Precondition:
* compares data and rhs data
*
* Postcondition:
* returns true if they are the same, false otherwise
*
************************************************************************/
template<typename V, typename E>
bool Edge<V, E>::operator==(const Edge & rhs)
{
	return m_data == rhs.m_data ? true : false;
}

/**********************************************************************
* Purpose: Setter for dest
*
* Precondition:
* dest - desired data for dest
*
* Postcondition:
* m_dest is set to dest
*
************************************************************************/
template<typename V, typename E>
void Edge<V, E>::SetDest(Vertice<V, E> *dest)
{
	m_dest = dest;
}

/**********************************************************************
* Purpose: Getter for dest
*
* Precondition:
* function is called
*
* Postcondition:
* m_dest is returned
*
************************************************************************/
template<typename V, typename E>
Vertice<V, E> *Edge<V, E>::GetDest()
{
	return m_dest;
}

/**********************************************************************
* Purpose: Setter for data
*
* Precondition:
* data - desired data
*
* Postcondition:
* m_data is set to data
*
************************************************************************/
template<typename V, typename E>
void Edge<V, E>::SetData(E data)
{
	m_data = data;
}

/**********************************************************************
* Purpose: Getter for data
*
* Precondition:
* function is called
*
* Postcondition:
* m_data is returned
*
************************************************************************/
template<typename V, typename E>
E Edge<V, E>::GetData()
{
	return m_data;
}

/**********************************************************************
* Purpose: Setter for weight
*
* Precondition:
* weight - desired data for weight
*
* Postcondition:
* m_weight is set to weight
*
************************************************************************/
template<typename V, typename E>
void Edge<V, E>::SetWeight(int weight)
{
	m_weight = weight;
}

/**********************************************************************
* Purpose: Getter for weight
*
* Precondition:
* function is called
*
* Postcondition:
* m_weight is returned
*
************************************************************************/
template<typename V, typename E>
int Edge<V, E>::GetWeight()
{
	return m_weight;
}


#endif
