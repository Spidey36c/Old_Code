/*************************************************************
* Author: James Nordqist
* Filename: Graph.h
* Date Created: 3/8/19
* Modifications: 3/9/19 - Added ResetProcessed
*				 3/11/19 - Added GetVertices
**************************************************************/
#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"
#include "Vertice.h"
#include <list>
#include <algorithm>
#include <exception>
#include <stack>
#include <queue>
using std::queue;
using std::stack;
using std::list;
using std::iterator;
using std::exception;

/************************************************************************
* Class: Graph
*
* Purpose: This class is a graph with vertices and edges
*
* Manager functions:
* Graph();
*	default ctor
* Graph(const Graph & copy);
*	copy ctor
* ~Graph();
*	dtor
* Graph & operator =(const Graph & rhs);
*	op =
*
* Methods:
* void InsertVertex(V data);
*	inserts a vertex into the list
* void DeleteVertex(V data);
*	deletes a vertex from the list if it exists
* void InsertEdge(V from, E edge, V to,int weight);
*	inserts an edge between two vertices if they exist
* void DeleteEdge(V from, E edge, V to);
*	deltes an edge between two vertices if they and the edge exist
* void DepthFirst(void(*visit)(V data));
*	Traversal to view the data in the graph
* void BreadthFirst(void(*visit)(V data));
*	traversal to view the data in the graph
* bool IsEmpty();
*	returns true if list is empty
* void ResetProcessed();
*	resets all the vertices processed to false
* list<Vertice<V,E>> GetVertices();
*	returns the list of vertices
*************************************************************************/
template<typename V, typename E>
class Graph
{
public:
	Graph();
	Graph(const Graph & copy);
	~Graph();
	Graph & operator =(const Graph & rhs);
	void InsertVertex(V data);
	void DeleteVertex(V data);
	void InsertEdge(V from, E edge, V to,int weight);
	void DeleteEdge(V from, E edge, V to);
	void DepthFirst(void(*visit)(V data));
	void BreadthFirst(void(*visit)(V data));
	bool IsEmpty();
	void ResetProcessed();
	list<Vertice<V,E>> GetVertices();
private:
	list<Vertice<V, E>> m_vertices;
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
Graph<V, E>::Graph()
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
Graph<V, E>::Graph(const Graph & copy) : m_vertices(copy.m_vertices)
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
Graph<V, E>::~Graph()
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
Graph<V,E> & Graph<V, E>::operator=(const Graph & rhs)
{
	if (this != &rhs)
	{
		m_vertices = rhs.m_vertices;
	}
	return *this;
}

/**********************************************************************
* Purpose: insert a vertex into the list
*
* Precondition:
* data - vertex to be inserted
*
* Postcondition:
* if data is unique, vertice is inserted with V data
*
************************************************************************/
template<typename V, typename E>
void Graph<V, E>::InsertVertex(V data)
{
	if (find(m_vertices.begin(), m_vertices.end(), data) == m_vertices.end())
	{
		Vertice<V, E> toins(data);
		m_vertices.push_back(toins);
	}
}

/**********************************************************************
* Purpose: delete a vertex from the list
*
* Precondition:
* data - vertex to be delete
*
* Postcondition:
* if vertex exists, it is deleted, otherwise an exception is thrown
*
************************************************************************/
template<typename V, typename E>
void Graph<V, E>::DeleteVertex(V data)
{
	typename list<Vertice<V, E>>::iterator ifind = find(m_vertices.begin(), m_vertices.end(), data);
	if (ifind != m_vertices.end())
	{
		list<Edge<V, E>> todel = ifind->GetEdges();
		Edge<V, E> etemp;
		Vertice<V, E> *vtemp;
		while (todel.empty() == false)
		{
			etemp = todel.front();
			vtemp = etemp.GetDest();
			vtemp->DeleteEdge(etemp);
			ifind->DeleteEdge(etemp);
			todel = ifind->GetEdges();
		}
		m_vertices.remove(*ifind);
	}
	else
	{
		throw exception("No vertice found with that data");
	}
}

/**********************************************************************
* Purpose: insert an edge between two vertices
*
* Precondition:
* edge - edge to be inserted
* from,to - vertices to have the edge inserted between them
* weight - weight of the edge
*
* Postcondition:
* if from and to vertices exists, data is inserted, else exception is thrown
*
************************************************************************/
template<typename V, typename E>
void Graph<V, E>::InsertEdge(V from, E edge, V to, int weight)
{
	typename list<Vertice<V, E>>::iterator ifind = find(m_vertices.begin(), m_vertices.end(), from);
	Edge<V, E> toins1(edge);
	Edge<V, E> toins2(edge);
	Vertice<V, E> *fromptr;
	Vertice<V, E> *toptr;
	if (ifind != m_vertices.end())
	{
		fromptr = &*ifind;
		ifind = find(m_vertices.begin(), m_vertices.end(), to);
		if (ifind != m_vertices.end())
		{
			toptr = &*ifind;
			toins2.SetDest(fromptr);
			toins2.SetWeight(weight);
			toins1.SetDest(toptr);
			toins1.SetWeight(weight);
			fromptr->AddEdge(toins1);
			toptr->AddEdge(toins2);
		}
		else
		{
			throw exception("To Vertex does not exist");
		}
	}
	else
	{
		throw exception("From Vertex does not exist");
	}
}

/**********************************************************************
* Purpose: deletes an edge two vertices
*
* Precondition:
* edge - edge to be deleted
* from,to - vertices to have the edge deleted between them
*
* Postcondition:
* if from and to vertices exists, edge is deleted if it exists, else exception is thrown
*
************************************************************************/
template<typename V, typename E>
void Graph<V, E>::DeleteEdge(V from, E edge, V to)
{
	typename list<Vertice<V, E>>::iterator ifind = find(m_vertices.begin(), m_vertices.end(), from);
	Edge<V, E> todel1(edge);
	Vertice<V, E> *fromptr;
	Vertice<V, E> *toptr;
	if (ifind != m_vertices.end())
	{
		fromptr = &*ifind;
		ifind = find(m_vertices.begin(), m_vertices.end(), to);
		if (ifind != m_vertices.end())
		{
			toptr = &*ifind;
			fromptr->DeleteEdge(todel1);
			toptr->DeleteEdge(todel1);
		}
		else
		{
			throw exception("To Vertex not found");
		}
	}
	else
	{
		throw exception("From Vertex not found");
	}
}

/**********************************************************************
* Purpose: traversal of the graph
*
* Precondition:
* visit - function to read the data in the vertice
*
* Postcondition:
* all the vertices are visted in a depth first traversal
*
************************************************************************/
template<typename V, typename E>
void Graph<V, E>::DepthFirst(void(*visit)(V data))
{
	Vertice<V,E> *toprocess;
	list<Edge<V, E>> toprcedge;
	typename list<Edge<V, E>>::iterator efind;
	stack<Vertice<V, E>*> travel;
	toprocess = &m_vertices.front();
	travel.push(toprocess);
	while (travel.empty() == false)
	{
		toprocess = travel.top();
		travel.pop();
		visit(toprocess->GetData());
		toprcedge = toprocess->GetEdges();
		toprocess->SetProcessed(true);
		efind = toprcedge.begin();
		while (efind != toprcedge.end())
		{
			toprocess = efind->GetDest();
			if (toprocess->GetProcessed() == false)
			{
				travel.push(toprocess);
			}
			efind++;
		}

	}
	ResetProcessed();
}

/**********************************************************************
* Purpose: traversal of the graph
*
* Precondition:
* visit - function to read the data in the vertice
*
* Postcondition:
* all the vertices are visted in a breadth first traversal
*
************************************************************************/
template<typename V, typename E>
void Graph<V, E>::BreadthFirst(void(*visit)(V data))
{
	Vertice<V, E> *toprocess;
	list<Edge<V, E>> toprcedge;
	typename list<Edge<V, E>>::iterator efind;
	queue<Vertice<V, E>*> travel;
	toprocess = &m_vertices.front();
	travel.push(toprocess);
	while (travel.empty() == false)
	{
		toprocess = travel.front();
		travel.pop();
		visit(toprocess->GetData());
		toprcedge = toprocess->GetEdges();
		toprocess->SetProcessed(true);
		efind = toprcedge.begin();
		while (efind != toprcedge.end())
		{
			toprocess = efind->GetDest();
			if (toprocess->GetProcessed() == false)
			{
				travel.push(toprocess);
			}
			efind++;
		}
	}
	ResetProcessed();
}

/**********************************************************************
* Purpose: returns a bool based on whether list is empty or not
*
* Precondition:
* function is called
*
* Postcondition:
* returns true if m_vertices is empty, otherwise false
*
************************************************************************/
template<typename V, typename E>
bool Graph<V, E>::IsEmpty()
{
	return m_vertices.empty();
}

/**********************************************************************
* Purpose:  resets all the vertices m_processed in the graph to false 
*
* Precondition:
* function is called
*
* Postcondition:
* all vertices m_processed is set to false
*
************************************************************************/
template<typename V, typename E>
void Graph<V, E>::ResetProcessed()
{
	typename list<Vertice<V, E>>::iterator reset = m_vertices.begin();
	while (reset != m_vertices.end())
	{
		reset->SetProcessed(false);
		reset++;
	}
}

/**********************************************************************
* Purpose: getter for list of vertices
*
* Precondition:
* function is called
*
* Postcondition:
* returns the list of vertices
*
************************************************************************/
template<typename V, typename E>
list<Vertice<V,E>> Graph<V, E>::GetVertices()
{
	return m_vertices;
}

#endif


