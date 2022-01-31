/*************************************************************
* Author: James Nordqist
* Filename: Vertice.h
* Date Created: 3/7/19
* Modifications: 3/8/19 - Added GetList
**************************************************************/
#ifndef VERTICE_H
#define VERTICE_H
#include "Edge.h"
#include <list>
using std::list;

/************************************************************************
* Class: Vertice
*
* Purpose: This class is a point on a graph
*
* Manager functions:
* Vertice();
*	default ctor
* Vertice(E data);
*	one arg ctor
* Vertice(const Vertice & copy);
*	copy ctor
* ~Vertice();
*	dtor
* Vertice & operator =(const Vertice & rhs);
*	op =
*
* Methods:
* bool operator ==(const Vertice & rhs);
*	op== comparing m_data and rhs.m_data
* void AddEdge(Edge<V,E> edge);
*	Adds an edge to the list based off of edge
* void DeleteEdge(Edge<V,E> data);
*	Deletes an edge from the list
* list<Edge<V,E>> &GetEdges();
*	getter for the list of edges
* void SetData(V data);
*	setter for m_data
* V GetData();
*	getter for m_data
* void SetProcessed(bool process);
*	setter for m_processed
* bool GetProcessed();
*	getter for m_processed
*************************************************************************/
template<typename V, typename E>
class Vertice
{
public:
	Vertice();
	Vertice(V data);
	Vertice(const Vertice & copy);
	~Vertice();
	Vertice & operator =(const Vertice & rhs);
	bool operator ==(const Vertice & rhs);
	void AddEdge(Edge<V,E> edge);
	void DeleteEdge(Edge<V,E> data);
	list<Edge<V,E>> &GetEdges();
	void SetData(V data);
	V GetData();
	void SetProcessed(bool process);
	bool GetProcessed();
private:
	V m_data;
	bool m_processed = false;
	list<Edge<V,E>> m_edges;
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
Vertice<V, E>::Vertice()
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
Vertice<V, E>::Vertice(V data): m_data(data)
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
Vertice<V, E>::Vertice(const Vertice & copy): m_data(copy.m_data), m_edges(copy.m_edges)
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
Vertice<V, E>::~Vertice()
{
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
Vertice<V,E> & Vertice<V, E>::operator=(const Vertice & rhs)
{
	if (this != &rhs)
	{
		m_edges = rhs.m_edges;
		m_data = rhs.m_data;
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
bool Vertice<V, E>::operator==(const Vertice & rhs)
{
	return m_data == rhs.m_data ? true : false;
}

/**********************************************************************
* Purpose: adds an edge to the list
*
* Precondition:
* edge - edge to be added
*
* Postcondition:
* adds edge to list
*
************************************************************************/
template<typename V, typename E>
void Vertice<V, E>::AddEdge(Edge<V,E> edge)
{
	m_edges.push_back(edge);
}

/**********************************************************************
* Purpose: deletes an edge from the list
*
* Precondition:
* data - edge to be deleted
*
* Postcondition:
* returns true if they are the same, false otherwise
*
************************************************************************/
template<typename V, typename E>
void Vertice<V, E>::DeleteEdge(Edge<V,E> data)
{
	m_edges.remove(data);
}

/**********************************************************************
* Purpose: Getter for edges
*
* Precondition:
* function is called
*
* Postcondition:
* returns the list of edges
*
************************************************************************/
template<typename V, typename E>
list<Edge<V,E>> &Vertice<V, E>::GetEdges()
{
	return m_edges;
}

/**********************************************************************
* Purpose: Getter for data
*
* Precondition:
* data- desired data for m_data
*
* Postcondition:
* m_data is set to data
*
************************************************************************/
template<typename V, typename E>
void Vertice<V, E>::SetData(V data)
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
* returns m_data
*
************************************************************************/
template<typename V, typename E>
V Vertice<V, E>::GetData()
{
	return m_data;
}

/**********************************************************************
* Purpose: Setter for m_processed
*
* Precondition:
* process - desired bool for m_processed
*
* Postcondition:
* m_processed is set to process
*
************************************************************************/
template<typename V, typename E>
void Vertice<V, E>::SetProcessed(bool process)
{
	m_processed = process;
}

/**********************************************************************
* Purpose: Getter for processed
*
* Precondition:
* function is called
*
* Postcondition:
* returns m_processed
*
************************************************************************/
template<typename V, typename E>
bool Vertice<V, E>::GetProcessed()
{
	return m_processed;
}


#endif
