/****************************************************************
* Author:		James Nordquist
* Filename:		PE 12_3 James Nordquist
* Date Created:	4/18/18
* Modifications:	
*
*****************************************************************/
/*************************************************************
*
* Assignment:  Programming Excercises 12_3
*
* Overview:
*	This program tracks stocks entered by the user and allows
*	the user to edit the price of the stock or delete the stock
*	and display all the stocks entered
*
* Input:
*	Stock names and stock prices.
* Output:
*	This program will output the stock names and stock prices
*
************************************************************/
#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <crtdbg.h>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::right;
using std::left;
using std::fixed;
using std::setprecision;

const int MAX_SIZE = 255;

void AddStock(char *** names, char buffer[], double price[], int *num_names);
void EditStock(char ***names, double price[], char buffer[], int *num_names);
int Index(char **names, int num_names, const char * str);
void DeleteString(char ** dest, int size);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int num_names = 0;
	char ** names = nullptr;
	char * str = nullptr;
	char ** temp = nullptr;
	double price[MAX_SIZE] = { 0 };
	char buffer[256] = { " " };
	int selection;
	
	names = new char * [num_names];

	for (int ii = 0; ii < num_names; ii++)
	{
		str = new char[strlen(buffer) + 1];
		strcpy(str, buffer);

		names[ii] = str;
	}

	cout << "1) Add a new stock" << endl;
	cout << "2) Edit a stock" << endl;
	cout << "3) Delete a stock" << endl;
	cout << "4) Display all stocks" << endl;
	cout << "5) Exit" << endl;
	cout << "> ";
	cin >> selection;
	while (selection < 1 || selection >5)
	{
		cout << "Invalid selection try again" << endl;
		cout << "1) Add a new stock" << endl;
		cout << "2) Edit a stock" << endl;
		cout << "3) Delete a stock" << endl;
		cout << "4) Display all stocks" << endl;
		cout << "5) Exit" << endl;
		cout << "> ";
		cin >> selection;
	}
	while (selection != 5)
	{
		if (selection == 1)
		{
			AddStock(&names, buffer, price, &num_names);
		}
		else if (selection == 2)
		{

		}
		else if (selection == 3)
		{

		}
		else if (selection == 4)
		{

		}
		cout << "1) Add a new stock" << endl;
		cout << "2) Edit a stock" << endl;
		cout << "3) Delete a stock" << endl;
		cout << "4) Display all stocks" << endl;
		cout << "5) Exit" << endl;
		cout << "> ";
		cin >> selection;
	}
	if (selection == 5)
	{
		cout << endl << "Stocks" << setw(19) << right << "Price" << endl << endl;

		for (int ii = 0; ii < num_names; ii++)
		{
			cout << setw(8) << left << names[ii] << setw(13) << right << "$" << fixed << setprecision(2) << price[ii] << endl;
		}
	}

	DeleteString(names, num_names);

	return 0;
}

void AddStock(char *** names, char buffer[], double price[], int *num_names)
{
	char ** temp = new char *[*num_names + 1];

	for (int ii = 0; ii < *num_names; ii++)
	{
		temp[ii] = (*names)[ii];
	}

	cout << "Enter name: ";
	cin >> buffer;

	temp[*num_names] = new char[strlen(buffer) + 1];

	strcpy(temp[*num_names], buffer);

	delete[] *names;

	*names = temp;

	cout << "Enter Stock price: ";
	cin >> price[*num_names];

	(*num_names)++;
}

void EditStock(char ***names, double price[], char buffer[], int *num_names)
{
	int found = 0;
	cout << "What do you want to find: " << endl;
	cin >> buffer;

	found = Index(*names, *num_names, buffer);
	if (found == -1)
	{
		cout << "String was not found" << endl;
	}
	else
	{
		cout << "String was found!" << endl;
		cout << "What is the price: ";
		cin >> price[found];
	}
}

int Index(char **names, int num_names,const char * str)
{
	int index = -1;
	int count = 0;
	
	while ((count < num_names) && (index == -1))
	{
		if (stricmp(names[count], str) != 0)
		{
			count++;
		}
		else
		{
			index = count;
		}
	}
	return index;
}

/**********************************************************************
* Purpose: This function deletes 2d dynamic arrays to avoid memory leaks
*
* Precondition:
*     dest - The 2d dynamic array made in main
*	  size - The size of the array to avoid deleting outside of the array
*
* Postcondition:
*     deletes dest and changes it to nullptr and makes size 0
*
************************************************************************/
void DeleteString(char ** dest, int size)
{
	for (int ii = 0; ii < size; ii++)
	{
		delete[] dest[ii];
	}

	delete[] dest;

	dest = nullptr;
}