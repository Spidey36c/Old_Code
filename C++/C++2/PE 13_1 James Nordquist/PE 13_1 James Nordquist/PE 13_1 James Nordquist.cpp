/****************************************************************
* Author:		James Nordquist
* Filename:		PE 12_4 James Nordquist
* Date Created:	4/18/18
* Modifications:
*
*****************************************************************/
/*************************************************************
*
* Assignment:  Programming Excercises 12_4
*
* Overview:
*	This program tracks ingredients entered by the user and allows
*	the user to edit the names of the ingredienst, delete
*	ingredients, display all the ingredients in pantry, search
*	for a specific ingredient, save current ingredients into
*	a file, and check the recipe for ingredients
*
* Input:
*	Ingredient names, and recipe file names
* Output:
*	This program will output the ingredients and whether or
*	not they are needed in the recipe
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
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::ofstream;
using std::ifstream;
using std::right;
using std::left;
using std::fixed;
using std::setprecision;

struct Employee
{
	char fName[25];
	char lName[25];
	char socSec[25];
	double wage;
	double oTWage = 0;
	double totalPay;
	int hours;
	int oTHours = 0;
	char status;
};

void Overtime(Employee data[], int counter);

const int MAX_SIZE = 11;
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int counter = 0;
	Employee data[MAX_SIZE];
	ifstream fin;
	char str[50];
	fin.open("Data.txt");
	if (fin.is_open())
	{
		while (counter < MAX_SIZE)
		{
			fin >> data[counter].fName;
			fin >> data[counter].lName;
			fin >> data[counter].socSec;
			fin >> data[counter].wage;
			fin >> data[counter].hours;
			fin >> data[counter].status;
			counter++;
		}
		fin.close();
	}
	else
	{
		cout << "File could not be opened" << endl;
	}
	Overtime(data, counter);
	for (int i = 0; i < counter; i++)
	{
		if (data[i].status != 'F')
		{
			data[i].totalPay = (data[i].wage*(data[i].hours - data[i].oTHours) + data[i].oTWage);
		}
		else if (data[i].wage - 5 < 0 && data[i].status != 'P')
		{
			data[i].totalPay = data[i].oTWage;
		}
		else
		{
			data[i].totalPay = ((data[i].wage-5)*(data[i].hours - data[i].oTHours) + data[i].oTWage);
		}
	}

	cout << "Name" << setw(28) << "Social Security" << setw(6) << "Wage" 
		<< setw(12) << "Hours" << setw(8) << "Status" << endl << endl;
	for (int i = 0; i < counter; i++)
	{
		strcpy(str, data[i].fName);
		strcat(str, " ");
		strcat(str, data[i].lName);
		cout << left << setw(14) << str <<right << setw(15) << data[i].socSec;
		cout << setw(6) << " $" << setw(6) << setprecision(2) << fixed << data[i].wage;
		cout << right << setw(6) << data[i].hours << setw(8) << data[i].status << endl << endl;
	}
	
	cout << "Name" << setw(30) << "Straight Time Pay" << setw(16) << "Overtime Pay"
		<< setw(13) << "Total Pay" << setw(11) << "/\\" << endl << endl;
	for (int i = 0; i < counter; i++)
	{
		strcpy(str, data[i].fName);
		strcat(str, " ");
		strcat(str, data[i].lName);
		if (data[i].status != 'F')
		{
			cout << left << setw(14) << str << right << setw(4) << "$" << setw(8) << setprecision(2) << fixed << data[i].wage*(data[i].hours - data[i].oTHours);
		}
		else if (data[i].wage-5 > 0 && data[i].status != 'P')
		{
			cout << left << setw(14) << str << right << setw(4) << "$" << setw(8) << setprecision(2) << fixed << (data[i].wage-5)*(data[i].hours - data[i].oTHours);
		}
		else
		{
			cout << left << setw(14) << str << right << setw(4) << "$" << setw(8) << setprecision(2) << fixed << 0;
		}
		cout << setw(13) << "$" << setw(10) << setprecision(2) << fixed << data[i].oTWage;
		cout << setw(6) << "$" << setw(10) << setprecision(2) << fixed << data[i].totalPay << "\t|" << endl << endl;
	}
	return 0;
}

void Overtime(Employee data[], int counter)
{
	for (int i = 0; i < counter; i++)
	{
		if (data[i].hours > 40)
		{
			data[i].oTHours = data[i].hours-40;
			data[i].oTWage = (data[i].wage *1.5)*(data[i].oTHours);
		}
	}
}