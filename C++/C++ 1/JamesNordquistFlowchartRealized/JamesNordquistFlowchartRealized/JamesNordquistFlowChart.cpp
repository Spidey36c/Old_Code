/******************************
* Flow Chart to Code
* James Nordquist
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <conio.h>

int main()
{
	int numerator;
	int denominator;
	int wholeNumber = 0;
	int remainder;


	printf("Enter a Numerator: ");
	scanf("%d", &numerator);
	
	printf("Enter a Denominator: ");
	scanf("%d", &denominator);


	if (denominator == 0)
	{
		printf("Error. Cannot Divide by Zero\n");
	}
	else
	{
		if (numerator > denominator)
		{
			wholeNumber = numerator / denominator;
			remainder = numerator % denominator;

			if (wholeNumber == 0)
			{
				if (remainder == 0)
				{
					printf("%d\n", wholeNumber);
				}
				else
				{
					printf("%d/%d\n", remainder, denominator);
				}

			}
			else
			{
				if (remainder == 0)
				{
					printf("%d\n", wholeNumber);
				}
				else
				{
					printf("%d %d/%d\n", wholeNumber, numerator, denominator);
				}
			}
		}
		else
		{
			if (numerator == 0)
			{
				printf("%d\n", wholeNumber);
			}
			else
			{
				printf("%d/%d\n", numerator, denominator);
			}
		
		}

	}


	char exit;
	printf("Enter a key to exit");
	exit = _getch();
	return 0;
}