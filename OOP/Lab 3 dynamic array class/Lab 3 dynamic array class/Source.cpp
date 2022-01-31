/*************************************************************
* Author: James Nordquist
* Filename: Source.cpp
* Date Created: 10/16/18
* Modifications: 10/18/18 - testing exceptions
*************************************************************/
#include <iostream>
#include <new>
#include "DynamicArray.h"
using std::cout;
using std::cin;
using std::endl; 
using std::bad_alloc;
#include <crtdbg.h>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	DynamicArray test1;
	try
	{
		const int SIZE = 800000;

		char buffer[SIZE] = { "Potion of strength" }; // can be used to change strings if strings are still null
		String test2 = "Potion of health";
		String test3 = "Heals you";
		String test4 = "medium";
		String test5 = "0.0.25.68";

		Potion test6 = { test2,test3,test4,test5 };
		Potion test7(test6);

		test1.Insert(test6);
		test1.Insert(test7);

		Potion test8 = test1.getData();
		int elements = test1.GetElements();
		Potion *test9 = test1.getArray();

		test9->displayTotalCost(test9, elements);
		DynamicArray test10 = test1;
		test1.Delete(test6);
	}
	catch (bad_alloc excpt)
	{
		cout << "Exception: " << excpt.what();
		abort();
	}
	catch (int excpt)
	{
		if (excpt == -1)
		{
			cout << "Strings are still nullptr" << endl;
		}
		abort();
	}

	return 0;
}