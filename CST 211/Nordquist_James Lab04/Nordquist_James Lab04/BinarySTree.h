/*************************************************************
* Author: James Nordquist
* Filename: BinarySTree.H
* Date Created: 2/16/19
* Modifications: 2/19/19 - Made a double of everything thats recursive
*						   so no node needs to be placed for user to use them
**************************************************************/
/************************************************************************
* Class: BinarySTree
*
* Purpose: This class is a binary search tree data structure
* Manager functions:
* BinarySTree();
*	default ctor
* BinarySTree(const BinarySTree & copy);
*	copy ctor
* ~BinarySTree();
*	dtor
* BinarySTree & operator =(const BinarySTree & rhs);
*	op =
*
* Methods:
* void Purge();
*	empties the tree
* int Height();
*	returns the height of the tree
* int Height(TNode<T>* root);
*	recursive, figures out the height of roots two children nodes returns the heighest number
* void Insert(T data);
*	inserts data into the tree
* void Insert(T data, TNode<T>*& toins);
*	recursive finds a place to insert the data into the tree
* void DeleteFind(T data);
*	finds node that holds the data to be deleted, throws exception if tree is empty
* void DeleteFind(T data, TNode<T> *& root);
*	recursive, finds the node that holds the data
* void DeleteFound(TNode<T> *& root);
*	deletes the node that holds the data and fixes the tree as necessary
* void BreadthFirst(void Visit(T data));
*	visits the tree from top to bottom left to right
* void PreOrder(void Visit(T data));
*	calls recursive preorder with m_head
* void PostOrder(void Visit(T data));
*	calls recursive postorder with m_head
* void InOrder(void Visit(T data));
*	calls recursive inorder with m_head
* void PreOrder(TNode<T> *root,void Visit(T data));
*	recursive visits the tree left to right starting with head
* void PostOrder(TNode<T> *root,void Visit(T data));
*	recursive visits the tree left to right ending with head
* void InOrder(TNode<T> *root,void Visit(T data));
*	recursive visits the tree left to right node by node
*************************************************************************/
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
protected:
	TNode<T>* m_head;
};

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* object is created
*
* Postcondition:
* object is instantiated using default values
*
************************************************************************/
template<typename T>
BinarySTree<T>::BinarySTree(): m_head(nullptr)
{
}

/**********************************************************************
* Purpose: copy ctor
*
* Precondition:
* object is created with copy
*
* Postcondition:
* this tree has the same nodes as the copy tree
*
************************************************************************/
template<typename T>
BinarySTree<T>::BinarySTree(const BinarySTree & copy)
{
	if (copy.m_head != nullptr)
	{
		queue<TNode<T>*> tocopy;
		TNode<T> * p = copy.m_head;
		if (p != nullptr)
		{
			tocopy.push(p);
			while (!tocopy.empty())
			{
				p = tocopy.front();
				tocopy.pop();
				Insert(p->GetData());
				if (p->GetLeft() != nullptr)
				{
					tocopy.push(p->GetLeft());
				}
				if (p->GetRight() != nullptr)
				{
					tocopy.push(p->GetRight());
				}
			}
		}
	}
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* object is deleted or goes out of scope
*
* Postcondition:
* tree is emptied and set back to default values
*
************************************************************************/
template<typename T>
BinarySTree<T>::~BinarySTree()
{
	Purge();
}

/**********************************************************************
* Purpose: op =
*
* Precondition:
* object is set to equal rhs
*
* Postcondition:
* tree has the same data in appropriate nodes
*
************************************************************************/
template<typename T>
BinarySTree<T> & BinarySTree<T>::operator=(const BinarySTree & rhs)
{
	if (this != &rhs)
	{
		Purge();
		if (rhs.m_head != nullptr)
		{
			queue<TNode<T>*> tocopy;
			TNode<T> * p = rhs.m_head;
			if (p != nullptr)
			{
				tocopy.push(p);
				while (!tocopy.empty())
				{
					p = tocopy.front();
					tocopy.pop();
					Insert(p->GetData());
					if (p->GetLeft() != nullptr)
					{
						tocopy.push(p->GetLeft());
					}
					if (p->GetRight() != nullptr)
					{
						tocopy.push(p->GetRight());
					}
				}
			}
		}
	}
	return *this;
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* function is called
*
* Postcondition:
* tree is emptied
*
************************************************************************/
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
	m_head = nullptr;
}
/**********************************************************************
* Purpose: returns the height of the tree
*
* Precondition:
* function is called
*
* Postcondition:
* height of the tree is returned, 0 is tree is empty
*
************************************************************************/
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

/**********************************************************************
* Purpose: finds the height of the root, by finding the the height of its children
*
* Precondition:
* root-height of node to find
*
* Postcondition:
* returns the height of node, 0 if nullptr
*
************************************************************************/
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

/**********************************************************************
* Purpose: inserts a node into the tree at the appropriate place with the data
*
* Precondition:
* data- data to be inserted
*
* Postcondition:
* data is inserted at the correct location in the tree
*
************************************************************************/
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

/**********************************************************************
* Purpose: inserts a node into the tree at the appropriate place with the data
*
* Precondition:
* data- data to be inserted
* toins- node that is currently being looked at
*
* Postcondition:
* data is inserted at the correct location in the tree
*
************************************************************************/
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

/**********************************************************************
* Purpose: finds the node that needs to be deleted
*
* Precondition:
* data- data to find in node
*
* Postcondition:
* node is deleted or exception is throw if there is no nodes in the tree
*
************************************************************************/
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

/**********************************************************************
* Purpose: finds the node that needs to be deleted
*
* Precondition:
* data- data to find in node
* root- node currently being looked at
*
* Postcondition:
* node is deleted or exception is throw if there is data is not found
*
************************************************************************/
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

/**********************************************************************
* Purpose: finds the node that needs to be deleted
*
* Precondition:
* root - node to be deleted
*
* Postcondition:
* node is deleted
*
************************************************************************/
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

/**********************************************************************
* Purpose: visits the nodes in order of top to bottom left to right
*
* Precondition:
* visit - function pointer
*
* Postcondition:
* all nodes are visited
*
************************************************************************/
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

/**********************************************************************
* Purpose: visits the nodes in order of left to right starting with the node visited
*		   then its left then right child
*
* Precondition:
* visit - function pointer
*
* Postcondition:
* all nodes are visited
*
************************************************************************/
template<typename T>
void BinarySTree<T>::PreOrder(void Visit(T data))
{
	PreOrder(m_head, Visit);
}

/**********************************************************************
* Purpose: visits the nodes in order of left to right ending with head
*
* Precondition:
* visit - function pointer
*
* Postcondition:
* all nodes are visited
*
************************************************************************/
template<typename T>
void BinarySTree<T>::PostOrder(void Visit(T data))
{
	PostOrder(m_head, Visit);
}

/**********************************************************************
* Purpose: visits the nodes in order of left to right going in the
*		   order left child, visit, right node
*
* Precondition:
* visit - function pointer
*
* Postcondition:
* all nodes are visited
*
************************************************************************/
template<typename T>
void BinarySTree<T>::InOrder(void Visit(T data))
{
	InOrder(m_head, Visit);
}

/**********************************************************************
* Purpose: visits the nodes in order of left to right starting with the node visited
*		   then its left then right child
*
* Precondition:
* visit - function pointer
*
* Postcondition:
* all nodes are visited
*
************************************************************************/
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

/**********************************************************************
* Purpose: visits the nodes in order of left to right ending with head
*
* Precondition:
* visit - function pointer
*
* Postcondition:
* all nodes are visited
*
************************************************************************/
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

/**********************************************************************
* Purpose: visits the nodes in order of left to right going in the
*		   order left child, visit, right node
*
* Precondition:
* visit - function pointer
*
* Postcondition:
* all nodes are visited
*
************************************************************************/
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

