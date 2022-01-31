#include <iostream>

void RecursiveStr(int *size, char str[]);

using std::cout;
using std::cin;
using std::endl;

int main()
{
	char str[15] = { 'H','e','l','l','o',' ','W','o','r','l','d','\0' };
	int size = strlen(str)-1;

	RecursiveStr(&size, str);
	cout << endl;
	return 0;
}

void RecursiveStr(int *size, char str[])
{
	if ((*size) >= 0)
	{
		cout << str[*size];
		(*size) -= 1;
		RecursiveStr(size, str);
	}
}