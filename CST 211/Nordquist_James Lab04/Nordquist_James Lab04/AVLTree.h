/*************************************************************
* Author: James Nordquist
* Filename: AVLTree.h
* Date Created: 2/21/19
* Modifications: 2/22/19 - fixed delete made balance function
*				 2/23/19 - made balance function into VBalacne and Ibalance
*					       to avoid conflict with balance enum
**************************************************************/
/************************************************************************
* Class: AVLTree
*
* Purpose: This class is an AVL Tree data structure
* Manager functions:
* AVLTree();
*	default ctor
* AVLTree(const AVLTree & copy);
*	copy ctor
* ~AVLTree();
*	dtor
* AVLTree & operator =(const AVLTree & copy);
*	op =
*
* Methods:
* void InsertAVL(T data)
*	calls recursive insert
* void InsertAVL(TNode<T> *& root, T data, bool & taller)
*	recursive, Inserts data into tree and figures out the balance
* void DeleteAVL(T data)
*	finds the node to delete and deletes it and fixes the tree, throws an exception if tree is empty
* void DeleteAVL(TNode<T> *& root, T data)
*	recursive, finds the node to delete and deletes it and fixes the tree, throws an exception if data is not found
* void VBalance(TNode<T> *& root)
*	Balances root by looking at its children
* int IBalance(TNode<T> *& root)
*	Balances and returns the heigh of root by looking at its children
* void LeftBalance(TNode<T> *& root)
*	Checks to see how the tree needs to be balanced to the left using ll or lr
* void RightBalance(TNode<T> *& root)
*	Checks to see how the tree needs to be balanced to the right using rr or rl
* void RR(TNode<T> *& root)
*	performs an rr on root
* void LL(TNode<T> *& root)
*	performs an ll on root
*************************************************************************/
#ifndef AVLTREE_H
#define AVLTREE_H
#include "BinarySTree.h"
#include "TNode.h"

template<typename T>
class AVLTree: public BinarySTree<T>
{
public:
	AVLTree();
	AVLTree(const AVLTree & copy);
	~AVLTree();
	AVLTree & operator =(const AVLTree & rhs);
	void InsertAVL(T data);
	void InsertAVL(TNode<T> *& root, T data, bool & taller);
	void DeleteAVL(T data);
	void DeleteAVL(TNode<T> *& root, T data);
	void VBalance(TNode<T> *& root);
	int IBalance(TNode<T> *& root);
	void LeftBalance(TNode<T> *& root);
	void RightBalance(TNode<T> *& root);
	void RR(TNode<T> *& root);
	void LL(TNode<T> *& root);
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
AVLTree<T>::AVLTree()
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
AVLTree<T>::AVLTree(const AVLTree & copy)
{
	if (copy.BinarySTree<T>::m_head != nullptr)
	{
		queue<TNode<T>*> tocopy;
		TNode<T> * p = copy.BinarySTree<T>::m_head;
		if (p != nullptr)
		{
			tocopy.push(p);
			while (!tocopy.empty())
			{
				p = tocopy.front();
				tocopy.pop();
				InsertAVL(p->GetData());
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
AVLTree<T>::~AVLTree()
{
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
AVLTree<T> & AVLTree<T>::operator=(const AVLTree & rhs)
{
	if (this != &rhs)
	{
		BinarySTree<T>::Purge();
		if (rhs.BinarySTree<T>::m_head != nullptr)
		{
			//thought I figured out how to copy tree using breadthfirst in binarystree but i think the binarystree i have is a bit old
			queue<TNode<T>*> tocopy;
			TNode<T> * p = rhs.BinarySTree<T>::m_head;
			if (p != nullptr)
			{
				tocopy.push(p);
				while (!tocopy.empty())
				{
					p = tocopy.front();
					tocopy.pop();
					InsertAVL(p->GetData());
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
* Purpose: Inserts data into the tree at the appropriate location, and balances
*		   the tree as necessary
*
* Precondition:
* data - data to be inserted
*
* Postcondition:
* data is inserted at the correct location and balances as needed
*
************************************************************************/
template<typename T>
void AVLTree<T>::InsertAVL(T data)
{
	bool taller = true;
	InsertAVL(BinarySTree<T>::m_head, data, taller);
	VBalance(BinarySTree<T>::m_head);
}

/**********************************************************************
* Purpose: Inserts data into the tree at the appropriate location, and balances
*		   the tree as necessary
*
* Precondition:
* data - data to be inserted
* root - Node currently pointing at 
* taller - bool to check if other nodes need to be changed
*
* Postcondition:
* data is inserted at the correct location and balances as needed
*
************************************************************************/
template<typename T>
void AVLTree<T>::InsertAVL(TNode<T>*& root, T data, bool & taller)
{
	if (root == nullptr)
	{
		root = new TNode<T>(data);
		taller = true;
	}
	else if (data < root->GetData())
	{ //left subtree
		InsertAVL(root->GetLeft(), data, taller);
		if (taller)
		{
			switch (root->GetBalance())
			{
			case LH:
				LeftBalance(root);
				break;
			case EH:
				root->GetBalance() = LH;
				break;
			case RH:
				root->GetBalance() = EH;
				taller = false;
				break;
			}
		}
	}
	else
	{ //right subtree
		InsertAVL(root->GetRight(), data, taller);
		if (taller)
		{
			switch (root->GetBalance())
			{
			case LH:
				root->GetBalance() = EH;
				taller = false;
				break;
			case EH:
				root->GetBalance() = RH;
				break;
			case RH:
				RightBalance(root);
			}
		}
	}
}

/**********************************************************************
* Purpose: finds the node to delete and fixes the tree if needed
*
* Precondition:
* data - data to be deleted
*
* Postcondition:
* node is deleted and tree is fixed, throws an exception if tree is empty
*
************************************************************************/
template<typename T>
void AVLTree<T>::DeleteAVL(T data)
{
	TNode<T> * temp;
	TNode<T> * temp2;
	if (BinarySTree<T>::m_head == nullptr)
	{
		throw exception("Can't delete from empty tree");
	}
	if (BinarySTree<T>::m_head->GetData() == data)
	{
		if (BinarySTree<T>::m_head->GetLeft() != nullptr)
		{
			if (BinarySTree<T>::m_head->GetLeft()->GetRight() != nullptr)
			{
				temp2 = BinarySTree<T>::m_head->GetLeft();
				temp = BinarySTree<T>::m_head->GetLeft()->GetRight();
				while (temp->GetRight() != nullptr)
				{
					temp2 = temp;
					temp = temp->GetRight();
				}
				BinarySTree<T>::m_head->GetData() = temp->GetData();
				temp2->GetRight() = temp->GetLeft();
				delete temp;
			}
			else
			{
				temp = BinarySTree<T>::m_head->GetLeft();
				temp->GetRight() = BinarySTree<T>::m_head->GetRight();
				temp2 = BinarySTree<T>::m_head;
				BinarySTree<T>::m_head = temp;
				delete temp2;
			}
		}
		else
		{
			if (BinarySTree<T>::m_head->GetRight() != nullptr)
			{
				temp = BinarySTree<T>::m_head;
				BinarySTree<T>::m_head = BinarySTree<T>::m_head->GetRight();
				delete temp;
			}
			else
			{
				delete BinarySTree<T>::m_head;
				BinarySTree<T>::m_head = nullptr;
			}
		}
	}
	else
	{
		if (data < BinarySTree<T>::m_head->GetData())
		{
			DeleteAVL(BinarySTree<T>::m_head->GetLeft(), data);
		}
		else
		{
			DeleteAVL(BinarySTree<T>::m_head->GetRight(), data);
		}
	}
	VBalance(BinarySTree<T>::m_head);
}

/**********************************************************************
* Purpose: finds the node to delete and fixes the tree if needed
*
* Precondition:
* data - data to be deleted
* root - node currently being looked at
*
* Postcondition:
* node is deleted and tree is fixed, throws an exception if data is not found
*
************************************************************************/
template<typename T>
void AVLTree<T>::DeleteAVL(TNode<T>*& root, T data)
{
	TNode<T> * temp;
	TNode<T> * temp2;
	if (root == nullptr)
	{
		throw exception("Node Not Found");
	}
	if (root->GetData() == data)
	{
		if (root->GetLeft() != nullptr)
		{
			if (root->GetLeft()->GetRight() != nullptr)
			{
				temp2 = root->GetLeft();
				temp = root->GetLeft()->GetRight();
				while (temp->GetRight() != nullptr)
				{
					temp2 = temp;
					temp = temp->GetRight();
				}
				root->GetData() = temp->GetData();
				temp2->GetRight() = temp->GetLeft();
				delete temp;
			}
			else
			{
				temp = root->GetLeft();
				temp->GetRight() = root->GetRight();
				temp2 = root;
				root = temp;
				delete temp2;
			}
		}
		else
		{
			if (root->GetRight() != nullptr)
			{
				temp = root;
				root = root->GetRight();
				delete temp;
			}
			else
			{
				delete root;
				root = nullptr;
			}
		}
	}
	else
	{
		if (data < root->GetData())
		{
			DeleteAVL(root->GetLeft(), data);
		}
		else
		{
			DeleteAVL(root->GetRight(), data);
		}
	}
}

/**********************************************************************
* Purpose: finds the balance of the node by its children
*
* Precondition:
* root- node to be balance
*
* Postcondition:
* root is correctly balanced
*
************************************************************************/
template<typename T>
void AVLTree<T>::VBalance(TNode<T>*& root)
{
	int height;
	int rheight;
	int lheight;
	if (root != nullptr)
	{
		rheight = IBalance(root->GetRight()) + 1;
		lheight = IBalance(root->GetLeft()) + 1;
		height = lheight - rheight;
		if (height > 1)
		{
			LeftBalance(root);
			VBalance(root);
		}
		else if (height < -1)
		{
			RightBalance(root);
			VBalance(root);
		}
		else
		{
			root->GetBalance() = static_cast<Balance>(height);
		}
	}
}

/**********************************************************************
* Purpose: finds the balance of the node by its children and returns its height
*		   for its parent
*
* Precondition:
* root- node to be balance
*
* Postcondition:
* root is correctly balanced and its height it returned
*
************************************************************************/
template<typename T>
int AVLTree<T>::IBalance(TNode<T>*& root)
{
	int result;
	int rheight;
	int lheight;
	int height;
	if (root == nullptr)
	{
		result = 0;
	}
	else
	{
		rheight = IBalance(root->GetRight()) + 1;
		lheight = IBalance(root->GetLeft()) + 1;
		height = lheight - rheight;
		if (height > 1)
		{
			LeftBalance(root);
			height = IBalance(root);
			result = height;
		}
		else if (height < -1)
		{
			RightBalance(root);
			height = IBalance(root);
			result = height;
		}
		else
		{
			root->GetBalance() = static_cast<Balance>(height);
			if (lheight > rheight)
			{
				result = lheight;
			}
			else
			{
				result = rheight;
			}
		}
	}
	return result;
}

/**********************************************************************
* Purpose: Balances the left side of root
*
* Precondition:
* root- node to be balance
*
* Postcondition:
* root is rotated based on the needed rotations
*
************************************************************************/
template<typename T>
void AVLTree<T>::LeftBalance(TNode<T>*& root)
{
	if (root->GetLeft()->GetBalance() == LH)
	{
		LL(root);
	}
	else if(root->GetLeft()->GetBalance() == RH)
	{
		RR(root->GetLeft());
		LL(root);
	}
	VBalance(root);
}

/**********************************************************************
* Purpose: Balances the right side of root
*
* Precondition:
* root- node to be balance
*
* Postcondition:
* root is rotated based on the needed rotations
*
************************************************************************/
template<typename T>
void AVLTree<T>::RightBalance(TNode<T>*& root)
{
	if (root->GetRight()->GetBalance() == RH)
	{
		RR(root);
	}
	else if(root->GetRight()->GetBalance() == LH)
	{
		LL(root->GetRight());
		RR(root);
	}
	VBalance(root);
}

/**********************************************************************
* Purpose: performs an RR rotation
*
* Precondition:
* root- node to be balance
*
* Postcondition:
* root is rotated and changed
*
************************************************************************/
template<typename T>
inline void AVLTree<T>::RR(TNode<T>*& root)
{
	TNode<T> * temp = root->GetRight();
	root->GetRight() = temp->GetLeft();
	temp->GetLeft() = root;
	root = temp;
}

/**********************************************************************
* Purpose: performs an LL rotation
*
* Precondition:
* root- node to be balance
*
* Postcondition:
* root is rotated and changed
*
************************************************************************/
template<typename T>
void AVLTree<T>::LL(TNode<T>*& root)
{
	TNode<T> * temp = root->GetLeft();
	root->GetLeft() = temp->GetRight();
	temp->GetRight() = root;
	root = temp;
}

#endif