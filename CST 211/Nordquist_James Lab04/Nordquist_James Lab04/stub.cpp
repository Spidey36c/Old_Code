/*************************************************************
* Author: James Nordquist
* Filename: stub.cpp
* Date Created: 2/22/19
* Modifications:
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Lab 4 – AVL
*
* Overview:
* This program is an application of an AVL tree data structure
*
* Input:
* The input is integers inserted into the avl tree in the test functions
*
* Output:
* The output of this program will be the data in the tree and whether
* or not the test passed
*
************************************************************/
#include <iostream>
#include <exception>
#include <crtdbg.h>
#include "AVLTree.H"
using std::cout;
using std::endl;
using std::exception;

typedef bool(*FunctionPointer)();

bool Test_Insert();
bool Test_Delete();
bool Test_DeleteEmpty();
bool Test_OpEq();
bool Test_CopyCtor();
void Display(int data);

FunctionPointer test_functions[] = { Test_Insert , Test_Delete, Test_DeleteEmpty,
Test_OpEq, Test_CopyCtor
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	bool tests_passed = true;

	// Run the test functions
	for (FunctionPointer func : test_functions)
	{
		if (func())
		{
			cout << "passed\n";
		}
		else
		{
			tests_passed = false;
			cout << "***** failed *****\n";
		}
	}

	if (tests_passed)
	{
		cout << "All tests passed" << endl;
	}
	else
	{
		cout << "Some test failed" << endl;
	}

	return 0;
}

/**********************************************************************
* Purpose: testing insert for avl tree
*
* Precondition:
*
* Postcondition:
* inserts data into the avltree using the temp array outputs the data inorder in the tree
*
************************************************************************/
bool Test_Insert()
{
	AVLTree<int> test;
	int temp[11] = { 8,9,10,2,1,5,3,6,4,7,11 };
	for (int i = 0; i < 11; i++)
	{
		test.InsertAVL(temp[i]);
	}

	test.InOrder(Display);

	cout << endl;

	return true;
}

/**********************************************************************
* Purpose: testing delete for avl tree
*
* Precondition:
*
* Postcondition:
* inserts data into the avltree using the temp array, output inorder,
* then delete a node, and then output inorder again
*
************************************************************************/
bool Test_Delete()
{
	AVLTree<int> test;
	int temp[11] = { 8,9,10,2,1,5,3,6,4,7,11 };
	for (int i = 0; i < 11; i++)
	{
		test.InsertAVL(temp[i]);
	}

	test.InOrder(Display);

	cout << endl;

	test.DeleteAVL(5);

	test.InOrder(Display);

	cout << endl;

	return true;
}

/**********************************************************************
* Purpose: testing delete empty for avl tree
*
* Precondition:
*
* Postcondition:
* create an avltree with no nodes and call delete function
*
************************************************************************/
bool Test_DeleteEmpty()
{
	bool result = false;
	AVLTree<int> test;

	try
	{
		test.DeleteAVL(10);
	}
	catch (exception &e)
	{
		result = true;
	}

	return result;
}

/**********************************************************************
* Purpose: testing op =
*
* Precondition:
*
* Postcondition:
* inserts data into the first tree and have the second tree set equal to 
* the first and output boths data
*
************************************************************************/
bool Test_OpEq()
{
	AVLTree<int> test;
	AVLTree<int> test2;
	int temp[11] = { 8,9,10,2,1,5,3,6,4,7,11 };
	for (int i = 0; i < 11; i++)
	{
		test.InsertAVL(temp[i]);
	}

	test.InOrder(Display);

	cout << endl;

	test2 = test;

	test2.InOrder(Display);

	cout << endl;

	return true;
}

/**********************************************************************
* Purpose: testing copy ctor
*
* Precondition:
*
* Postcondition:
* inserts data into the first tree and have the second tree be initialzed to
* the first and output boths data
*
************************************************************************/
bool Test_CopyCtor()
{
	AVLTree<int> test;
	int temp[11] = { 8,9,10,2,1,5,3,6,4,7,11 };
	for (int i = 0; i < 11; i++)
	{
		test.InsertAVL(temp[i]);
	}

	AVLTree<int> test2(test);

	test.InOrder(Display);

	cout << endl;

	test2.InOrder(Display);

	cout << endl;
	return true;
}

/**********************************************************************
* Purpose: used for inorder
*
* Precondition:
*
* Postcondition:
* outputs data
*
************************************************************************/
void Display(int data)
{
	cout << data << " ";
}
