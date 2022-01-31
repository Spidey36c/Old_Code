#ifndef BINARYSTREE_H
#define BINARYSTREE_H
#include "TNode.h"
#include <exception>
#include <queue>
using std::exception;
using std::queue;

template<typename T>
class BinarySTree
{
public:
	BinarySTree();
	BinarySTree(const BinarySTree & copy);
	~BinarySTree();
	BinarySTree & operator =(const BinarySTree & rhs);
	void Purge();
	int Height();
	int Height(TNode<T>* root);
	void Insert(T data);
	void Insert(T data, TNode<T>*& toins);
	void DeleteFind(T data);
	void DeleteFind(T data, TNode<T> *& root);
	void DeleteFound(TNode<T> *& root);
	void BreadthFirst(void Visit(T data));
	void PreOrder(void Visit(T data));
	void PostOrder(void Visit(T data));
	void InOrder(void Visit(T data));
	void PreOrder(TNode<T> *root,void Visit(T data));
	void PostOrder(TNode<T> *root,void Visit(T data));
	void InOrder(TNode<T> *root,void Visit(T data));
private:
	TNode<T>* m_head;
};

template<typename T>
BinarySTree<T>::BinarySTree(): m_head(nullptr)
{
}

template<typename T>
BinarySTree<T>::BinarySTree(const BinarySTree & copy)
{
	if (copy.m_head != nullptr)
	{
		queue<T> tocopy;
		copy.BreadthFirst(tocopy.push());

		while (tocopy.empty() == false)
		{
			Insert(tocopy.pop());
		}
	}
}

template<typename T>
BinarySTree<T>::~BinarySTree()
{
	Purge();
}

template<typename T>
BinarySTree<T> & BinarySTree<T>::operator=(const BinarySTree & rhs)
{
	if (this != &rhs)
	{
		Purge();
		if (rhs.m_head != nullptr)
		{
			queue<T> tocopy;
			rhs.BreadthFirst(tocopy.push());

			while (tocopy.empty() == false)
			{
				Insert(tocopy.pop());
			}
		}
	}
	return *this;
}

template<typename T>
void BinarySTree<T>::Purge()
{
	TNode<T>* temp = m_head;
	if (m_head != nullptr)
	{
		while (temp->GetLeft() != nullptr || temp->GetRight() != nullptr)
		{
			if (temp->GetLeft() != nullptr)
			{
				DeleteFind(temp->GetLeft()->GetData());
			}
			
			if (temp->GetRight() != nullptr)
			{
				DeleteFind(temp->GetRight()->GetData());
			}
		}
		DeleteFind(m_head->GetData());
	}
}

template<typename T>
int BinarySTree<T>::Height()
{
	int result;
	if (m_head == nullptr)
	{
		result = 0;
	}
	else
	{
		result = Height(m_head);
		result--;
	}
	return result;
}

template<typename T>
int BinarySTree<T>::Height(TNode<T>* root)
{
	int result;
	int rheight = 0;
	int lheight = 0;
	if (root != nullptr)
	{
		lheight = Height(root->GetLeft());
		rheight = Height(root->GetRight());
		if (lheight > rheight)
		{
			result = lheight + 1;
		}
		else
		{
			result = rheight + 1;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}


template<typename T>
void BinarySTree<T>::Insert(T data)
{
	if (m_head == nullptr)
	{
		TNode<T> *temp = new TNode<T>(data);
		m_head = temp;
	}
	else
	{
		if (data < m_head->GetData())
		{
			Insert(data, m_head->GetLeft());
		}
		else
		{
			Insert(data, m_head->GetRight());
		}
	}
}

template<typename T>
void BinarySTree<T>::Insert(T data, TNode<T>*& toins)
{
	if (toins == nullptr)
	{
		TNode<T> * temp = new TNode<T>(data);
		toins = temp;
	}
	else
	{
		if (data < toins->GetData())
		{
			Insert(data, toins->GetLeft());
		}
		else
		{
			Insert(data, toins->GetRight());
		}
	}
}

template<typename T>
void BinarySTree<T>::DeleteFind(T data)
{
	if (m_head == nullptr)
	{
		throw exception("Can't Delete from an empty tree");
	}
	else if (m_head->GetData() == data)
	{
		DeleteFound(m_head);
	}
	else
	{
		if (data < m_head->GetData())
		{
			DeleteFind(data, m_head->GetLeft());
		}
		else
		{
			DeleteFind(data, m_head->GetRight());
		}
	}
}

template<typename T>
void BinarySTree<T>::DeleteFind(T data, TNode<T>*& root)
{
	if (root == nullptr)
	{
		throw exception("Data not found");
	}
	else if (root->GetData() == data)
	{
		DeleteFound(root);
	}
	else
	{
		if (data < root->GetData())
		{
			DeleteFind(data, root->GetLeft());
		}
		else
		{
			DeleteFind(data, root->GetRight());
		}
	}
}

template<typename T>
void BinarySTree<T>::DeleteFound(TNode<T>*& root)
{
	TNode<T>* todel = root;
	if (root->GetLeft() == nullptr && root->GetRight() == nullptr)
	{
		root = nullptr;
	}
	else if (root->GetLeft() == nullptr)
	{
		root = root->GetRight();
	}
	else if (root->GetRight() == nullptr)
	{
		root = root->GetLeft();
	}
	else //non-empty left and right subtrees
	{
		TNode<T> *prev = root;

		todel = root->GetLeft();
		while (todel->GetRight() != nullptr)
		{
			prev = todel;
			todel = todel->GetRight();
		}
		root->GetData() = todel->GetData();
		if (prev == root)
		{
			prev->GetLeft() = todel->GetLeft();
		}
		else
		{
			prev->GetRight() = todel->GetLeft();
		}
	}
	delete todel;

}

template<typename T>
void BinarySTree<T>::BreadthFirst(void Visit(T data))
{
	queue<TNode<T>*> queue;
	TNode<T> * p = m_head;
	if (p != nullptr)
	{
		queue.push(p);
		while (!queue.empty())
		{
			p = queue.front();
			queue.pop();
			Visit(p->GetData());
			if (p->GetLeft() != nullptr)
			{
				queue.push(p->GetLeft());
			}
			if (p->GetRight() != nullptr)
			{
				queue.push(p->GetRight());
			}
		}
	}
}

template<typename T>
void BinarySTree<T>::PreOrder(void Visit(T data))
{
	PreOrder(m_head, Visit);
}

template<typename T>
void BinarySTree<T>::PostOrder(void Visit(T data))
{
	PostOrder(m_head, Visit);
}

template<typename T>
void BinarySTree<T>::InOrder(void Visit(T data))
{
	InOrder(m_head, Visit);
}

template<typename T>
void BinarySTree<T>::PreOrder(TNode<T> *root, void Visit(T data))
{
	if (root != nullptr)
	{
		Visit(root->GetData());
		PreOrder(root->GetLeft(), Visit);
		PreOrder(root->GetRight(), Visit);
	}
}

template<typename T>
void BinarySTree<T>::PostOrder(TNode<T>* root, void Visit(T data))
{
	if (root != nullptr)
	{
		PostOrder(root->GetLeft(), Visit);
		PostOrder(root->GetRight(), Visit);
		Visit(root->GetData());
	}
}

template<typename T>
void BinarySTree<T>::InOrder(TNode<T>* root, void Visit(T data))
{
	if (root != nullptr)
	{
		InOrder(root->GetLeft(), Visit);
		Visit(root->GetData());
		InOrder(root->GetRight(), Visit);
	}
}


#endif

