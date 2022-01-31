/********************************
* String Chunking
* James Nordquist
*********************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>


char *My_Strtok(char *str, const char *delims);
int main()
{
	char str[50] = "  .;. ;.; ; This is .;a  ;.; ; . test";
	char str2[50] = "  .;. ;.; ; This is .;a  ;.; ; . test";

	char *chnk1 = My_Strtok(str, "; .");
	printf("First strtok: '%s'\n", chnk1);
	char *chnk2 = My_Strtok(NULL, "; .");
	printf("Second strtok: '%s'\n", chnk2);
	char *chnk3 = My_Strtok(NULL, "; .");
	printf("Third strtok: '%s'\n", chnk3);
	char *chnk4 = My_Strtok(NULL, "; .");
	printf("Fourth strtok: '%s'\n", chnk4);

	chnk1 = My_Strtok(str2, "; .");
	printf("First strtok: '%s'\n", chnk1);
	chnk2 = My_Strtok(NULL, "; .");
	printf("Second strtok: '%s'\n", chnk2);
	chnk3 = My_Strtok(NULL, "; .");
	printf("Third strtok: '%s'\n", chnk3);
	chnk4 = My_Strtok(NULL, "; .");
	printf("Fourth strtok: '%s'\n", chnk4);


	return 0;
}


char *My_Strtok(char *str, const char *delims)
{
	static char *left_off;
	if (str != NULL)
	{
		left_off = str;
	}
	char *chnk = left_off;
	char *c_ptr = chnk;

	while (strchr(delims, *left_off) != NULL)
	{
		left_off++;
	}

	chnk = left_off;

	while (strchr(delims, *left_off) == NULL)
	{
		left_off++;
	}
	*left_off = '\0';
	left_off++;

	return chnk;
}
