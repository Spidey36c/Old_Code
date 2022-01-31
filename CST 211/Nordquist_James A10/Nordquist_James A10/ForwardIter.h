#ifndef FORWARDITER_H
#define FORWARDITER_H
#include "ListIter.h"

template<typename T>
class ForwardIter : public ListIter<T>
{
public:
	ForwardIter();
	ForwardIter(List<T> list);
	ForwardIter(const ForwardIter & copy);
	virtual ~ForwardIter();
	ForwardIter & operator =(const ForwardIter & copy);
	void MoveNext();
	void Reset();
};

template<typename T>
ForwardIter<T>::ForwardIter() : ListIter<T>()
{
}

template<typename T>
ForwardIter<T>::ForwardIter(List<T> list): ListIter<T>(list)
{
}

template<typename T>
ForwardIter<T>::ForwardIter(const ForwardIter & copy): ListIter<T>(copy.m_list)
{
	this->m_current = copy->m_current;
}

template<typename T>
ForwardIter<T>::~ForwardIter()
{
}

template<typename T>
ForwardIter<T> & ForwardIter<T>::operator=(const ForwardIter & rhs)
{
	if (this != &rhs)
	{
		this->m_list = rhs.m_list;
		this->m_current = rhs.m_current;
	}
	return *this;
}

template<typename T>
void ForwardIter<T>::MoveNext()
{
	if (m_current != nullptr)
	{
		this->m_current = this->m_current->GetNext();
	}
}

template<typename T>
void ForwardIter<T>::Reset()
{
	this->m_current = this->m_list.GetHead();
}


#endif

