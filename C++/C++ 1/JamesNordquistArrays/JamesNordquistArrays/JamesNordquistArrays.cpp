/******************************
* Arrays
* James Nordquist
*******************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <conio.h>

int main()
{
	const int NUM_SCORES = 5;
	int scores[NUM_SCORES];
	double sum = 0;

	for (int ii = 0; ii < NUM_SCORES; ii++)
	{
		printf("Enter a score: ");
		scanf("%d", &scores[ii]);
		sum += scores[ii];
	}
	for (int ii = 0; ii < NUM_SCORES; ii++)
	{
		printf("%d ", scores[ii]);
	}
	printf("\n");
	printf("The average is %-15.5lf\n", sum / NUM_SCORES);

	char exit;
	printf("Enter a key to exit");
	exit = _getch();
	return 0;
}