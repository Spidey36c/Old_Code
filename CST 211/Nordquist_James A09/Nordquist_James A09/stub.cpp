#include <iostream>
#include <exception>
#include "BinarySTree.h"
using std::cout;
using std::endl;
using std::exception;

typedef bool(*FunctionPointer)();

bool Test_Insert();
bool Test_Delete();
bool Test_DeleteEmpty();
bool Test_Height();
bool Test_HeightEmpty();
bool Test_Purge();
bool Test_BreadthFirst();
bool Test_InOrder();
bool Test_PostOrder();
bool Test_PreOrder();
void Display(int data);

FunctionPointer test_functions[] = { Test_Insert, Test_Delete, Test_DeleteEmpty,
Test_Height,Test_HeightEmpty, Test_Purge,
Test_BreadthFirst,Test_InOrder, Test_PostOrder, 
Test_PreOrder
};

int main()
{
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

bool Test_Insert()
{
	BinarySTree<int> test;
	int temp[10] = {5,2,7,3,1,8,9,4,6,0};
	for (int i = 0; i < 10; i++)
	{
		test.Insert(temp[i]);
	}

	test.InOrder(Display);

	cout << endl;

	return true;
}

bool Test_Delete()
{
	BinarySTree<int> test;
	int temp[10] = { 5,2,7,3,1,8,9,4,6,0 };
	for (int i = 0; i < 10; i++)
	{
		test.Insert(temp[i]);
	}

	test.InOrder(Display);

	cout << endl;

	test.DeleteFind(3);

	test.InOrder(Display);

	cout << endl;

	return true;
}

bool Test_DeleteEmpty()
{
	bool result = false;
	BinarySTree<int> test;

	try
	{
		test.DeleteFind(10);
	}
	catch (exception &e)
	{
		result = true;
	}

	return result;
}

bool Test_Height()
{
	bool result = false;
	BinarySTree<int> test;
	int temp[10] = { 5,2,7,3,1,8,9,4,6,0 };
	for (int i = 0; i < 10; i++)
	{
		test.Insert(temp[i]);
	}

	if (test.Height() == 3)
	{
		result = true;
	}

	return result;
}

bool Test_HeightEmpty()
{
	bool result = false;
	BinarySTree<int> test;

	if (test.Height() == 0)
	{
		result = true;
	}

	return result;
}

bool Test_Purge()
{
	bool result = false;
	BinarySTree<int> test;
	int temp[10] = { 5,2,7,3,1,8,9,4,6,0 };

	for (int i = 0; i < 10; i++)
	{
		test.Insert(temp[i]);
	}

	test.Purge();

	if (test.Height() == 0)
	{
		result = true;
	}

	return result;
}

bool Test_BreadthFirst()
{
	BinarySTree<int> test;
	int temp[10] = { 5,2,7,3,1,8,9,4,6,0 };
	for (int i = 0; i < 10; i++)
	{
		test.Insert(temp[i]);
	}

	test.BreadthFirst(Display);

	cout << endl;

	return true;
}

bool Test_InOrder()
{
	BinarySTree<int> test;
	int temp[10] = { 5,2,7,3,1,8,9,4,6,0 };
	for (int i = 0; i < 10; i++)
	{
		test.Insert(temp[i]);
	}

	test.InOrder(Display);

	cout << endl;

	return true;
}

bool Test_PostOrder()
{
	BinarySTree<int> test;
	int temp[10] = { 5,2,7,3,1,8,9,4,6,0 };
	for (int i = 0; i < 10; i++)
	{
		test.Insert(temp[i]);
	}

	test.PostOrder(Display);

	cout << endl;

	return true;
}

bool Test_PreOrder()
{
	BinarySTree<int> test;
	int temp[10] = { 5,2,7,3,1,8,9,4,6,0 };
	for (int i = 0; i < 10; i++)
	{
		test.Insert(temp[i]);
	}

	test.PreOrder(Display);

	cout << endl;

	return true;
}

void Display(int data)
{
	cout << data << " ";
}
