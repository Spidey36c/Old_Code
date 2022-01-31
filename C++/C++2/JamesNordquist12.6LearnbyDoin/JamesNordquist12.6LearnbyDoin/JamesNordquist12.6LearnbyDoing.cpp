/****************************************************************
* Author:		James Nordquist
* Filename:		JamesNordquistProgrammingExcercises12
* Date Created:	4/12/18
* Modifications:
*****************************************************************/
/*************************************************************
*
* Assignment:  Learn by Doing 12.6
*
* Overview:
*	This program declares a two dimensional array and displays
*	the contents using a pointer
*
* Input:

*
* Output:
*	This program will output the contents of the array
*
************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int data[4][5] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int *int_ptr = *data;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << *int_ptr << endl;
			int_ptr++;
		}
		cout << ' ' << endl;
	}
	return 0;
}