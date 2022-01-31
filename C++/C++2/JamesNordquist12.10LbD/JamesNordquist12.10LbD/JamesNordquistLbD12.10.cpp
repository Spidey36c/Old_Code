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

void MakeSpace(char *&str3, char *&str2);
void MakeSpacePointer(char ** dest, char **src);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	char *str = nullptr;
	char *str2 = nullptr;
	char *str3 = nullptr;
	char buffer[255];

	cout << "Enter a string: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(buffer, 255);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	str = new char[strlen(buffer) + 1];
	str3 = new char[strlen(buffer) + 1];
	strcpy(str, buffer);
	strcpy(str3, buffer);
	cout << "Enter another string: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(buffer, 255);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	str2 = new char[strlen(buffer) + 1];
	strcpy(str2, buffer);
	MakeSpacePointer(&str, &str2);

	cout << str << endl;
	MakeSpace(str3, str2);
	cout << str3 << endl;
	delete[] str;
	delete[] str2;
	delete[] str3;
	return 0;
}

void MakeSpace(char *&str3, char *&str2)
{
	char *temp = new char[strlen(str3) + strlen(str2) + 1];
	strcpy(temp, str3);
	strcpy(temp + strlen(str3), str2);
	delete[] str3;
	str3 = temp;
}

void MakeSpacePointer(char **dest, char **src)
{
	char *temp = new char[strlen(*src) + strlen(*dest)+1];

	strcpy(temp, *dest);
	strcpy(temp+strlen(*dest), *src);
	delete[] * dest;
	*dest = temp;
}