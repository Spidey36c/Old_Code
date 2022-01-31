/*************************************************************
* Author:		James Nordquist
* Filename:		Source.cpp
* Date Created:	5/18/2019
* Modifications:	
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Programming Excercise 15_1
*
* Overview:
*	This program uses a class to create a fraction calculator
*
* Input:
*	The input will be 3 class variables, two with numerators and
*	denominators, 1 that will be used to do all the math on
*
* Output:
*	The output will be the fractions adding, subtracting, mutiplying
*	dividing, and the output of such mathmatics
*
************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Fraction.h"

void Add(Fraction f1, Fraction f2, Fraction *f3);
void Subtract(Fraction f1, Fraction f2, Fraction *f3);
void Multiply(Fraction f1, Fraction f2, Fraction *f3);
void Divide(Fraction f1, Fraction f2, Fraction *f3);

int main()
{
	Fraction f1(12,18),f2(1,2),f3;

	Add(f1, f2, &f3);

	cout << endl;

	Subtract(f1, f2, &f3);

	cout << endl;
	
	Multiply(f1, f2, &f3);

	cout << endl;

	Divide(f1, f2, &f3);

	cout << endl;

	return 0;
}

/**********************************************************************
* Purpose: adds fractions f1 and f2 and places the end result in f3
*
* Precondition:
*	   f1 - a fraction with a numerator and denominator
*	   f2 - a fraction with a numerator and denominator
*	   f3 - a fraction that has no numerator or denominator
* Postcondition:
*      f3 is given a numerator and denominator
*
************************************************************************/
void Add(Fraction f1, Fraction f2, Fraction *f3)
{
	(*f3).Add(f1, f2);
	f1.Display();
	cout << " + ";
	f2.Display();
	cout << " = ";
	(*f3).Display();
}
/**********************************************************************
* Purpose: Subtracts fractions f1 and f2 and places the end result in f3
*
* Precondition:
*	   f1 - a fraction with a numerator and denominator
*	   f2 - a fraction with a numerator and denominator
*	   f3 - a fraction that has no numerator or denominator
* Postcondition:
*      f3 is given a numerator and denominator
*
************************************************************************/
void Subtract(Fraction f1, Fraction f2, Fraction *f3)
{
	(*f3).Subtract(f1, f2);
	f1.Display();
	cout << " - ";
	f2.Display();
	cout << " = ";
	(*f3).Display();
}
/**********************************************************************
* Purpose: Multiplies fractions f1 and f2 and places the end result in f3
*
* Precondition:
*	   f1 - a fraction with a numerator and denominator
*	   f2 - a fraction with a numerator and denominator
*	   f3 - a fraction that has no numerator or denominator
* Postcondition:
*      f3 is given a numerator and denominator
*
************************************************************************/
void Multiply(Fraction f1, Fraction f2, Fraction *f3)
{
	(*f3).Multiply(f1, f2);
	f1.Display();
	cout << " * ";
	f2.Display();
	cout << " = ";
	(*f3).Display();
}
/**********************************************************************
* Purpose: Divides fractions f1 and f2 and places the end result in f3
*
* Precondition:
*	   f1 - a fraction with a numerator and denominator
*	   f2 - a fraction with a numerator and denominator
*	   f3 - a fraction that has no numerator or denominator
* Postcondition:
*      f3 is given a numerator and denominator
*
************************************************************************/
void Divide(Fraction f1, Fraction f2, Fraction *f3)
{

	(*f3).Divide(f1, f2);
	f1.Display();
	cout << " / ";
	f2.Display();
	cout << " = ";
	(*f3).Display();

}