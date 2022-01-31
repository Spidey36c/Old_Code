#include <iostream>
#include <string>
#include <crtdbg.h>
#include "Exception.h"
#include "ListStack.h"
using std::cout;

typedef bool(*FunctionPointer)();

bool Test_Push();
bool Test_Pop();
bool Test_Pop_Empty();
bool Test_Peek();
bool Test_Peek_Empty();
bool Test_IsEmpty();


FunctionPointer test_functions[] = { Test_Push, Test_Pop, Test_Pop_Empty, 
Test_Peek, Test_Peek_Empty, Test_IsEmpty };



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	bool tests_passed = true;

	for (FunctionPointer func : test_functions)
	{
		if (func())
		{
			cout << "Passed!!\n";
		}
		else
		{
			tests_passed = false;
			cout << "***** Failed :( *****\n";
		}
	}

	tests_passed ? (cout << "\nAll Tests Passed! :) \n") : (cout << "\nAll Tests NOT Passed! :(\n");

	return 0;
}

bool Test_Push()
{
	bool pass = true;
	ListStack<int> test;

	test.Push(5);

	cout << "Push test: ";

	return pass;
}

bool Test_Pop()
{
	bool pass = true;
	int size = 10;
	int temp;
	ListStack<int> test;

	for (int i = 0; i < size; i++)
	{
		test.Push(i);
	}
	
	temp = test.Pop();

	if (temp != size - 1 || size - 1 != test.Size())
	{
		pass = false;
	}

	cout << "Pop test: ";

	return pass;
}

bool Test_Pop_Empty()
{
	bool pass = false;
	ListStack<int> test;

	try
	{
		test.Pop();
	}
	catch (Exception &e)
	{
		pass = true;
	}

	cout << "Pop test underflow: ";

	return pass;
}

bool Test_Peek()
{
	bool pass = true;
	int size = 10;
	int temp;
	ListStack<int> test;

	for (int i = 0; i < size; i++)
	{
		test.Push(i);
	}

	temp = test.Peek();

	if (temp != size - 1)
	{
		pass = false;
	}

	cout << "Peek test: ";

	return pass;
}

bool Test_Peek_Empty()
{
	bool pass = false;
	ListStack<int> test;

	try
	{
		test.Peek();
	}
	catch (Exception &e)
	{
		pass = true;
	}

	cout << "Peek test underflow: ";

	return pass;
}

bool Test_IsEmpty()
{
	ListStack<int> test;

	cout << "Is Empty test: ";

	return test.IsEmpty();
}
