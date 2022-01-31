/***************************
* List of 8 things
* James Nordquist
****************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

// Solution for problem 1
int main1()
{
	for (int ii = 10; ii <= 20; ii++)
	{
		if (ii % 2 != 0)
		{
			printf("%d ", ii);
		}
	}
	printf("\n");
	return 0;
}

// Solution for problem 2
int main2()
{
	int num;

	printf("Enter a Value: ");
	scanf("%d", &num);

	if (num < 5)
	{
		printf("Small\n");
	}
	else if (num > 100)
	{
		printf("Large\n");
	}
	else
	{
		printf("Just Right\n");
	}


	return 0;
}


// Solution for problem 3
int main3()
{
	FILE * input;

	input = fopen("data.txt", "w");
	if (input == nullptr)
	{
		printf("Unable to open file");
	}
	else
	{
		fprintf(input, "James Nordquist");
		fclose(input);
	}
	



	return 0;
}



// Solution for problem 4
int main4()
{
	ifstream data_file("Names.txt");
	char firstName1[40];
	char lastName1[40];
	char firstName2[40];
	char lastName2[40];
	if (data_file.is_open())
	{
		data_file >> firstName1 >> lastName1;
		data_file >> firstName2 >> lastName2;

		data_file.close();
	}
	else
	{
		cout << "Error: unable to open file." << endl;
	}
	
	cout << firstName1 << " " << lastName1 << endl;
	cout << firstName2 << " " << lastName2 << endl;

	return 0;
}


// Solution for problem 5
int ValueEnter(const char *prompt, int minimum, int maximum);
int main5()
{
	int value;

	value = ValueEnter("Enter a value inbetween %d and %d: ", 1, 100);

	return 0;
}

int ValueEnter(const char *prompt, int minimum, int maximum)
{
	int value;
	printf(prompt,minimum,maximum);
	scanf("%d", &value);
	while (value < minimum || value > maximum)
	{
		printf("Value is not inbetween maximum and minimum.\n");
		printf(prompt,minimum,maximum);
		scanf("%d", &value);
	}
	return value;
}


// Solution for problem 6
void UntilNegativeValue(int &minimum, int &maximum);
int main6()
{
	int minimum = 0;
	int	maximum = 0;

	UntilNegativeValue(minimum,maximum);


	printf("%d %d", minimum, maximum);
	return 0;
}
void UntilNegativeValue(int &minimum, int &maximum)
{
	int value;
	printf("Enter a value, Negative to exit: ");
	scanf("%d", &value);
	minimum = value;
	maximum = value;
	printf("Enter a value, Negative to exit: ");
	scanf("%d", &value);
	while (value >= 0)
	{
		if (value < minimum && value >= 0)
		{
			minimum = value;
		}
		else if (value > maximum && value >= 0)
		{
			maximum = value;
		}
		printf("Enter a value, Negative to exit: ");
		scanf("%d", &value);
	}
}


// Solution for problem 7
void EnterArray(int data[], int size);
int main7()
{
	const int ARRAY_SIZE = 5;
	int data[ARRAY_SIZE];
	EnterArray(data, ARRAY_SIZE);
	for (int ii = 0; ii < ARRAY_SIZE; ii++)
	{
		printf("%d ", data[ii]);
	}
	
	return 0;
}
void EnterArray(int data[], int size)
{
	for (int ii = 0; ii < size; ii++)
	{
		data[ii] = ii;
	}
}

// Solution for problem 8
char *FindEnd(char *buff);
int main()
{
	char buff[20] = "this";
	strcpy(FindEnd(buff), " that");
	printf("%s\n", buff);
}
char *FindEnd(char *buff)
{
	while (*buff != 0)
	{
		buff++;
	}

	return buff;
}
