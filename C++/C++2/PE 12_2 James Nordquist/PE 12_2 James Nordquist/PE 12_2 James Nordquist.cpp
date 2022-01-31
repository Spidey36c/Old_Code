/****************************************************************
* Author:		James Nordquist
* Filename:		PE 12_2 James Nordquist
* Date Created:	4/16/18
* Modifications:	4/18/18 Made DeleteString Function
*
*****************************************************************/
/*************************************************************
*
* Assignment:  Programming Excercises 12_2
*
* Overview:
*	This program reads a file and outputs the words in the file
*	and how many times they appear
*
* Input:
*
* Output:
*	This program will output the words of the file and how
*	many times each word appears
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
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::right;
using std::left;

void DeleteString(char ** dest,int & size);

const int MAX_NAME_SIZE = 255;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ifstream fin;
	fin.open("Text.txt");
	if (fin.is_open())
	{
		char ** words = new char *[MAX_NAME_SIZE];
		char * str = nullptr;
		int num_words = 0;
		char buffer[256];
		int count[MAX_NAME_SIZE] = { 0 };
		int result = 0;
		char ** dump = new char *[MAX_NAME_SIZE];
		int dump_size = 0;
		bool new_word = true;

		fin >> buffer;

		str = new char[strlen(buffer) + 1];
		strcpy(str, buffer);

		words[num_words] = str;
		count[num_words]++;
		num_words++;

		while (!fin.eof())
		{
			fin >> buffer;

			strtok(buffer, " ,.");

			str = new char[strlen(buffer) + 1];
			strcpy(str, buffer);

			for (int ii = 0; ii < num_words; ii++)
			{
				result = stricmp(str, words[ii]);
				if (result == 0)
				{
					new_word = false;
					count[ii]++;
					dump[dump_size] = str;
					dump_size++;
				}
			}
			if (new_word == true)
			{
				words[num_words] = str;
				count[num_words]++;
				num_words++;
			}
			new_word = true;
		}

		cout << setw(35) << right << "Word Frequency Analysis" << endl << endl;
		cout << "Word" << setw(19) << right << "Frequency" << endl;

		for (int ii = 0; ii < num_words; ii++)
		{
			cout << setw(8) << left << words[ii] << setw(8) << right << count[ii] << endl;
		}

		DeleteString(words, num_words);

		DeleteString(dump, dump_size);

		fin.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Sleep(10000);
	return 0;
}

/**********************************************************************
* Purpose: This function deletes 2d dynamic arrays to avoid memory leaks
*
* Precondition:
*     dest - The 2d dynamic array made in main
*	  size - The size of the array to avoid deleting outside of the array
*
* Postcondition:
*     deletes dest and changes it to nullptr and makes size 0
*
************************************************************************/
void DeleteString(char ** dest, int & size)
{
	for (int ii = 0; ii < size; ii++)
	{
		delete[] dest[ii];
	}
	
	delete[] dest;
	
	dest = nullptr;

	size = 0;
}