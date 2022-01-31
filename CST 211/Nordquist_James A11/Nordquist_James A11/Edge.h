#ifndef EDGE_H
#define EDGE_H
#include <iostream>

template<typename V, typename E>
class Vertice;

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
private:
	Vertice<V, E> * m_dest;
	E m_data;
	int m_weight; //not to be used here, just for dijkstra graph implentation later
};


template<typename V, typename E>
Edge<V, E>::Edge(): m_weight(0)
{
}

template<typename V, typename E>
Edge<V, E>::Edge(E data): m_weight(0), m_data(data)
{
}

template<typename V, typename E>
Edge<V, E>::Edge(const Edge & copy): m_weight(0), m_data(copy.m_data), m_dest(copy.m_dest)
{
}

template<typename V, typename E>
Edge<V, E>::~Edge()
{
	m_weight = 0;
}

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

template<typename V, typename E>
bool Edge<V, E>::operator==(const Edge & rhs)
{
	return m_data == rhs.m_data ? true : false;
}

template<typename V, typename E>
void Edge<V, E>::SetDest(Vertice<V, E> *dest)
{
	m_dest = dest;
}

template<typename V, typename E>
Vertice<V, E> *Edge<V, E>::GetDest()
{
	return m_dest;
}

template<typename V, typename E>
void Edge<V, E>::SetData(E data)
{
	m_data = data;
}

template<typename V, typename E>
E Edge<V, E>::GetData()
{


	return m_data9;
}


#endif
