/****************************************************************
* Author:		James Nordquist
* Filename:		JamesNordquist12.7LearnbyDoing
* Date Created:	4/12/18
* Modifications:
*****************************************************************/
/*************************************************************
*
* Assignment:  Learn by Doing 12.7
*
* Overview:
*	This program has us create strcat and strlen using pointers
*	and show that it works
*
* Input:
*	A dest and src string made by the user
*
* Output:
*	This program will output dest after a strcat is made
*
************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

char *StrCat(char * dest, char *src);
int StrLen(char * dest);

int main()
{
	const int MAX_SIZE = 255;
	char string[MAX_SIZE];
	char string2[MAX_SIZE];

	cout << "Enter a string: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(string, MAX_SIZE);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	cout << "Enter what you want to put at the end of the string you just entered: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(string2, MAX_SIZE);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	*string = *StrCat(string, string2);
	cout << "The string is now " << string << endl;

	return 0;

}

char *StrCat(char *dest, char *src)
{
	char *return_val = dest;
	int count;

	while (*dest != 0)
	{
		dest++;
	}

	count = StrLen(return_val);

	// Adds a space between words entered
	//if (count != 0)
	//{
	//	*dest = ' ';
	//	dest++;
	//}

	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return return_val;
}

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