#include <iostream>
#include <string>
#include <crtdbg.h>
#include "Array.h"
#include "Exception.h"
#include "Stack.h"
using std::cout;

typedef bool(*FunctionPointer)();

bool Test_Push();
bool Test_Push_Full();
bool Test_Pop();
bool Test_Pop_Empty();
bool Test_Peek();
bool Test_Peek_Empty();
bool Test_IsEmpty();
bool Test_IsFull();
bool Test_SetSize();
bool Test_SetSize_Smaller();


FunctionPointer test_functions[] = { Test_Push, Test_Push_Full, Test_Pop,
Test_Pop_Empty, Test_Peek, Test_Peek_Empty,
Test_IsEmpty, Test_IsFull, Test_SetSize, Test_SetSize_Smaller };



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
	int size = 1;
	Stack<int> test(size);

	test.Push(5);

	if (size != test.Size())
	{
		pass = false;
	}

	cout << "Push test: ";

	return pass;
}

bool Test_Push_Full()
{
	bool pass = false;
	int size = 1;
	Stack<int> test(size);

	test.Push(5);

	try
	{
		test.Push(6);
	}
	catch (Exception &e)
	{
		pass = true;
	}

	cout << "Push test overflow: ";

	return pass;
}

bool Test_Pop()
{
	bool pass = true;
	int size = 5;
	int temp;
	Stack<int> test(size);

	for (int i = 0; i < size; i++)
	{
		test.Push(i);
	}
	
	temp = test.Pop();

	if (temp != 4 || size - 1 != test.Size())
	{
		pass = false;
	}

	cout << "Pop test: ";

	return pass;
}

bool Test_Pop_Empty()
{
	bool pass = false;
	Stack<int> test;

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
	int size = 5;
	int temp;
	Stack<int> test(size);

	for (int i = 0; i < size; i++)
	{
		test.Push(i);
	}

	temp = test.Peek();

	if (temp != 4)
	{
		pass = false;
	}

	cout << "Peek test: ";

	return pass;
}

bool Test_Peek_Empty()
{
	bool pass = false;
	Stack<int> test;

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
	Stack<int> test;

	cout << "Is Empty test: ";

	return test.IsEmpty();
}

bool Test_IsFull()
{
	int size = 5;
	Stack<int> test(size);

	for (int i = 0; i < size; i++)
	{
		test.Push(i);
	}

	cout << "Is Full test: ";

	return test.IsFull();
}

bool Test_SetSize()
{
	bool pass = false;
	int size = 5;
	Stack<int> test(size);

	for (int i = 0; i < size; i++)
	{
		test.Push(i);
	}
	
	test.SetSize(size * 2);

	for (int i = 0; i < 5; i++)
	{
		test.Push(i);
	}

	try 
	{
		test.Push(10);
	}
	catch (Exception &e)
	{
		pass = true;
	}

	cout << "Set Size larger test: ";

	return pass;
}

bool Test_SetSize_Smaller()
{
	bool pass = false;
	int size = 5;
	int new_size = 2;
	Stack<int> test(size);

	for (int i = 0; i < size; i++)
	{
		test.Push(i);
	}

	test.SetSize(new_size);

	try
	{
		test.Push(3);
	}
	catch (Exception &e)
	{
		pass = true;
	}

	cout << "Set Size smaller test: ";

	return pass;
}
