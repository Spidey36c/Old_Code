/*************************************************************
* Author: James Nordquist
* Filename: stub.cpp
* Date Created: 3/12/19
* Modifications: 3/13/19 - add testing for op = and delete
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Lab 6 – Hash Table
*
* Overview:
* This program is an application of a Hash Table
*
* Input:
* N/A
*
* Output:
* The output of this program will be the data stored in the Hash Table
* and whether an exception was caught
*
************************************************************/
#include <iostream>
#include <string>
#include <exception>
#include "HashNode.h"
#include "HashTable.h"
using std::string;
using std::exception;
using std::cout;
using std::endl;
using std::stoi;

struct Book
{
	string m_title;
	string m_author;
	int m_pages;
};

/**********************************************************************
* Purpose: Hashing function for strings
*
* Precondition:
* key - string, assumed to hold integers in a string
*
* Postcondition:
* returns the index where the key can be inserted
*
************************************************************************/
int AsciiHash(string key);

int main()
{
	HashTable<Book,string> table(10);
	HashTable<Book, string> copy(10);

	table.setHash(AsciiHash);

	Book temp = { "C++: An Active Learning Approach", "Randal Albert", 635 };
	table.Insert("0763757233", temp);

	Book temp1 = { "Rodeo for Dummies", "Calvin Caldwell", 1 };
	table.Insert("7063757233", temp1);

	Book temp3 = { "And That n There", "Ralph Carestia", 1 };
	table.Insert("7063757234", temp3);

	cout << table["0763757233"].m_title << endl;
	cout << table["7063757233"].m_title << endl;
	cout << table["7063757234"].m_title << endl;

	copy = table;

	table.Delete("0763757233");

	cout << copy["0763757233"].m_title << endl;

	try
	{
		cout << table["0763757233"].m_title << endl;
	}
	catch (exception &e)
	{
		cout << "exception caught" << endl;
	}

	return 0;
}

int AsciiHash(string key)
{
	int ikey = 0;
	string temp;
	for (int i = 0; i < key.size(); i++)
	{
		temp = key[i];
		ikey += stoi(temp);
	}
	ikey = ikey % 10;
	return ikey;
}
