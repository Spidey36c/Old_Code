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

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	char ** students = nullptr;
	char * str = nullptr;
	char buffer[256];
	int * scores = nullptr;
	int num_students = 0;
	double average = 0;

	cout << "How many students do you have? ";
	cin >> num_students;

	students = new char *[num_students];
	scores = new int [num_students];

	for (int ii = 0; ii < num_students; ii++)
	{
		cout << "Enter student " << ii + 1 << " name: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(buffer, 255);
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		
		str = new char[strlen(buffer) + 1];
		strcpy(str, buffer);

		students[ii] = str;

		cout << "Enter student " << ii + 1 << " score: ";
		cin >> scores[ii];
	}

	cout << endl;

	for (int ii = 0; ii < num_students; ii++)
	{
		cout << setw(30) << left << students[ii] << setw(20) << right << scores[ii] << endl;;
		average += scores[ii];
	}
	average /= num_students;
	cout << "The average is " << average << endl;

	for (int ii = 0; ii < num_students; ii++)
	{
		delete[] students[ii];
	}
	delete[] students;

	delete[] scores;

	students = nullptr;

	return 0;
}


