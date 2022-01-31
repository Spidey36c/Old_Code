/***********************
* cStrings
* James Nordquist
***********************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <ctype.h>

int main()
{
	char first[50];
	char last[50];
	char greeting[150];
	
	printf("Enter your first name: ");
	fgets(first, sizeof(first), stdin);

	first[strlen(first) - 1] = '\0';

	printf("Enter your last name: ");
	fgets(last, sizeof(last), stdin);
	
	last[strlen(last) - 1] = '\0';
	
	_strlwr(first);
	_strlwr(last);
	first[0] = toupper(first[0]);
	last[0] = toupper(last[0]);
	
	strcpy(greeting, "Hello");
	strcat(greeting, " ");
	strcat(greeting, first);
	strcat(greeting, " ");
	strcat(greeting, last);
	
	printf("%s\n", greeting);

	return 0;
}