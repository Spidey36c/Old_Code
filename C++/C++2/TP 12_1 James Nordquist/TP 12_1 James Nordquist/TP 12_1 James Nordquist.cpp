/****************************************************************
* Author:		James Nordquist
* Filename:		TP 12_1 James Nordquist
* Date Created:	4/23/18
* Modifications:
*
*****************************************************************/
/*************************************************************
*
* Assignment:	Team Programming Exercise 12_1
*
* Overview:
*	This program has us use a predifened function signature
*	to create a function that takes Cstring and tokenize with
*	delimiters entered by the user and put it into a 2d Ragged array
*
* Input:
*	Cstring and delimiters
* Output:
*	This program will output the number cstrings in the 2d
*	ragged array
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

int StrToArray(char **& str_array, char * str, char delimiter);
void AddString(char *** names, char buffer[], int *size);
void DeleteString(char ** dest, int size);

const int MAX_SIZE = 255;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	char ** str_array = nullptr;
	char str[MAX_SIZE];
	char delimiters = ' ';
	int size = 0;

	cout << "Enter a string: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(str, 255);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	size = StrToArray(str_array, str, delimiters);

	cout << "The size of the array is " << size << endl;

	DeleteString(str_array, size);

	return 0;
}

/**********************************************************
* Name: StrToArray
* Parameters: The pointer that will point to the array of
*					cStrings. By Ref.
*			  A Pointer to the string to be tokenized. By Val.
*			  A character that represents the delimiter
*
* Return: The number of cStrings in the array.
*
* Pre-Conditions: The pointer to the array wil be null.
*				  The cString will be null terminated;
*				  The delimiter will be  a valid character but
*						is not guaranteed to be in the cString.
*
* Post-Conditions: The pointer to the array will either be
*						a valid array or null if there were
*						no instances of the delimiter found
*				   If there aren't any instances of the 
*						delimiter found, the function will
*						return 0, otherwise the number of
*						cStrings in the array.
* 
* Purpose: This function creates a dynamic ragged array of
*		   strings as determined by the delimiter. For
*		   example, the cString "C++: Learn by Doing" will
*		   produce an array of four strings if the delimiter
*		   is a space.
***********************************************************/
int StrToArray(char **& str_array, char * str, char delimiter)
{
	int size = 0;
	char *tokenPtr;
	char *chkPtr;

	tokenPtr = strtok(str, &delimiter);
	chkPtr = strtok(nullptr, &delimiter);

	if (chkPtr != nullptr)
	{
		AddString(&str_array, tokenPtr, &size);
		AddString(&str_array, chkPtr, &size);
		while (tokenPtr != nullptr)
		{
			tokenPtr = strtok(nullptr, &delimiter);

			if (tokenPtr != nullptr)
			{
				AddString(&str_array, tokenPtr, &size);
			}
		}
	}
	else if (chkPtr == nullptr)
	{
		return 0;
	}

	return size;
}

/**********************************************************************
* Purpose: This function adds a string to names
*
* Precondition:
*     names - array where buffer is placed
*	  buffer - cString created before array was called and what is put into
*			   names
*	  size - the current size of names
*
* Postcondition:
*     makes names larger and puts buffer into a new spot in names
*
************************************************************************/
void AddString(char *** names, char buffer[], int *size)
{
	char ** temp = new char *[*size + 1];

	for (int ii = 0; ii < *size; ii++)
	{
		temp[ii] = (*names)[ii];
	}

	temp[*size] = new char[strlen(buffer) + 1];

	strcpy(temp[*size], buffer);

	delete[] * names;

	*names = temp;

	(*size)++;
}

/**********************************************************************
* Purpose: This function deletes dest
*
* Precondition:
*     dest - Array that was created before this function was called
*	  size - The size of the array used to avoid deleteing outside
*			 the array.
*
* Postcondition:
*     deletes dest and sets it to nullptr to avoid memory leaks
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