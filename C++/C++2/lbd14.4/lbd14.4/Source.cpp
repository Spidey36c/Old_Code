#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;

void FindName(string name, string fname[], string lname[],string number[], string bday[], int size);
void AddPerson(string fname[], string lname[], string number[], string bday[], int *size);
void EditPerson(string fname[], string lname[], string number[], string bday[], int size);

int main()
{
	int size = 0;
	int choice = 0;
	string fname[25];
	string lname[25];
	string name;
	string number[25];
	string bday[25];
	ifstream fin;
	ofstream fout;
	fin.open("Text.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> fname[size];
			fin >> lname[size];
			fin >> number[size];
			fin >> bday[size];
			size++;
		}
		fin.close();
		cout << "1) Find a person's information" << endl;
		cout << "2) Add a person to the data base" << endl;
		cout << "3) Edit a person's information" << endl;
		cout << "4) Display all records to the screen" << endl;
		cout << "5) Quit" << endl;
		cout << "> ";
		cin >> choice;
		while (choice < 1 || choice > 5)
		{
			cout << "That is not an valid choice pick again" << endl;
			cout << "1) Find a person's information" << endl;
			cout << "2) Add a person to the data base" << endl;
			cout << "3) Edit a person's information" << endl;
			cout << "4) Display all records to the screen" << endl;
			cout << "5) Quit" << endl;
			cout << "> ";
			cin >> choice;
		}
		while (choice >= 1 && choice <= 4)
		{
			switch(choice)
			{
				case 1:
					cout << "What name do you want to find: ";
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, name);
					FindName(name, fname, lname, number, bday, size);
					break;
				case 2:
					AddPerson(fname, lname, number, bday, &size);
					break;
				case 3:
					EditPerson(fname, lname, number, bday, size);
					break;
				case 4:
					for (int i = 0; i < size; i++)
					{
						cout << fname[i] + " " + lname[i] + " " + number[i] + " " + bday[i] << endl;
					}
					break;
			}
			cout << "1) Find a person's information" << endl;
			cout << "2) Add a person to the data base" << endl;
			cout << "3) Edit a person's information" << endl;
			cout << "4) Display all records to the screen" << endl;
			cout << "5) Quit" << endl;
			cout << "> ";
			cin >> choice;
			while (choice < 1 || choice > 5)
			{
				cout << "That is not an valid choice pick again" << endl;
				cout << "1) Find a person's information" << endl;
				cout << "2) Add a person to the data base" << endl;
				cout << "3) Edit a person's information" << endl;
				cout << "4) Display all records to the screen" << endl;
				cout << "5) Quit" << endl;
				cout << "> ";
				cin >> choice;
			}
		}
		fout.open("Text.txt");
		for (int i = 0; i < size; i++)
		{
			fout << fname[i] + " " + lname[i] + " " + number[i] + " " + bday[i] << endl;
		}
	}
	else
	{
		cout << "File could not be opened" << endl;
	}

	return 0;
}

void FindName(string name, string fname[], string lname[],string number[],string bday[],int size)
{
	bool found = false;
	int start = 0;

	while (start < size && found != true)
	{
		string fullname = fname[start] + " " + lname[start];
		if (name == fullname)
		{
			found = true;
		}
		if (found != true)
		{
			start++;
		}
	}
	if (found == true)
	{
		cout << "That person was found" << endl;
		cout << name << " " << number[start] << " " << bday[start] << endl;
	}
	else
	{
		cout << "That person was not found" << endl;
	}
}

void AddPerson(string fname[], string lname[], string number[], string bday[], int *size)
{
	cout << "What is the first name of the person? ";
	cin >> fname[(*size)];
	cout << "What is the last name of the person? ";
	cin >> lname[(*size)];
	cout << "What is the number of the person? ";
	cin >> number[(*size)];
	cout << "What is the birth day of the person? ";
	cin >> bday[(*size)];
	(*size)++;
}

void EditPerson(string fname[], string lname[], string number[], string bday[], int size)
{
	int selection = 0;
	cout << "Who's information do you want to change (1-" << size - 1 << ") ";
	cin >> selection;
	while (selection <= 1 || selection > size - 1)
	{
		cout << "That location doesn't have anyones information on it, try again" << endl;
		cout << "Who's information do you want to change (1-" << size - 1 << ") ";
		cin >> selection;
	}
	cout << "What is the first name of the person? ";
	cin >> fname[selection-1];
	cout << "What is the last name of the person? ";
	cin >> lname[selection-1];
	cout << "What is the number of the person? ";
	cin >> number[selection-1];
	cout << "What is the birth day of the person? ";
	cin >> bday[selection-1];
}