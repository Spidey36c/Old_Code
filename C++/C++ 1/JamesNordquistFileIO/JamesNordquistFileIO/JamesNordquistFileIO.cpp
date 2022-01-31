/*************************************
* C Style File I/O
* James Nordquist
**************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <conio.h>

int main()
{
	char first[26];
	char last[26];
	int age;
	char firstNew[26];
	char lastNew[26];
	int ageNew;

	FILE *myoutput;


	printf("Enter your first name: ");
	scanf("%s", &first);
	printf("Enter your last name: ");
	scanf("%s", &last);
	printf("Enter your age: ");
	scanf("%d", &age);

	myoutput = fopen("data.txt", "w");
	if (myoutput == nullptr)
	{
		fprintf(stderr, "Unable to open data.txt\n");
	}
	else
	{
		fprintf(myoutput, "%s %s %d\n", first, last, age);
		fclose(myoutput);
	}

	myoutput = fopen("data.txt", "r");
	if (myoutput == nullptr)
	{
		fprintf(stderr, "Unable to open data.txt\n");
	}
	else
	{
		fscanf(myoutput, "%s %s %d", &firstNew, &lastNew, &ageNew);
		printf("%s %s %d\n", firstNew, lastNew, ageNew);
		fclose(myoutput);
	}


	char exit;
	printf("Enter a key to exit");
	exit = _getch();

	return 0;
}