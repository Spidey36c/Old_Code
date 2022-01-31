/**********************************************************************/
/* SYNOPSIS:                                                          */
/*      This program is designed to build Pascal's Triangle. Below is */
/* an example of Pascal's Triangle.                                   */
/*            1                                                       */
/*          1   1                                                     */
/*        1   2   1                                                   */
/*      1   3   3   1                                                 */
/*    1   4   6   4   1                                               */
/* Pascal's Triangle is used in figuring the coeficients of a         */
/* polynomial. For example, (x + y)^2 is equal to 1x^2 + 2xy + 1y^2.  */
/* As you can see the coeficients are the same as the third row of the*/
/* triangle (index 2). This lab will build the triangle and print it  */
/* to the screen.                                                     */
/*                                                                    */
/* INPUT:                                                             */
/*     The user will input a number which will represent the power of */
/* the equation. The program will take this input and add 1 to it for */
/* the number of rows in the triangle.                                */
/*                                                                    */
/* OUTPUT:                                                            */
/*      The output will be the triangle printed to the screen in      */
/* triangular form.                                                   */
/**********************************************************************/
#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::setw;

const int MAX_POWER = 13;
const int MAX_FILENAME = 255;

void GetPower(int & power);
void GetFilename(char filename[]);
void ConvertToUpper(char filename[]);
void InitPascal(int & power, int pascal_tri[MAX_POWER][MAX_POWER]);
void PrintPascal(char filename[], int power, int pascal_tri[MAX_POWER][MAX_POWER]);

int main()
{
	int power;
	int pascal_tri[MAX_POWER][MAX_POWER];
	char filename[MAX_FILENAME];

	GetPower(power);
	GetFilename(filename);
	InitPascal(power, pascal_tri);
	PrintPascal(filename, power, pascal_tri);
	return 0;
}
void GetPower(int & power)
{
	char str[3];

	cout << "Please enter the power of the equation (1 - " << MAX_POWER - 1 << "): ";
	cin >> power;

	while (power > MAX_POWER || power <= 0)
	{
		cout << "You have entered an invalid power.";
		cout << "\nThe number must be from 1 to " << MAX_POWER - 1;
		cout << "\n\nPress the enter key to try again";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(str, 2, '\n');
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Please enter the power of the equation (1 - " << MAX_POWER << "): ";
		cin >> power;
	}
}


void GetFilename(char filename[])
{
	cout << "Please enter the filename for the report: ";
	cin >> filename;
	ConvertToUpper(filename);
}
void ConvertToUpper(char filename[])
{
	int length, count;

	length = int(strlen(filename));
	cout << "\n\nConverted string: ";

	// This converts the string to all uppercase 
	for (count = 0; count < length; count++)
	{
		if (filename[count] >= 97 && filename[count] <= 122)
		{
			filename[count] -= 32;
		}
		cout << filename[count];
	}
	cout << endl;
}
void InitPascal(int & power, int pascal_tri[MAX_POWER][MAX_POWER])
{
	int row, col;

	for (row = 0; row <= power; row++)
	{
		for (col = 0; col <= row; col++)
		{
			// Left side of triangle 
			if (col == 0)
			{
				pascal_tri[row][col] = 1;
			}
			// Right side of triangle 
			else if (row == col)
			{
				pascal_tri[row][col] = 1;
			}
			// Middle of triangle 
			else
			{
				pascal_tri[row][col] = pascal_tri[row - 1][col - 1] + pascal_tri[row - 1][col];
			}
		}
	}
}
void PrintPascal(char filename[], int power, int pascal_tri[MAX_POWER][MAX_POWER])
{
	int row;
	int col;
	int space;
	char str[3];
	
	cout << "This is Pascal's triangle for the power of " << power << "\n\n\n";
	ofstream report(filename);
	if (report.fail())
	{
		cout << "Unable to open the file";
		cout << "\n\nPress the enter key to try again";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(str, 2, '\n');
		cin.ignore(cin.rdbuf()->in_avail());
	}
	else
	{
		report << "This is Pascal's triangle for the power of " << power << "\n\n\n";

		for (row = 0; row <= power; row++)
		{
			for (space = 0; space < 37 - (row * 3); space++)
			{
				report << " ";
			}
		for (col = 0; col <= row; col++)
		{
			report << setw(6) << pascal_tri[row][col];
		}
		report << endl;
	}
	report.close();
	}
	for (row = 0; row <= power; row++)
	{
		for (space = 0; space < 37 - (row * 3); space++)
		{
			cout << " ";
		}
		for (col = 0; col <= row; col++)
		{
			cout << setw(6) << pascal_tri[row][col];
		}
		cout << endl;
	}
}





