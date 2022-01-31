//***********************************************************
// Wage Table for Three Employees
//
// James Nordquist
//***********************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
	float wage;
	float wage2;
	float wage3;
	char name[21];
	char name12[21];
	char name2[21];
	char name22[21];
	char name3[21];
	char name32[21];


	printf("Enter First Employee First Name: ");
	scanf("%s", name);

	printf("Enter First Employee Last Name: ");
	scanf("%s", name12);

	printf("Enter First Employee Hourly Wages: ");
	scanf("%f", &wage);

	printf("Enter Second Employee First Name: ");
	scanf("%s", name2);

	printf("Enter Second Employee Last Name: ");
	scanf("%s", name22);

	printf("Enter Second Employee Hourly Wages: ");
	scanf("%f", &wage2);

	printf("Enter Third Employee First Name: ");
	scanf("%s", name3);

	printf("Enter Third Employee Last Name: ");
	scanf("%s", name32);

	printf("Enter Third Employee Hourly Wages: ");
	scanf("%f", &wage3);

	printf("\n%-21s %-21s %8s\n", "First Name", "Last Name", "Hourly Wages");
	printf("%-21s %-21s $%8.2f\n", name, name12, wage);
	printf("%-21s %-21s $%8.2f\n", name2, name22, wage2);
	printf("%-21s %-21s $%8.2f\n", name3, name32, wage3);

	char exit[20];
	printf("Enter a key then press Enter to exit the program: ");
	scanf("%s",&exit)

	return 0;
}