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
	void InsertEdge(V from, E edge, V to);
	void DeleteEdge(V from, E edge, V to);
	void DepthFirst(void(*visit)(V data));
	void BreadthFirst(void(*visit)(V data));
	bool IsEmpty();
	void ResetProcessed();
private:
	list<Vertice<V, E>> m_vertices;
};

template<typename V, typename E>
Graph<V, E>::Graph()
{
}

template<typename V, typename E>
Graph<V, E>::Graph(const Graph & copy) : m_vertices(copy.m_vertices)
{
}

template<typename V, typename E>
Graph<V, E>::~Graph()
{
}

template<typename V, typename E>
Graph<V,E> & Graph<V, E>::operator=(const Graph & rhs)
{
	if (this != &rhs)
	{
		m_vertices = rhs.m_vertices;
	}
	return *this;
}

template<typename V, typename E>
void Graph<V, E>::InsertVertex(V data)
{
	Vertice<V, E> toins(data);
	m_vertices.push_back(toins);
}

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

template<typename V, typename E>
void Graph<V, E>::InsertEdge(V from, E edge, V to)
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
			toins1.SetDest(toptr);
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

template<typename V, typename E>
bool Graph<V, E>::IsEmpty()
{
	return m_vertices.empty();
}

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

#endif


