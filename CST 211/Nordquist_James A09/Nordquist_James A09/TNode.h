#ifndef TNODE_H
#define TNODE_H

template<typename T>
class TNode
{
public:
	TNode();
	TNode(T data);
	TNode(const TNode & copy);
	~TNode();
	TNode & operator =(const TNode & rhs);
	TNode *& GetLeft();
	void SetLeft(TNode *left);
	TNode *& GetRight();
	void SetRight(TNode *right);
	T & GetData();
private:
	T m_data;
	TNode<T> * m_left;
	TNode<T> * m_right;
};

template<typename T>
TNode<T>::TNode(): m_left(nullptr), m_right(nullptr), m_data(0)
{
}

template<typename T>
TNode<T>::TNode(T data): m_data(data), m_left(nullptr), m_right(nullptr)
{
}

template<typename T>
TNode<T>::TNode(const TNode & copy): m_data(copy.m_data), m_left(nullptr), m_right(nullptr)
{
}

template<typename T>
TNode<T>::~TNode()
{
	m_left = nullptr;
	m_right = nullptr;
	m_data = 0;
}

template<typename T>
TNode<T> & TNode<T>::operator=(const TNode & rhs)
{
	if (*this != rhs)
	{
		m_data = rhs.m_data;
	}
	return *this;
}

template<typename T>
TNode<T> *& TNode<T>::GetLeft()
{
	return m_left;
}

template<typename T>
void TNode<T>::SetLeft(TNode * left)
{
	m_left = left;
}

template<typename T>
TNode<T> *& TNode<T>::GetRight()
{
	return m_right;
}

template<typename T>
void TNode<T>::SetRight(TNode * right)
{
	m_right = right;
}

template<typename T>
T & TNode<T>::GetData()
{
	return m_data;
}








#endif

