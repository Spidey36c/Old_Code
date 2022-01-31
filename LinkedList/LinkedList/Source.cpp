/*************************************************************
* Author:		James Nordquist
* Filename:		Source.cpp
* Date Created:	6/6/18
* Modifications:	6/7/18 - Did everything
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Linked List
*
* Overview:
*	This program will read from a file of songs and artist 
*	into a linked list then allow the user to either add or
*	remove songs from the list.
* Input:
*	The input will consist of either the name of a song, name of an artist
*	, or both and two selection variables.
* Output:
*	The output of this program will be whether or not a song
*	or artist was found and whether or not something was
*	successful
************************************************************/
#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::string;
#include "List.h"
#include "Node.h"
#include "Song.h"

void BatchAdd(List & myList, const char * filename);
void SingleAdd(List & myList);
void BatchRemove(List & myList, const char * filename);
void SingleRemove(List & myList);

int main()
{
	string buffer;
	List myList;
	int selection;
	char select;
	BatchAdd(myList, "Current.txt");
	bool saved = true;
	cout << "What do you want to do?" << endl;
	cout << "1. Search by Song" << endl;
	cout << "2. Search by Artist" << endl;
	cout << "3. Add a Song" << endl;
	cout << "4. Batch Add Songs" << endl;
	cout << "5. Remove a Song" << endl;
	cout << "6. Batch Remove Songs" << endl;
	cout << "7. Save" << endl;
	cout << "8. Exit" << endl;
	cout << "> ";
	cin >> selection;
	while (selection < 1 || selection > 8)
	{
		cout << "Invalid Selection" << endl;
		cout << "What do you want to do?" << endl;
		cout << "1. Search by Song" << endl;
		cout << "2. Search by Artist" << endl;
		cout << "3. Add a Song" << endl;
		cout << "4. Batch Add Songs" << endl;
		cout << "5. Remove a Song" << endl;
		cout << "6. Batch Remove Songs" << endl;
		cout << "7. Save" << endl;
		cout << "8. Exit" << endl;
		cout << ">";
		cin >> selection;
	}
	while (selection >= 1 && selection < 8)
	{
		switch (selection)
		{
		case 1:
			cout << "What song do you want to find? ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, buffer);
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			myList.searchSongName(buffer);
			break;
		case 2:
			cout << "What artist do you want to find? ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, buffer);
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			myList.searchArtistName(buffer);
			break;
		case 3:
			SingleAdd(myList);
			saved = false;
			break;
		case 4:
			cout << "Attempting to add songs from ToBeAdded.txt" << endl;
			BatchAdd(myList, "ToBeAdded.txt");
			saved = false;
			break;
		case 5:
			SingleRemove(myList);
			saved = false;
			break;
		case 6:
			cout << "Attemping to remove songs from ToBeRemoved.txt" << endl;
			BatchRemove(myList, "ToBeRemoved.txt");
			saved = false;
			break;
		case 7:
			myList.saveToFile("Current.txt");
			saved = true;
			break;
		}
		cout << "What do you want to do?" << endl;
		cout << "1. Search by Song" << endl;
		cout << "2. Search by Artist" << endl;
		cout << "3. Add a Song" << endl;
		cout << "4. Batch Add Songs" << endl;
		cout << "5. Remove a Song" << endl;
		cout << "6. Batch Remove Songs" << endl;
		cout << "7. Save" << endl;
		cout << "8. Exit" << endl;
		cout << ">";
		cin >> selection;
		while (selection < 1 || selection > 8)
		{
			cout << "Invalid Selection" << endl;
			cout << "What do you want to do?" << endl;
			cout << "1. Search by Song" << endl;
			cout << "2. Search by Artist" << endl;
			cout << "3. Add a Song" << endl;
			cout << "4. Batch Add Songs" << endl;
			cout << "5. Remove a Song" << endl;
			cout << "6. Batch Remove Songs" << endl;
			cout << "7. Save" << endl;
			cout << "8. Exit" << endl;
			cout << ">";
			cin >> selection;
		}
	}

	if (selection == 8 && saved == false)
	{
		cout << "Do you want to save any changes made to the list?(y/n) ";
		cin >> select;
		if (select == 'Y' || select == 'y')
		{
			myList.saveToFile("Current.txt");
		}
	}

	return 0;
}

/**********************************************************************
* Purpose: This function reads information from a filename and places it
*		   into the linked list
*
* Precondition:
*     myList - the linked list that is going to have information from the 
*			   file placed into
*	  filename - the name of the file to be read
*
* Postcondition:
*      New information added to myList
*
************************************************************************/
void BatchAdd(List & myList, const char * filename)
{
	Song funcSong;
	string buffer;
	ifstream fin;
	fin.open(filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, buffer);
			funcSong.setSongName(buffer);
			getline(fin, buffer);
			funcSong.setArtistName(buffer);
			if (funcSong.getSongName() != "")
			{
				myList.insertOrdered(funcSong);
			}
		}
		fin.close();
		cout << "Suceeded in adding songs that were in ToBeAdded.txt" << endl;
	}
	else
	{
		cout << "File could not be opened" << endl;
	}
}

/**********************************************************************
* Purpose: This function adds one song to the linked list
*
* Precondition:
*     myList - the linked list that is going to have new information put into it
*
* Postcondition:
*      New information added to myList
*
************************************************************************/
void SingleAdd(List & myList)
{
	string buffer;
	Song funcSong;

	cout << "What is the name of the song you want to add? ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, buffer);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	funcSong.setSongName(buffer);
	cout << "What is the name of the artists of the song? ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, buffer);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	funcSong.setArtistName(buffer);
	myList.insertOrdered(funcSong);
}

/**********************************************************************
* Purpose: This function reads information from a filename and removes
*		   matching info from the linked list
*
* Precondition:
*     myList - the linked list that is going to have information from the
*			   file taken out of
*	  filename - the name of the file to be read
*
* Postcondition:
*      Information taken from myList
*
************************************************************************/
void BatchRemove(List & myList, const char * filename)
{
	Song funcSong;
	string buffer;
	ifstream fin;
	fin.open(filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, buffer);
			myList.deleteNode(buffer);
			getline(fin, buffer);
		}
		fin.close();
		cout << "Suceeded in removing songs that were in the list and ToBeRemoved.txt" << endl;
	}
	else
	{
		cout << "File could not be opened" << endl;
	}
}
/**********************************************************************
* Purpose: This function removes one song from the linked list
*
* Precondition:
*     myList - the linked list that is going to have information taken from it
*
* Postcondition:
*      Information taken from myList
*
************************************************************************/
void SingleRemove(List & myList)
{
	string buffer;
	Song funcSong;

	cout << "What is the name of the song you want to remove? ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, buffer);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	myList.deleteNode(buffer);
}