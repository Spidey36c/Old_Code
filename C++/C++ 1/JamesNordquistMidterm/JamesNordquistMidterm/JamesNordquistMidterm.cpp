/***************************
* Midterm Option 3
* James Nordquist
****************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int firstFunction(int& num1, int& num2)
{
	printf("Enter the first number: ");
	scanf("%d", &num1);
	printf("Enter the second number: ");
	scanf("%d", &num2);

	return num1;
	return num2;
}

void secondFunction(int& num1, int& num2)
{
	if (num2 < num1)
	{
		while (num2 <= num1)
		{
			printf("%d ", num2);
			num2 += 2;
		}
	}
	else if (num1 < num2)
	{
		while (num1 <= num2)
		{
			printf("%d ", num1);
			num1 += 2;
		}
	}
	else
	{
		printf("%d", num1);
	}
	printf("\n");
}

int main()
{
	int num1;
	int num2;

	firstFunction(num1, num2);
	secondFunction(num1, num2);
	
	return 0;
}