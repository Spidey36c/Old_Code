/***********************************
* Lab 4 loops Loops with menus
*
* James Nordquist
************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <math.h>

int main()
{
	int menuNumber;

	printf("Make a Selection: \n");
	printf("1) Display the first X natural numbers and their sum.\n");
	printf("2) Is it a Prime Number?\n");
	printf("3) The sum of the digits of an entered number.\n");
	printf("4) Compute the series: (1/1)^1 + (1/2)^2 + (1/3)^3 + (1/4)^4 etc.\n");
	printf("5) Display a diamond you enter the height of.\n");
	printf("6) Exit the Program.\n");
	printf("> ");
	scanf("%d", &menuNumber);

	while (menuNumber >=1&& menuNumber < 6)
	{
		if (menuNumber == 1)
		{
			int sum = 0;
			int numbers = 0;
			int displayNumber;

			printf("How many Natural Numbers do you want? ");
			scanf("%d", &displayNumber);
			printf("# of Natural numbers: %d\n", displayNumber);

			while (displayNumber > 0)
			{
				displayNumber--;
				numbers++;
				sum += numbers;
				printf("%d ", numbers);
			}
			printf("\n");

			printf("Sum: %d\n\n,", sum);
		}

		if (menuNumber == 2)
		{
			int primeNumber;
			int remainder = 1;
			int dividedNumber;

			printf("Enter a Number: ");
			scanf("%d", &primeNumber);

			if (primeNumber > 0)
			{
				dividedNumber = primeNumber - 1;

				while (remainder > 0 && dividedNumber >= 2)
				{
					remainder = primeNumber % dividedNumber;
					dividedNumber--;
				}
				if (remainder == 0)
				{
					printf("The number is not prime.\n");
				}
				else
				{
					printf("The number is prime.\n");
				}
			}
			else
			{
				printf("Error\n");
			}
			printf("\n");
		}
		if (menuNumber == 3)
		{
			int ii = 1;
			int standIn;
			int enteredNumber;
			int sum = 0;

			printf("Enter a Number: ");
			scanf("%d", &enteredNumber);
			standIn = enteredNumber;

			while (standIn >= 1)
			{
				ii = standIn % 10;
				standIn /= 10;
				sum += ii;
			}
			printf("The sum of %d is %d\n\n", enteredNumber, sum);
		}
		if (menuNumber == 4)
		{
			double sum = 0;
			int enteredNumber;

			printf("Enter the number of times you want the series to iterate: ");
			scanf("%d", &enteredNumber);

			for (double aa = 1; aa <= enteredNumber; aa++)
			{
				sum += pow(1 / aa, aa);
			}
			printf("The sum is %lf\n\n", sum);
		}
		if (menuNumber == 5)
		{
			int height;

			printf("Enter Height of diamond: ");
			scanf("%d", &height);

			if (height % 2 == 0)
			{
				height -= 1;
			}
			int half = height / 2;

			for (int ii = 0; ii < half; ii++)
			{
				int numSpaces = 0;

				for (int xx = ii; xx < half; xx++)
				{
					printf(" ");
					numSpaces++;
				}
				printf("*");

				if (ii != 0)
				{
					for (int xx = half - numSpaces + ii - 1; xx > 0; xx--)
					{
						printf(" ");
					}
					printf("*");
				}
				printf("\n");
			}
			if (height >= 3)
			{
				printf("*");
				for (int ii = 0; ii < height - 2; ii++)
				{
					printf(" ");
				}
				printf("*\n");
			}
			for (int ii = half - 1; ii >= 0; ii--) 
			{
				int numSpaces = 0;

				for (int xx = ii; xx < half; xx++) 
				{
					printf(" ");
					numSpaces++;
				}
				printf("*");

				if (ii != 0) 
				{
					for (int xx = half - numSpaces + ii - 1; xx > 0; xx--)
					{
						printf(" ");
					}
					printf("*");
				}

				printf("\n");
			}
			if (height == 1)
			{
				printf("*\n");
			}
		}
	printf("Make a Selection: \n");
	printf("1) Display the first X natural numbers and their sum.\n");
	printf("2) Is it a Prime Number?\n");
	printf("3) The sum of the digits of an entered number.\n");
	printf("4) Compute the series: (1/1)^1 + (1/2)^2 + (1/3)^3 + (1/4)^4 etc.\n");
	printf("5) Display a diamond you enter the height of.\n");
	printf("6) Exit the Program.\n");
	printf("> ");
	scanf("%d", &menuNumber);
		
	}
	if (menuNumber == 6)
	{
		printf("Goodbye\n");
	}
	if (menuNumber <= 0|| menuNumber > 6)
	{
		printf("Incorrect Selection\n");
	}

	return 0;
}
