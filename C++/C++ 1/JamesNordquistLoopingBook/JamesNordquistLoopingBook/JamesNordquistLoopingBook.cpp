/**************************************
* Book Problem pg.230 problem 1)
*James Nordquist
**************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
	int days;
	int dayNumber = 0;
	int money = 0;

	printf("Enter the amount of days between 1-30: ");
	scanf("%d", &days);

	if (days <= 30 && days >= 1)
	{
		while (days >= 1)
		{
			money *= 2;
			money += 1;
			dayNumber++;
			printf("Day %d %d\n",dayNumber, money);
			days--;
		}
	}
	else
	{
		printf("Number of days is not between 1-30\n");
	}


	return 0;
}