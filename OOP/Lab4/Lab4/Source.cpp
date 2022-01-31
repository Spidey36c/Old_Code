#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include "Character.h"
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;


int main()
{
	Character carray[3];

	Potion test = { "Potion of Health" , "Heals half", "Mid", "0.0.12.52" };
	DynamicArray test2;
	test2.Insert(test);
	BackPack test3;
	test3.addArrayPotion(test2);
	CoinPouch test4 = "1.2.55.70";
	String cname = "Bob";
	Character Bob(test3, test4, cname);
	carray[0] = Bob;


	ofstream myfile("character.bin", ios::out | ios::binary | ios::ate);

	if (myfile.is_open())
	{

		myfile.write(reinterpret_cast<char *>(cname.c_str()), 30); // make 30 into const int

		myfile.close();
	}
	else
	{
		cout << "Could not open file" << endl;
	}

	ifstream fin("character.bin", ios::in | ios::binary);

	if (fin.is_open())
	{
		char buffer[30];
		fin.read(reinterpret_cast<char *>(buffer), 30);
	
		fin.close();
	}
	else
	{
		cout << "Could not open file" << endl;
	}
	
	return 0;
}