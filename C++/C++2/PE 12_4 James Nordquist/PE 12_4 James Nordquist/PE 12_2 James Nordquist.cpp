/****************************************************************
* Author:		James Nordquist
* Filename:		PE 12_4 James Nordquist
* Date Created:	4/18/18
* Modifications:
*
*****************************************************************/
/*************************************************************
*
* Assignment:  Programming Excercises 12_4
*
* Overview:
*	This program tracks ingredients entered by the user and allows
*	the user to edit the names of the ingredienst, delete 
*	ingredients, display all the ingredients in pantry, search
*	for a specific ingredient, save current ingredients into
*	a file, and check the recipe for ingredients
*
* Input:
*	Ingredient names, and recipe file names
* Output:
*	This program will output the ingredients and whether or 
*	not they are needed in the recipe
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

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::ofstream;
using std::ifstream;
using std::right;
using std::left;
using std::fixed;
using std::setprecision;

const int MAX_SIZE = 255;

void AddIngredient(char *** names, char buffer[], int *num_names);
void AddIngredientFromFile(char *** names, char buffer[], int *num_names);
void RemoveIngredient(char ***names, char buffer[], int *num_names);
void ChkRecipe(char **names, int num_names,char **recipe,int num_lines);
void SaveIngredients(char **names, int num_names);
void PrintIngredients(char ** names, int num_names);
void EditIngredient(char ***names, char buffer[], int *num_names);
int Index(char **names, int num_names, const char * str);
void DeleteIngredient(char ** dest, int size);
void Purge(char ** dest, int size);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int num_names = 0;
	int num_lines = 0;
	char ** names = new char *[num_names];
	char * str = nullptr;
	ifstream fin;
	ofstream fout;
	char ** recipe = nullptr;
	char buffer[256] = { " " };
	int selection;
	int found = 0;
	
	fin.open("pantry.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(buffer, 255);
			if (strcmp(buffer,"\0") != 0)
			{
				AddIngredientFromFile(&names, buffer, &num_names);
			}
		}
		fout.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}

	cout << "1) Add a new ingredient" << endl;
	cout << "2) Delete an ingredient" << endl;
	cout << "3) Search for an ingredient" << endl;
	cout << "4) Edit an ingredient" << endl;
	cout << "5) Save current Ingredients" << endl;
	cout << "6) Display ingredients" << endl;
	cout << "7) Check recipe for Ingredients" << endl;
	cout << "8) Exit" << endl;
	cout << "> ";
	cin >> selection;
	while (selection < 1 || selection >8)
	{
		cout << "1) Add a new ingredient" << endl;
		cout << "2) Delete an ingredient" << endl;
		cout << "3) Search for an ingredient" << endl;
		cout << "4) Edit an ingredient" << endl;
		cout << "5) Save current Ingredients" << endl;
		cout << "6) Display ingredients" << endl;
		cout << "7) Check recipe for Ingredients" << endl;
		cout << "8) Exit" << endl;
		cout << "> ";
		cin >> selection;
	}
	while (selection != 8)
	{
		if (selection == 1)
		{
			AddIngredient(&names, buffer,&num_names);
		}
		else if (selection == 2)
		{
			RemoveIngredient(&names, buffer, &num_names); 
		}
		else if (selection == 3)
		{
			cout << "What Ingredient are you looking for? ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(buffer, 255);
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			str = new char[strlen(buffer) + 1];
			strcpy(str, buffer);
			found = Index(names, num_names, str);
			if (found == -1)
			{
				cout << "That ingredient was not found" << endl;
			}
			else
			{
				cout << buffer << " was found to be an Ingredient" << endl;
			}
			delete[] str;
		}
		else if (selection == 4)
		{
			EditIngredient(&names, buffer, &num_names);
		}
		else if (selection == 5)
		{
			SaveIngredients(names, num_names);
		}
		else if (selection == 6)
		{
			PrintIngredients(names, num_names);
		}
		else if (selection == 7)
		{
			ifstream fin;
			cout << "What is the recipe file? ";
			cin >> buffer;
			fin.open(buffer);
			if (fin.is_open())
			{
				while (!fin.eof())
				{
					fin.getline(buffer, 255);
					if (strcmp(buffer, "\0") != 0)
					{
						AddIngredientFromFile(&recipe, buffer, &num_lines);
					}
				}
				fout.close();
				ChkRecipe(names, num_names, recipe, num_lines);
			}
			else
			{
				cout << "Unable to open file" << endl;
			}
			Purge(recipe, num_lines);
			num_lines = 0;
		}
		cout << "1) Add a new ingredient" << endl;
		cout << "2) Delete an ingredient" << endl;
		cout << "3) Search for an ingredient" << endl;
		cout << "4) Edit an ingredient" << endl;
		cout << "5) Save current Ingredients" << endl;
		cout << "6) Display ingredients" << endl;
		cout << "7) Check recipe for Ingredients" << endl;
		cout << "8) Exit" << endl;
		cout << "> ";
		cin >> selection;
	}
	if (selection == 8)
	{
		SaveIngredients(names, num_names);
	}

	DeleteIngredient(names, num_names);

	DeleteIngredient(recipe, num_lines);

	return 0;
}

/**********************************************************************
* Purpose: This function checks the recipe text file to see if there
*		   are any missing ingredients or if the ingredients are needed
*		   in the recipe
*
* Precondition:
*     names - 2d array created when program was started, it holds the
*			  ingredients
*	  num_names - number to show how many ingredients are in names
*	  recipe - 2d array of the recipe to which names is compared to
*	  num_lines - number to show how many lines there are in the recipe
*
* Postcondition:
*     prints whether or not an ingredient is needed or not, and if there
*	  is a missing ingredient
*
************************************************************************/
void ChkRecipe(char **names, int num_names, char **recipe, int num_lines)
{
	char * ptr_ch;
	char * str;
	int *found = new int[num_lines];
	int *found2 = new int[num_names];

	for (int i = 0; i < num_lines; i++)
	{
		for (int j = 0; j < num_names; j++)
		{
			ptr_ch = strstr(recipe[i], names[j]);
			if (ptr_ch != nullptr)
			{
				found[i] = 1;
				found2[j] = 1;
			}
		}
	}
	for (int i = 0; i < num_names; i++)
	{
		if (found2[i] == 1)
		{
			cout << names[i] << " is in the recipe" << endl;
		}
		else
		{
			cout << names[i] << " is not in the recipe" << endl;
		}
	}
	cout << endl;
	for (int i = 0; i < num_lines; i++)
	{
		if (found[i] != 1)
		{
			str = strtok(recipe[i], "<");
			str = strtok(nullptr, ">");
			cout << str << " is not apart of the ingredients" << endl;
		}
	}
	delete[] found;
	delete[] found2;
}

/**********************************************************************
* Purpose: This function prints out the output of names to the console
*
* Precondition:
*     names - 2d array made before this function was called
*	  size - the size of the 2d array to avoid errors
*
* Postcondition:
*     prints the contents of names to the console
*
************************************************************************/
void PrintIngredients(char ** names,int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << names[i] << endl;
	}
}

/**********************************************************************
* Purpose: This function prints out the contents of names to a file
*
* Precondition:
*     names - 2d array made before this function was called
*	  size - the size of the 2d array to avoid errors
*
* Postcondition:
*     prints the contents of names to the file
*
************************************************************************/
void SaveIngredients(char **names, int size)
{
	ofstream fout;

	fout.open("pantry.txt");
	if (fout.is_open())
	{
		for (int i = 0; i < size; i++)
		{
			fout << names[i] << endl;
		}
		fout.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
}

/**********************************************************************
* Purpose: This function fills the 2d array names with buffer
*
* Precondition:
*     names - 2d array made before this function was called
*	  buffer - a string made by the current line in a file before this
*			   this function was called
*	  size - the size of the 2d array to avoid errors
*
* Postcondition:
*     names is filled by buffer in one part of its array and made space
*	  in temp for the next possible item
*
************************************************************************/
void AddIngredientFromFile(char *** names, char buffer[], int *size)
{
	char ** temp = new char *[*size + 1];

	for (int ii = 0; ii < *size; ii++)
	{
		temp[ii] = (*names)[ii];
	}

	temp[*size] = new char[strlen(buffer) + 1];

	strcpy(temp[*size], buffer);

	delete[] * names;

	*names = temp;

	(*size)++;
}

/**********************************************************************
* Purpose: This function adds an ingredient to the end of names
*
* Precondition:
*     names - 2d array made before this function was called
*	  buffer - a string made by the user to enter a new ingredient
*	  size - the size of the 2d array to avoid errors
*
* Postcondition:
*     Allows the user to enter a new ingredient to names
*
************************************************************************/
void AddIngredient(char *** names, char buffer[], int *size)
{
	char ** temp = new char *[*size + 1];

	for (int ii = 0; ii < *size; ii++)
	{
		temp[ii] = (*names)[ii];
	}

	cout << "Enter name: ";
	cin >> buffer;

	temp[*size] = new char[strlen(buffer) + 1];

	strcpy(temp[*size], buffer);

	delete[] * names;

	*names = temp;

	(*size)++;
}

/**********************************************************************
* Purpose: This function edits the name of an ingredient
*
* Precondition:
*     names - 2d array made before this function was called
*	  buffer - a string made by the user to find a string and then edit
*			   the string found
*	  size - the size of the 2d array to avoid errors
*
* Postcondition:
*     Allows the user to edit existing ingredients names
*
************************************************************************/
void EditIngredient(char ***names, char buffer[], int *size)
{
	int found = 0;
	cout << "What do you want to find: ";
	cin >> buffer;

	found = Index(*names, *size, buffer);
	if (found == -1)
	{
		cout << "That ingredient was not found" << endl;
	}
	else
	{
		cout << "What do you want to change " << buffer << " to? ";
		cin >> buffer;
		char * temp = new char [strlen(buffer)+1];

		strcpy(temp, buffer);
		delete[] (*names)[found];
		(*names)[found] = temp;
	}
}

/**********************************************************************
* Purpose: This function removes an ingredient from names
*
* Precondition:
*     names - 2d array made before this function was called
*	  buffer - a string made by the user to find a string and then edit
*			   the string found
*	  size - the size of the 2d array to avoid errors
*
* Postcondition:
*     Removes a user specified ingredient from array and size is reduced
*	  by one
*
************************************************************************/
void RemoveIngredient(char ***names, char buffer[], int *size)
{
	int found = 0;
	cout << "What do you want to delete: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(buffer, 255);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	found = Index(*names, *size, buffer);
	if (found == -1)
	{
		cout << "That ingredient was not found" << endl;
	}
	else
	{
		char ** temp = new char *[*size - 1];
		for (int i = 0; i < found; i++)
		{
			temp[i] = (*names)[i];
		}

		delete[] (*names)[found];

		for (int i = found; i < *size-1; i++)
		{
			temp[i] = (*names)[i + 1];
		}
		
		delete[] (*names);
		*names = temp;
		(*size)--;
	}
}

/**********************************************************************
* Purpose: This function finds the index of str
*
* Precondition:
*     names - 2d array made before this function was called
*	  str - a string created by the user to find a string in names
*	  size - the size of the 2d array to avoid errors
*
* Postcondition:
*     Returns where the string was found
*
************************************************************************/
int Index(char **names, int size, const char * str)
{
	int index = -1;
	int count = 0;

	while ((count < size) && (index == -1))
	{
		if (stricmp(names[count], str) != 0)
		{
			count++;
		}
		else
		{
			index = count;
		}
	}
	return index;
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
void DeleteIngredient(char ** dest, int size)
{
	for (int ii = 0; ii < size; ii++)
	{
		delete[] dest[ii];
	}

	delete[] dest;

	dest = nullptr;
}

void Purge(char ** dest, int size)
{
	for (int ii = 0; ii < size; ii++)
	{
		delete[] dest[ii];
	}

	dest = nullptr;
}