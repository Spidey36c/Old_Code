/****************************************************************
* Author:		James Nordquist
* Filename:		JamesNordquistPointer12.5.1
* Date Created:	4/4/18
* Modifications:
*****************************************************************/
/*************************************************************
*
* Assignment:  12.5.1
*
* Overview:
*	This program takes an example from eariler in the book
*	and changes any references by value to pointers.
*
* Input:
*	There are no inputs by the user, only predetermined
*	variables.
*
* Output:
*	The program will output variables a and b multiple times
*	but the outputs will changed based on what "Fun" function
*	the variables have been passed too. It will also print
*	variables c and d.
*
************************************************************/
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

int Fun1(int a, int b);
void Fun2(int * a, int b);
void Fun3(int * c, int * d);
void PrintOutput(int a, int b);

int main()
{
	int a = 2, b = 10;
	PrintOutput(a, b);
	a = Fun1(a, b);
	cout << a << "\t" << b << endl;

	Fun2(&a, b);
	PrintOutput(a, b);

	return 0;
}
//PrintOutput
void PrintOutput(int a, int b)
{
	cout << a << "\t" << b << endl;
}

//Fun1
int Fun1(int a, int b)
{
	int c;
	
	c = a + b;
	a++;
	--b;

	cout << a << "\t" << b << "\t" << c << endl;

	return c;
}
//Fun2
void Fun2(int * a, int b)
{
	*a += 5;
	double temp = pow(static_cast<double>(*a), 2);
	b = static_cast<int>(temp);

	PrintOutput(*a, b);
	Fun3(a, &b);
	PrintOutput(*a, b);
}
//Fun3
void Fun3(int * c, int * d)
{
	*c = 25;
	*d = 10;
	PrintOutput(*c, *d);
}