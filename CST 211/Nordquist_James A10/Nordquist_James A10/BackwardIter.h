#ifndef BACKWARDITER_H
#define BACKWARDITER_H
#include "ListIter.h"

template<typename T>
class BackwardIter : public ListIter<T>
{
public:
	BackwardIter();
	BackwardIter(List<T> list);
	BackwardIter(const BackwardIter & copy);
	virtual ~BackwardIter();
	BackwardIter & operator =(const BackwardIter & copy);
	void MoveNext();
	void Reset();
};

template<typename T>
BackwardIter<T>::BackwardIter() : ListIter()
{
}

template<typename T>
BackwardIter<T>::BackwardIter(List<T> list) : ListIter()
{
}

template<typename T>
BackwardIter<T>::BackwardIter(const BackwardIter & copy) : ListIter(copy.m_list)
{
	this->m_current = copy.m_current;
}

template<typename T>
BackwardIter<T>::~BackwardIter()
{
}

template<typename T>
BackwardIter<T> & BackwardIter<T>::operator=(const BackwardIter & copy)
{
	if (this != &rhs)
	{
		this->m_list = copy.m_list;
		this->m_current = copy.m_current;
	}
	return *this;
}

template<typename T>
void BackwardIter<T>::MoveNext()
{
	if (m_current != nullptr)
	{
		this->m_current = this->m_current->GetNext();
	}
}

template<typename T>
void BackwardIter<T>::Reset()
{
	this->m_current = this->m_list.GetHead();
}


#endif

