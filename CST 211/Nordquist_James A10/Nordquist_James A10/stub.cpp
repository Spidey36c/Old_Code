#include <iostream>
#include "AbstractIter.h"
#include "ForwardIter.h"
#include "BackwardIter.h"
#include "List.h"
#include "Node.h"
#include "ListIter.h"
using std::cout;
using std::endl;

typedef bool(*FunctionPointer)();

bool Test_ForwardIter();

FunctionPointer test_functions[] = { Test_ForwardIter

};

int main()
{
	bool tests_passed;

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
