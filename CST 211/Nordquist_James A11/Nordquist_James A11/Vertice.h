#ifndef VERTICE_H
#define VERTICE_H
#include "Edge.h"
#include <list>
using std::list;

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

template<typename V, typename E>
Vertice<V, E>::Vertice()
{
}

template<typename V, typename E>
Vertice<V, E>::Vertice(V data): m_data(data)
{
}

template<typename V, typename E>
Vertice<V, E>::Vertice(const Vertice & copy): m_data(copy.m_data), m_edges(copy.m_edges)
{
}

template<typename V, typename E>
Vertice<V, E>::~Vertice()
{
}

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

template<typename V, typename E>
bool Vertice<V, E>::operator==(const Vertice & rhs)
{
	return m_data == rhs.m_data ? true : false;
}

template<typename V, typename E>
void Vertice<V, E>::AddEdge(Edge<V,E> edge)
{
	m_edges.push_back(edge);
}

template<typename V, typename E>
void Vertice<V, E>::DeleteEdge(Edge<V,E> data)
{
	m_edges.remove(data);
}

template<typename V, typename E>
list<Edge<V,E>> &Vertice<V, E>::GetEdges()
{
	return m_edges;
}

template<typename V, typename E>
void Vertice<V, E>::SetData(V data)
{
	m_data = data;
}

template<typename V, typename E>
V Vertice<V, E>::GetData()
{
	return m_data;
}

template<typename V, typename E>
void Vertice<V, E>::SetProcessed(bool process)
{
	m_processed = process;
}

template<typename V, typename E>
bool Vertice<V, E>::GetProcessed()
{
	return m_processed;
}


#endif
