/*****************************
* Functions
*
* James Nordquist
******************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <conio.h>

double largestNumber(double first, double second, double third)
{
	if (first >= second && first >= third)
	{
		return first;
	}
	else if (second >= first && second >= third)
	{
		return second;
	}
	else
	{
		return third;
	}
}

int multiply(int numberOne, int numberTwo)
{
	numberOne *= numberTwo;
	return numberOne;
}

int main()
{
	double first;
	double second;
	double third;
	int numberOne;
	int numberTwo;

	printf("Enter the first number: ");
	scanf("%lf", &first);
	printf("Enter the second number: ");
	scanf("%lf", &second);
	printf("Enter the third number: ");
	scanf("%lf", &third);
	printf("The largest number is %lf\n", largestNumber(first, second, third));
	printf("Enter the first number: ");
	scanf("%d", &numberOne);
	printf("Enter the second number: ");
	scanf("%d", &numberTwo);
	printf("%d\n", multiply(numberOne, numberTwo));


	char exit;
	printf("Enter a key to exit");
	exit = _getch();

	return 0;
}

