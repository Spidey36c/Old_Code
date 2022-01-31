#include <iostream>
#include <crtdbg.h>
#include "Vertice.h"
#include "Graph.h"
#include "Edge.h"
using std::cout;
using std::endl;

typedef bool(*FunctionPointer)();

void Display(int data);
bool Test_InsertVertice();
bool Test_DeleteVertice();
bool Test_InsertEdge();
bool Test_DeleteEdge();
bool Test_DeleteVertice_NonExistant();
bool Test_DeleteVertice_MiddleVertex();
bool Test_DepthFirst();
bool Test_BreadthFirst();

FunctionPointer test_functions[] = { Test_InsertVertice, Test_DeleteVertice, Test_InsertEdge,
Test_DeleteEdge, Test_DeleteVertice_NonExistant, Test_DeleteVertice_MiddleVertex,
Test_DepthFirst, Test_BreadthFirst
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// Run the test functions
	for (FunctionPointer func : test_functions)
	{
		if (func())
		{
			cout << "passed\n";
		}
		else
		{
			cout << "***** failed *****\n";
		}
	}

	return 0;
}

void Display(int data)
{
	cout << data << endl;
}

bool Test_InsertVertice()
{
	Graph<int, int> test;
	test.InsertVertex(8);
	test.BreadthFirst(Display);
	return true;
}

bool Test_DeleteVertice()
{
	bool result = false;
	Graph<int, int> test;
	test.InsertVertex(8);
	test.DeleteVertex(8);
	if (test.IsEmpty() == true)
	{
		result = true;
	}
	return result;
}

bool Test_InsertEdge()
{
	Graph<int, int> test;
	test.InsertVertex(8);
	test.InsertVertex(9);
	test.InsertEdge(8, 5, 9);
	return true;
}

bool Test_DeleteEdge()
{
	Graph<int, int> test;
	test.InsertVertex(8);
	test.InsertVertex(9);
	test.InsertEdge(8, 5, 9);
	test.DeleteEdge(8, 5, 9);
	return true;
}

bool Test_DeleteVertice_NonExistant()
{
	bool result = false;
	Graph<int, int> test;
	try
	{
		test.DeleteVertex(9);
	}
	catch (exception &e)
	{
		result = true;
	}
	return result;
}

bool Test_DeleteVertice_MiddleVertex()
{
	Graph<int, int> test;
	test.InsertVertex(5);
	test.InsertVertex(7);
	test.InsertVertex(9);
	test.InsertEdge(5, 6, 7);
	test.InsertEdge(7, 8, 9);
	test.DeleteVertex(7);
	return true;
}

bool Test_DepthFirst()
{
	Graph<int, int> test;
	test.InsertVertex(1);
	test.InsertVertex(2);
	test.InsertVertex(3);
	test.InsertVertex(4);
	test.InsertEdge(1, 5, 2);
	test.InsertEdge(2, 6, 3);
	test.InsertEdge(2, 7, 4);
	test.DepthFirst(Display);
	return true;
}

bool Test_BreadthFirst()
{
	Graph<int, int> test;
	test.InsertVertex(1);
	test.InsertVertex(2);
	test.InsertVertex(3);
	test.InsertVertex(4);
	test.InsertEdge(1, 5, 2);
	test.InsertEdge(2, 6, 3);
	test.InsertEdge(2, 7, 4);
	test.BreadthFirst(Display);
	return true;
}
