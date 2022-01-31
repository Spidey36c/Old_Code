/********************************************
* Pointers
* James Nordquist
*********************************************/
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

