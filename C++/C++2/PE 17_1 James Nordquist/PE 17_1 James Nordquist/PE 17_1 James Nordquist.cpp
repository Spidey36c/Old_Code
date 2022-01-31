/****************************************************************
* Author:		James Nordquist
* Filename:		PE 17_1 James Nordquist
* Date Created:	5/9/18
* Modifications:
*
*****************************************************************/
/*************************************************************
*
* Assignment:  Programming Excercises 17_1
*
* Overview:
*	This program reads a file and displays the hex values of the file
*	as well as the translated ASCII characters
*
* Input:
*	Filename
* Output:
*	The Hex values of the file, The ASCII characters of the file
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

using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::ifstream;
using std::ios;
using std::hex;
using std::setfill;
using std::dec;
using std::uppercase;
using std::setprecision;
using std::left;
using std::right;

void ReadFileAndOutput(char filename[], int address, unsigned char temp[]);
void HexOutput(int *address, unsigned char temp[]);

int main()
{
	char filename[256];
	int address = 0;
	unsigned char temp[16];

	cout << "Drag and drop file(one with no spaces in the name) you want to open ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(filename, 255);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << endl << endl;

	ReadFileAndOutput(filename, address, temp);

	return 0;
}

/**********************************************************************
* Purpose: Bulk of the program that handles the file and formating
*
* Precondition:
*     filename - cString that holds the filename to be open
*	  address - The address of the hex that is outputted
*	  temp - cString that holds 16 bytes of the file and is used to output
*
* Postcondition:
*     prints the address, hex numbers, and printable characters.
*
************************************************************************/
void ReadFileAndOutput(char filename[], int address, unsigned char temp[])
{
	ifstream input(filename, ios::in, ios::binary);
	if (input.is_open())
	{
		cout << "Address |" << setw(33) << "Hex Numbers" << setw(21) << "|" << setw(16) << "Printable Chars" << endl;
		for (int i = 0; i < 80; i++)
		{
			cout << "_";
		}
		cout << endl;
		while (!input.eof())
		{
			if (address % 16 == 0)
			{
				cout << left << setw(8) << dec << address;
			}
			cout << "| ";
			input.read(reinterpret_cast<char *>(temp), sizeof(char) * 16);

			HexOutput(&address, temp);

			cout << "| ";
			for (int i = 0; i < 16; i++)
			{
				if (static_cast<char>(temp[i]) < 32)
				{
					cout << ".";
				}
				else
				{
					cout << temp[i];
				}
			}
			cout << endl;
		}
		input.close();
	}
	else
	{
		cout << "File does not exist" << endl;
	}
}

/**********************************************************************
* Purpose: Converting 16 bytes of the binary file to int and output as hex
*
* Precondition:
*	  address - The address of the hex that is outputted
*	  temp - cString that holds 16 bytes of the file and is used to output hex
*
* Postcondition:
*     prints hex numbers
*
************************************************************************/
void HexOutput(int *address, unsigned char temp[])
{
	for (int i = 0; i < 16; i++)
	{
		if (static_cast<int>(temp[i]) < 16)
		{
			cout << "0";
		}
		cout << hex << setfill(' ') << uppercase << right << static_cast<int>(temp[i]) << " ";

		(*address)++;
		if ((*address) % 8 == 0)
		{
			cout << "  ";
		}
	}
}