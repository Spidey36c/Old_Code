#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

struct Stuff
{
	char fname[25];
	int age;
	char gender;
};

void ReadData(Stuff data[]);
void DisplayOne(Stuff data);
void EditRef(Stuff &data);
void EditPointer(Stuff *data);

int main()
{
	Stuff data[5];
	int size = 0;
	ReadData(data);
	for (int i = 0; i < 5; i++)
	{
		DisplayOne(data[i]);
	}
	cout << "What place in the array do you want to replace: ";
	cin >> size;
	EditRef(data[size]);
	for (int i = 0; i < 5; i++)
	{
		DisplayOne(data[i]);
	}
	cout << "What place in the array do you want to replace: ";
	cin >> size;
	EditPointer(&data[size]);
	for (int i = 0; i < 5; i++)
	{
		DisplayOne(data[i]);
	}
	return 0;
}

void ReadData(Stuff data[])
{
	ifstream fin;
	int counter = 0;
	fin.open("Data.txt");
	if (fin.is_open())
	{
		while (counter < 5)
		{
			fin >> data[counter].fname;
			fin >> data[counter].age;
			fin >> data[counter].gender;
			counter++;
		}
		fin.close();
	}
	else
	{
		cout << "File could not be opened" << endl;
	}
	
}

void EditRef(Stuff &data)
{
	cout << "Enter a new name: ";
	cin >> data.fname;
	cout << "Enter an age: ";
	cin >> data.age;
	cout << "Enter their gender: ";
	cin >> data.gender;
}

void EditPointer(Stuff *data)
{
	cout << "Enter a new name: ";
	cin >> data->fname;
	cout << "Enter an age: ";
	cin >> data->age;
	cout << "Enter their gender: ";
	cin >> data->gender;
}

void DisplayOne(Stuff data)
{
	cout << data.fname << " ";
	cout << data.age << " ";
	cout << data.gender << endl;
}