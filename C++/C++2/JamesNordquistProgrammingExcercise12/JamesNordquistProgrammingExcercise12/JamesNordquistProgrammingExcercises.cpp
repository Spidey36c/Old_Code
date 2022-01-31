/****************************************************************
* Author:		James Nordquist
* Filename:		JamesNordquistProgrammingExcercise12
* Date Created:	4/5/18
* Modifications:	4/13/18 - Invalid selections now output the
*							  the menu again and ask for another
*							  input
*****************************************************************/
/*************************************************************
*
* Assignment:  Programming Excercises 12
*
* Overview:
*	This program has us create a menu of string functions 
*	using pointer notation and not array notation or any 
*	predefined string functions.
*
* Input:
*	There is a input for two Cstrings and a selection input.
*
* Output:
*	This program will output the string with the changes
*	after the user has exited the menu and after any changes
************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <crtdbg.h>

void GetString(char * dest);
void StrCpy(char * dest, char * src);
void DeleteString(char * str, int start, int num_char);
char *StrCat(char * dest, char * src);
int StrLen(char * dest);
bool StrStr(char * dest, char * src);
char *StrRev(char * dest);
bool StriCmp(char * dest, char * src);
void InsertString(char * dest, int start, char * src);
int Index(char * dest, char * src);
void CreateSub(char * dest, int start, int num_char);

using std::cout;
using std::cin;
using std::endl;

const int MAX_NAME_SIZE = 255;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	char string[MAX_NAME_SIZE] = "\0";
	char string2[MAX_NAME_SIZE];
	int selection;
	int count;
	int num_char;
	
	cout << "What do you want to do?" << endl;
	cout << "1) Get a cString" << endl;
	cout << "2) Copy one cString into another(strcpy)" << endl;
	cout << "3) Concatenate one cString onto the Original cString(strcat)" << endl;
	cout << "4) Finds the length of a cString(strlen)" << endl;
	cout << "5) Finds the substring in a cString(strstr)" << endl;
	cout << "6) Reverse a cString(strrev)" << endl;
	cout << "7) Case insensitive cString compare(stricmp)" << endl;
	cout << "8) Delete a Portion of the cString" << endl;
	cout << "9) Insert another cString into the First cString" << endl;
	cout << "10) Create a substring" << endl;
	cout << "11) Find Index of Sub - String" << endl;
	cout << "12) Exit" << endl;
	cout << "> ";
	cin >> selection;

	while (selection < 1 || selection > 12)
	{
		cout << "Invalid Selection" << endl;
		cout << "What do you want to do?" << endl;
		cout << "1) Get a cString" << endl;
		cout << "2) Copy one cString into another(strcpy)" << endl;
		cout << "3) Concatenate one cString onto the Original cString(strcat)" << endl;
		cout << "4) Finds the length of a cString(strlen)" << endl;
		cout << "5) Finds the substring in a cString(strstr)" << endl;
		cout << "6) Reverse a cString(strrev)" << endl;
		cout << "7) Case insensitive cString compare(stricmp)" << endl;
		cout << "8) Delete a Portion of the cString" << endl;
		cout << "9) Insert another cString into the First cString" << endl;
		cout << "10) Create a substring" << endl;
		cout << "11) Find Index of Sub - String" << endl;
		cout << "12) Exit" << endl;
		cout << "> ";
		cin >> selection;
	}

	while (selection < 12 && selection >= 1)
	{
		switch (selection)
		{
		case 1:
			cout << "Enter what you want the string to hold: ";
			GetString(string);

			cout << "You entered (" << string << ")" << endl << endl;
			break;

		case 2:
			cout << "Enter what you want to copy into the string: ";
			GetString(string2);

			cout << "You entered (" << string2 << ")" << endl;
			cout << "You changed (" << string << ")";
			StrCpy(string, string2);
			cout << " to (" << string << ")" << endl << endl;
			break;

		case 3:
			cout << "Enter what you want to put at the end of the string: ";
			GetString(string2);

			cout << "You entered (" << string2 << ")" << endl;
			cout << "You changed (" << string << ")";
			*string = *StrCat(string, string2);
			cout << " to (" << string << ")" << endl << endl;
			break;

		case 4:
			cout << "The length of the string currently is ";
			count = StrLen(string);
			cout << count << endl << endl;
			break;

		case 5:
			cout << "Enter what you want to find in the string: ";
			GetString(string2);

			cout << "You entered (" << string2 << ")" << endl;

			if (StrStr(string, string2) == true)
			{
				cout << "(" << string2 << ") does exist in (" << string << ")" << endl << endl;
			}
			else
			{
				cout << "(" << string2 << ") does not exist in (" << string << ")" << endl << endl;
			}
			break;

		case 6:
			cout << "Changed (" << string << ") to (";
			*string = *StrRev(string);
			cout << string << ")" << endl << endl;

			break;
		case 7:
			cout << "Enter what you want to compare to the string: ";
			GetString(string2);

			cout << "(" << string2 << ") is ";
			if (StriCmp(string, string2) == true)
			{
				cout << "equal to (" << string << ")" << endl;
			}
			else
			{
				cout << "not equal to (" << string << ")" << endl << endl;
			}

			break;
		case 8:
			cout << "Enter where you want to start deleting charecters: ";
			cin >> count;
			cout << "Enter how many characters you want to delete: ";
			cin >> num_char;

			DeleteString(string, count, num_char);

			cout << "The string is now (" << string << ")" << endl << endl;

			break;
		case 9:
			cout << "Enter where you want to insert a string: ";
			cin >> count;

			cout << "Enter what you want to insert: ";
			GetString(string2);

			cout << "(" << string << ") changed to (";
			InsertString(string, count, string2);
			cout << string << ")" << endl << endl;

			break;
		case 10:
			cout << "Enter where you want to create the sub-string: ";
			cin >> count;

			cout << "Enter how many characters you want to have in the substring: ";
			cin >> num_char;

			cout << "(" << string << ") changed to (";
			CreateSub(string, count, num_char);
			cout << string << ")" << endl << endl;

			break;
		case 11:
			cout << "What sub-string do you want to find the index of? ";
			GetString(string2);

			cout << "The sub-string of (" << string2 << ") is found at ";
			count = Index(string, string2);
			cout << count << endl << endl;

			break;
		}

		cout << "What do you want to do?" << endl;
		cout << "1) Get a cString" << endl;
		cout << "2) Copy one cString into another(strcpy)" << endl;
		cout << "3) Concatenate one cString onto the Original cString(strcat)" << endl;
		cout << "4) Finds the length of a cString(strlen)" << endl;
		cout << "5) Finds the substring in a cString(strstr)" << endl;
		cout << "6) Reverse a cString(strrev)" << endl;
		cout << "7) Case insensitive cString compare(stricmp)" << endl;
		cout << "8) Delete a Portion of the cString" << endl;
		cout << "9) Insert another cString into the First cString" << endl;
		cout << "10) Create a substring" << endl;
		cout << "11) Find Index of Sub - String" << endl;
		cout << "12) Exit" << endl;
		cout << "> ";
		cin >> selection;

		while (selection < 1 || selection > 12)
		{
			cout << "Invalid Selection" << endl;
			cout << "What do you want to do?" << endl;
			cout << "1) Get a cString" << endl;
			cout << "2) Copy one cString into another(strcpy)" << endl;
			cout << "3) Concatenate one cString onto the Original cString(strcat)" << endl;
			cout << "4) Finds the length of a cString(strlen)" << endl;
			cout << "5) Finds the substring in a cString(strstr)" << endl;
			cout << "6) Reverse a cString(strrev)" << endl;
			cout << "7) Case insensitive cString compare(stricmp)" << endl;
			cout << "8) Delete a Portion of the cString" << endl;
			cout << "9) Insert another cString into the First cString" << endl;
			cout << "10) Create a substring" << endl;
			cout << "11) Find Index of Sub - String" << endl;
			cout << "12) Exit" << endl;
			cout << "> ";
			cin >> selection;
		}
	}
	
	if (selection == 12)
	{
		cout << "The end result of the changes is " << string << endl;
		cout << "Goodbye" << endl;
	}

	return 0;
}

/**********************************************************************
* Purpose: This function gets a string from user input, this is to reduce
*		   redundant code.
*
* Precondition:
*     dest - Either an empty string, or a string with characters
*			 if the user chose menu option 1
*
* Postcondition:
*     Modifies dest by placing whatever string the user entered into it
*
************************************************************************/
void GetString(char * dest)
{
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(dest, MAX_NAME_SIZE);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
}

/**********************************************************************
* Purpose: This function imitates the string function strcpy with pointers
*
* Precondition:
*     dest - Either an empty string, or a string with characters
*			 if the user chose menu option 1
*	  src  - A string created and filled by the user once they 
*			 choose this menu option 
*
* Postcondition:
*     Modifies dest by replacing it with src
*
************************************************************************/
void StrCpy(char * dest, char * src)
{
	while (*dest++ = *src++);
}

/**********************************************************************
* Purpose: This function deletes a certain number of characters stated
*		   by the user
*
* Precondition:
*     dest - Either an empty string, or a string with characters
*			 if the user chose menu option 1
*	  start - An integer stated by the user to choose when to start
*			  deleting characters
*	  num_char - An integer stated by the user of how many characters
*				 to delete
*
* Postcondition:
*     Modifies dest by deleting characters
*
************************************************************************/
void DeleteString(char * str, int start, int num_char)
{
	StrCpy(str + start, str + start + num_char);
}

/**********************************************************************
* Purpose: This function imitates the string function strcayt with pointers
*
* Precondition:
*     dest - Either an empty string, or a string with characters
*			 if the user chose menu option 1
*	  src  - A string created and filled by the user once they
*			 choose this menu option
*
* Postcondition:
*     Modifies dest by appending src to the end of dest
*
************************************************************************/
char *StrCat(char *dest, char *src)
{
	char *return_val = dest;

	while (*dest != 0)
	{
		dest++;
	}

	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return return_val;
}

/**********************************************************************
* Purpose: This function imitates the string function strlen with pointers
*
* Precondition:
*     dest - Either an empty string, or a string with characters
*			 if the user chose menu option 1
*
* Postcondition:
*     Returns the length of the string as count
*
************************************************************************/
int StrLen(char *dest)
{
	int count = 0;

	while (*dest != 0)
	{
		dest++;
		count++;
	}
	
	return count;
}

/**********************************************************************
* Purpose: This function imitates the string function strstr with pointers
*
* Precondition:
*     dest - Either an empty string, or a string with characters
*			 if the user chose menu option 1
*	  src  - A string created and filled by the user once they
*			 choose this menu option
*
* Postcondition:
*     States whether or not string src can be found in string dest
*	  by using true or false, true being src exists in dest, false
*	  being src does not exist in dest
*
************************************************************************/
bool StrStr(char *dest, char *src)
{
	int count = 0;
	char *temp = src;
	int length = StrLen(temp);

	while (*dest != 0)
	{
		if (*dest == *src)
		{
			while (*dest == *src && *src != 0)
			{
				count++;
				dest++;
				src++;
			}

			if (count == length)
			{
				return true;
			}
			else
			{
				count = 0;
				src = temp;
			}
		}
		dest++;
	}

	return false;
}

/**********************************************************************
* Purpose: This function imitates the string function strrev with pointers
*
* Precondition:
*     dest - Either an empty string, or a string with characters
*			 if the user chose menu option 1
*
* Postcondition:
*     Modifies dest by reversing the characters in it 
*	  ex. Hello becomes olleH
*
************************************************************************/
char *StrRev(char * dest)
{
	char *return_val = dest;
	char name[MAX_NAME_SIZE];
	int length = StrLen(dest);
	int count = 0;

	for (int ii = length-1; ii >= 0; ii--)
	{
		name[count] = dest[ii];
		count++;
	}
	name[count] = '\0';

	for (int ii = 0; ii < length; ii++)
	{
		*dest = name[ii];
		dest++;
	}

	return return_val;
}

/**********************************************************************
* Purpose: This function imitates the string function stricmp with pointers
*
* Precondition:
*     dest - Either an empty string, or a string with characters
*			 if the user chose menu option 1
*	  src  - A string created and filled by the user once they
*			 choose this menu option
*
* Postcondition:
*     States whether dest and src are the same by returning true or false
*
************************************************************************/
bool StriCmp(char * dest, char * src)
{
	int count1;
	int count2;
	char name1[MAX_NAME_SIZE];
	char name2[MAX_NAME_SIZE];
	int equals = 0;

	count1 = StrLen(dest);
	count2 = StrLen(src);

	for (int ii = 0; ii < count1+1; ii++)
	{
		name1[ii] = *dest;
		dest++;
	}

	for (int ii = 0; ii < count2+1; ii++)
	{
		name2[ii] = *src;
		src++;
	}

	if (count1 == count2)
	{
		for (int count = 0; count < count2; count++)
		{
			if (name1[count] >= 97 && name1[count] <= 122)
			{
				name1[count] -= 32;
			}
		}

		for (int count = 0; count < count2; count++)
		{
			if (name2[count] >= 97 && name2[count] <= 122)
			{
				name2[count] -= 32;
			}
		}

		while (name1[equals] == name2[equals] && name1[equals] !=0)
		{
			equals++;
		}

		if (equals == count2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

/**********************************************************************
* Purpose: This function Inserts string src into string dest starting
*		   at a point in string dest indicated by the user
*
* Precondition:
*     dest - Either an empty string, or a string with characters
*			 if the user chose menu option 1
*	  start - An integer stated by the user to indicate when to start 
*	  insterting src
*	  src  - A string created and filled by the user once they
*			 choose this menu option
*
* Postcondition:
*     Modifies dest by placing string src in it.
*
************************************************************************/
void InsertString(char * dest, int start, char * src)

{
	char name[MAX_NAME_SIZE];
	int count = StrLen(dest);
	int count2 = StrLen(src);

	for (int ii = 0; ii < count + 1; ii++)
	{
		name[ii] = *dest;
		dest++;
	}
	dest -= count + 1;
	if (count != 0)
	{
		dest += start;

		while (*src != 0)
		{
			*dest = *src;
			dest++;
			src++;
		}
	}
	else
	{
		while (*src != 0)
		{
			*dest = *src;
			dest++;
			src++;
		}
	}
}

/**********************************************************************
* Purpose: This function finds at what point, with an integer, in dest
*		   is string src
*
* Precondition:
*     dest - Either an empty string, or a string with characters
*			 if the user chose menu option 1
*	  src  - A string created and filled by the user once they
*			 choose this menu option
*
* Postcondition:
*     Returns count as when the first character of src shows up in dest
*
************************************************************************/
int Index(char * dest, char * src)
{
	int count = 0;
	int equals;
	char *temp = src;
	int length = StrLen(temp);

	while (*dest != 0)
	{
		if (*dest == *src)
		{
			equals = count;
			while (*dest == *src && *src != 0)
			{
				equals++;
				dest++;
				src++;
			}

			if (equals == length)
			{
				return count;
			}
			else
			{
				count = 0;
				src = temp;
			}
		}
		dest++;
		count++;
	}

	return count;
}

/**********************************************************************
* Purpose: This function creates a sub string using the string
*		   existing in dest
*
* Precondition:
*     dest - Either an empty string, or a string with characters
*			 if the user chose menu option 1
*	  start - An integer stated by the user to choose when to start
*			  the Sub-String
*	  num_char - An integer stated by the user of how many characters
*				 to copy and insert as a substring 
*
* Postcondition:
*     Modifies dest by creating a sub-string in it
*
************************************************************************/
void CreateSub(char * dest, int start, int num_char)
{
	char name[MAX_NAME_SIZE];
	int count = StrLen(dest);

	for (int ii = 0; ii < count + 1; ii++)
	{
		name[ii] = *dest;
		dest++;
	}
	dest -= count + 1;
	dest += start;

	for (int value = 0; value < num_char; value++)
	{
		*dest = name[value];
		dest++;
	}
}
