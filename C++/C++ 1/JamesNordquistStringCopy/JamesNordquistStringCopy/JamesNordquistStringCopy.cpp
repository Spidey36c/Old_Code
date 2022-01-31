/********************************************
* String Copy Pointer
* James Nordquist
*********************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>


char *my_strcat(char *dest, char *source);

int main()
{
	char start[11] = "this";
	char end[5] = "that";

	printf("%s\n", start);

	printf("%s\n", my_strcat(start, end));

	printf("%s\n", start);

	return 0;
}


char *my_strcat(char *dest, char *source)
{
	char *return_val = dest;

	while (*dest != 0)
	{
		dest++;
	}
	while (*source != 0)
	{
		*dest = *source;
		dest++;
		source++;
	}

	*dest = '\0';

	return return_val;
}