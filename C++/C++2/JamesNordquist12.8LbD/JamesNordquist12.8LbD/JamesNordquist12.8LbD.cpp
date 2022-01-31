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

void ChkInstances(char *dest, char src);

int main()
{
	char string[255];
	char chr;

	cout << "Enter a string: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(string, 255);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Enter a letter to see how many times it appears: ";
	cin >> chr;

	ChkInstances(string, chr);

	return 0;
}

void ChkInstances(char * dest, char src)
{
	int ptr_ch = 0;
	int size = strlen(dest);

	cout << "Searching for char " << src << " in string " << dest << endl;

	for (int i = 0; i < size; i++)
	{
		if (src == dest[i])
		{
			ptr_ch++;
		}
	}

	if (ptr_ch == 0)
	{
		cout << src << " does not appear" << endl;
	}
	else
	{
		cout << src << " appears " << ptr_ch << " times " << endl;
	}
}