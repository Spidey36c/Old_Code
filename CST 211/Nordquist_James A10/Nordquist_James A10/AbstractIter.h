#ifndef ABSTRACTITER_H
#define ABSTRACTITER_H
template<typename T>
class AbstractIter
{
public:
	AbstractIter();
	AbstractIter(const AbstractIter & copy);
	virtual ~AbstractIter() = 0;
	virtual AbstractIter & operator =(const AbstractIter & rhs);
	virtual void MoveNext() = 0;
	virtual void Reset() = 0;
	virtual bool IsDone() = 0;
	virtual T GetCurrent() = 0;
};

template<typename T>
AbstractIter<T>::AbstractIter()
{
}

template<typename T>
AbstractIter<T>::AbstractIter(const AbstractIter & copy)
{
}

template<typename T>
AbstractIter<T> & AbstractIter<T>::operator=(const AbstractIter & rhs)
{

}

#endif


