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
using std::setw;
using std::right;
using std::left;
using std::fixed;
using std::setprecision;

const int MAX_SIZE = 255;

void AddStock(char *** names, char buffer[], int *num_names);
void DeleteStock(char ** dest, int size);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int num_names = 0;
	char ** names = nullptr;
	char * str = nullptr;
	char buffer[256] = { " " };
	char selection[2] = { "y" };

	cout << "Do you want to enter a stock? (y/n) ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(selection, 2);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	while (selection[0] == 'y' || selection[0] == 'Y')
	{
		AddStock(&names, buffer, &num_names);
		for (int i = 0; i < num_names;i++)
		{
			cout << names[i] << endl;
		}
		cout << "Do you want to enter another stock? (y/n) ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(selection, 2);
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}

	DeleteStock(names, num_names);

	return 0;
}

void AddStock(char *** names, char buffer[], int *num_names)
{
	char ** temp = new char *[*num_names + 1];

	for (int ii = 0; ii < *num_names; ii++)
	{
		temp[ii] = (*names)[ii];
	}

	cout << "Enter stock symbol: ";
	cin >> buffer;

	temp[*num_names] = new char[strlen(buffer) + 1];

	strcpy(temp[*num_names], buffer);

	delete[] * names;

	*names = temp;

	(*num_names)++;
}

void DeleteStock(char ** dest, int size)
{
	for (int ii = 0; ii < size; ii++)
	{
		delete[] dest[ii];
	}

	delete[] dest;

	dest = nullptr;
}