/******************************************
* Functions Lab
*
* James Nordquist
*******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int PromptForInteger(const char *prompt, int lowerLimit, int upperLimit);
int ageMonthDay(int& age, int& month, int& day);
void twentyFirstBirthday(int& age, int& month, int& day);

int main()
{
	int age;
	int month;
	int day;


	
	ageMonthDay(age,month,day);
	twentyFirstBirthday(age, month, day);
	
	return 0;
}

int PromptForInteger(const char *prompt, int lowerLimit, int upperLimit)
{
	int value = 0;
	printf(prompt);
	scanf("%d", &value);

	while (value<lowerLimit || value>upperLimit)
	{
		printf("Value not within limits try again: ");
		scanf("%d", &value);
	}
	return value;

}

int ageMonthDay(int& age, int& month, int& day)
{
	age = PromptForInteger("Enter your age: ", 1, 100);
	month = PromptForInteger("Enter the month of your birth as a number: ", 1, 12);
	day = PromptForInteger("Enter the day of your birth: ", 1, 31);
	return age;
	return month;
	return day;
}

void twentyFirstBirthday(int& age, int& month, int& day)
{
	int year = 2018;
	year = year - age;
	year += 21;
	if (age>=21)
	{
		if (month >= 2 && day > 21 && year==2018)
		{
			year -= 1;
			printf("Your 21st birthday was %d / %d / %d\n", month, day, year);
		}
		else
		{
			printf("Your 21st birthday was %d / %d / %d\n", month, day, year);
		}
	}
	else
	{
		printf("Your 21st birthday is %d / %d / %d\n", day, month, year);
	}
}