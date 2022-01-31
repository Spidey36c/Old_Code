#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include "Header.h"

int main()
{
	int id;
	int newid;
	char gender;
	char newgender;
	Person thing;
	cout << "What is the persons id? ";
	cin >> id;
	cout << "What is the person's gender? ";
	cin >> gender;
	thing.SetGender(gender);
	thing.SetId(id);
	newid = thing.GetId();
	newgender = thing.GetGender();
	cout << newid << endl;
	cout << newgender << endl;
	cout << "Neat" << endl;
	cin >> id;
	return 0;
}