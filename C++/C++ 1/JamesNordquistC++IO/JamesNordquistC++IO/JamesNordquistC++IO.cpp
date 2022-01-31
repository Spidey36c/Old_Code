/************************
* C++ I/O
* James Nordquist
************************/

#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;
using std::right;

int main()
{
	const int NUMBER_OF_EMPLOYEES = 3;
	double wages[NUMBER_OF_EMPLOYEES];
	char firstName[NUMBER_OF_EMPLOYEES][21];
	char lastName[NUMBER_OF_EMPLOYEES][21];


	for (int ii = 1; ii <= NUMBER_OF_EMPLOYEES; ii++)
	{
		cout << "Enter employee number " << ii << " first name: ";
		cin >> firstName[ii-1];
		cout << "Enter employee number " << ii << " last name: ";
		cin >> lastName[ii-1];
		cout << "Enter employee number " << ii << " Hourly wages: ";
		cin >> wages[ii-1];
	}
	cout << endl;
	cout << "First Name" << setw(19) << "Last Name" << setw(19) << "Hourly Wages" << endl;
	for (int ii = 0; ii < NUMBER_OF_EMPLOYEES; ii++)
	{
		cout << setw(20) << left << firstName[ii];
		cout << setw(20) << left << lastName[ii];
		cout << setprecision(2) << fixed << setw(8) << right << wages[ii] << endl;
	}


	char exit;
	cout << "Enter a key to exit.";
	exit = _getch();

	return 0;
}