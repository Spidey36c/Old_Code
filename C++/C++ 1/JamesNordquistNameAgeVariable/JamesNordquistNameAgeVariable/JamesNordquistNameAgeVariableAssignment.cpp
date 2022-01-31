#include <cstdio>

//********************************************************
// James Nordquist
//
// Name Age assignment
//********************************************************

int main()
{
	int userAge = 19;
	char userFirstName[15] = "James";
	char userLastName[30] = "Nordquist";

	printf("Name: %s %s\nAge: %d\n", userFirstName, userLastName, userAge);

	char exit[20];
	printf("\nEnter a key then press Enter to exit the program: ");
	scanf("%s", &exit);

	return 0;
}