#ifndef LISTITER_H
#define LISTITER_H
#include "AbstractIter.h"
#include "Node.h"
#include "List.h"

template<typename T>
class ListIter : public AbstractIter<T>
{
public:
	ListIter();
	ListIter(List<T> list);
	ListIter(const ListIter & copy);
	virtual ~ListIter();
	virtual ListIter & operator =(const ListIter & rhs);
	virtual void MoveNext() = 0;
	virtual void Reset() = 0;
	virtual bool IsDone();
	virtual Node<T> GetCurrent();
protected:
	Node<T> * m_current;
	List<T> m_list;
};

template<typename T>
ListIter<T>::ListIter(): AbstractIter<T>()
{
}

template<typename T>
ListIter<T>::ListIter(List<T> list): AbstractIter<T>()
{
	m_current = nullptr;
	m_list = list;
}

template<typename T>
ListIter<T>::ListIter(const ListIter & copy): m_list(copy.m_list)
{
	Node<T> * temp = m_list.GetHead();
	int location = m_list.Find(copy.m_current);
	for (int i = 0; i < location; i++)
	{
		temp = temp->GetNext();
	}
	m_current = temp;
}

template<typename T>
ListIter<T>::~ListIter()
{
}

template<typename T>
ListIter<T> & ListIter<T>::operator=(const ListIter & rhs)
{
	if (this != &rhs)
	{
		m_list = rhs.m_list;
		Node<T> * temp = m_list.GetHead();
		int location = m_list.Find(rhs.m_current);
		for (int i = 0; i < location; i++)
		{
			temp = temp->GetNext();
		}
		m_current = temp;
	}
	return *this;
}

template<typename T>
bool ListIter<T>::IsDone()
{
	bool done = false;
	if (m_current == nullptr)
	{
		done = true;
	}
	return done;
}

template<typename T>
Node<T> ListIter<T>::GetCurrent()
{
	return *m_current;
}

#endif

