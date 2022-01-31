#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <math.h>
// Solution to problem 1
int main1()
{
	for (int ii = 0; ii < 10; ii++)
	{
		printf("%d\n", ii);
	}


	return 0;
}

// Solution to problem 2
int main2()
{
	int num;
	printf("Enter a value, Negative to exit: ");
	scanf("%d", &num);

	while (num >= 0)
	{
		printf("Enter a value, Negative to exit: ");
		scanf("%d", &num);
	}

	return 0;
}

// Solution to problem 3
int main3()
{
	int num1 = 0;
	int num2 = 5;
	int num3 = -6;

	if (num1 >= num2 && num1 >= num3)
	{
		printf("Num1 is largest, %d", num1);
	}
	else if (num2 >= num1 && num2 >= num3)
	{
		printf("Num2 is largest, %d", num2);
	}
	else
	{
		printf("Num3 is largest, %d", num3);
	}
	printf("\n");

	return 0;
}


// Solution for problem 4
int main4()
{
	double value;
	double temp;

	printf("Enter a value you want to find the square root of: ");
	scanf("%lf", &value);

	temp = sqrt(value);
	printf("The sqaure root of %-10.0lf is %-17.3lf\n", value, temp);

	return 0;
}

// Solution for problem 5
int main5()
{
	int iterations;
	int sum=0;

	printf("Enter the number squares you want to find the sum of: ");
	scanf("%d", &iterations);

	for (int ii = 1; ii <= iterations; ii++)
	{
		sum += ii * ii;
		printf("%d * %d ", ii, ii);
		if (ii < iterations)
		{
			printf("+ ");
		}
	}
	printf("The sum is %d\n", sum);

	return 0;
}

// Solution for problem 6
int ReturnLargest(int num1, int num2, int num3);
int main6()
{
	int num1;
	int num2;
	int num3;
	int largest;

	printf("Enter the first #: ");
	scanf("%d", &num1);
	printf("Enter the second #: ");
	scanf("%d", &num2);
	printf("Enter the third #: ");
	scanf("%d", &num3);

	largest = ReturnLargest(num1, num2, num3);

	printf("The largest number is %d\n", largest);

	return 0;
}

int ReturnLargest(int num1, int num2, int num3)
{
	if (num1 >= num2 && num1 >= num3)
	{
		return num1;
	}
	else if (num2 >= num1 && num2 >= num3)
	{
		return num2;
	}
	else
	{
		return num3;
	}
}

// Solution for problem 7
int ReturnValues(int &num1,int &num2);
int main7()
{
	int num1 = 0;
	int num2 = 0;

	ReturnValues(num1, num2);

	printf("%d %d\n", num1, num2);
	return 0;
}

int ReturnValues(int &num1, int &num2)
{
	printf("Enter the first number: ");
	scanf("%d", &num1);
	printf("Enter the second number: ");
	scanf("%d", &num2);
	return 0;
}

// Solution for problem 8
int main8()
{
	const int ARRAY_SIZE = 5;
	int data[ARRAY_SIZE];

	for (int ii = 0; ii < ARRAY_SIZE; ii++)
	{
		data[ii] = 0;
	}
	for (int ii = 0; ii < ARRAY_SIZE; ii++)
	{
		printf("%d\n", data[ii]);
	}

	return 0;
}

// Solution to problem 9
double AverageArray(int data[], int numvalues);
int main9()
{
	const int ARRAY_SIZE = 5;
	int data[ARRAY_SIZE];
	double average;
	
	for (int ii = 0; ii < ARRAY_SIZE; ii++)
	{
		printf("Enter a number: ");
		scanf("%d", &data[ii]);
	}

	average = AverageArray(data, ARRAY_SIZE);

	printf("The average is %lf\n", average);

	return 0;
}

double AverageArray(int data[], int numvalues)
{
	double sum = 0;
	for (int ii = 0; ii < numvalues; ii++)
	{
		sum += data[ii];
	}
	sum = sum / numvalues;
	return sum;
}

// Solution to problem 10
int ReadFile(char *filename, int data[], int arraySize);
int main10()
{
	const int ARRAY_SIZE = 10;
	int data[ARRAY_SIZE];
	char filename[50];
	int numvalues;

	printf("Enter file name: ");
	scanf("%s", filename);

	numvalues = ReadFile(filename, data, ARRAY_SIZE);

	for (int ii = 0; ii < numvalues; ii++)
	{
		printf("%d\n", data[ii]);
	}

	printf("There are %d number of values in the file\n", numvalues);

	return 0;
}
int ReadFile(char *filename, int data[], int arraySize)
{
	FILE *input = fopen(filename, "r");
	if (input == nullptr)
	{
		printf("Unable to open %s\n", filename);
		return 0;
	}

	int value;
	int numvalues = 0;

	fscanf(input, "%d", &value);
	while (!feof(input) && numvalues < arraySize)
	{

		data[numvalues] = value;

		numvalues++;

		fscanf(input, "%d", &value);

	}

	return numvalues;
}