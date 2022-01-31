/*********************************
* Compute the average of a list of numbers
*
* James Nordquist
**********************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <conio.h>

int main()
{
	
	int value;

	double sum = 0;
	int count = 0;

	printf("Enter a value (negative to exit): ");
	scanf("%d", &value);
	while (value > 0)
	{
		count++;
		sum += value;
		printf("Enter a value (negative to exit): ");
		scanf("%d", &value);
	}
	
	printf("The sum of the %d values is %-10.0lf\n", count, sum);
	printf("The average is %-10.4lf\n", sum / count);
	

	char exit;
	printf("Enter a key to exit");
	exit = _getch();
	return 0;
}