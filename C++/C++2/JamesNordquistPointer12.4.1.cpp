/****************************************************************
* Author:		James Nordquist
* Filename:		JamesNordquistPointer12.4.1
* Date Created:	3/7/18
* Modifications:	4/4/18 - Changed Header to fit cst 136 style
*****************************************************************/
/*************************************************************
*
* Assignment:  12.4.1
*
* Overview:
*	This program is to implement what was learned so far in
*	chapter 12. The program takes one array and finds the
*	address of the array and of the first pointer. After that,
*	the program will change the elements of the array using 
*	pointers.
*	
* Input:
*	There are no inputs by the user, only predetermined
*	variables.
*
* Output:
*	The program will output the address of the array and first
*	pointer as well as the first three elements of the array
*	and the changes made to the array. It will output the 
*	complete array with changes.
*
************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main()
{
	int numbers[5] = { 99,32,1,88,100 };
	int * int_ptr = numbers;
	int ** int_ptr_ptr = &int_ptr;

	// A.
	cout << "Array Address: " << numbers << endl;
	// B.
	cout << "Array Address with one pointer: " << int_ptr << endl;
	// C.
	cout << "Array Address with two pointers: " << *int_ptr_ptr << endl;
	// D.
	cout << "First pointer address: " << &int_ptr << endl;
	// E.
	cout << "First pointer address using another pointer: " << int_ptr_ptr << endl;
	// F.
	cout << "First element of the array using one pointer: " << *int_ptr << endl;
	// G.
	cout << "First element of the array using two pointers: " << **int_ptr_ptr << endl;
	// H.
	int_ptr++;
	// I.
	cout << "Second element of the array using one pointer: " << *int_ptr << endl;
	// J.
	cout << "Second element of the array using two pointers: " << **int_ptr_ptr << endl;
	// K.
	*int_ptr = 101;
	cout << "Changing the second element of the array with one pointer: " << *int_ptr << endl;
	// L.
	**int_ptr_ptr = 102;
	cout << "Changing the second element of the array with two pointers: " << **int_ptr_ptr << endl;
	// M.
	(*int_ptr_ptr)++;
	cout << "Third element of the array using two pointers: " << *int_ptr << endl;
	// N.
	*int_ptr = -1;
	cout << "Changing the third element of the array with one pointer: " << *int_ptr << endl;
	// O.
	**int_ptr_ptr = -2;
	cout << "Changing the third element of the array with two pointers: " << **int_ptr_ptr << endl << endl;
	// P.
	for (int ii = 0; ii < 5; ii++)
	{
		cout << ii << ":" << numbers[ii] << endl;
	}

	return 0;
}

