/*************************************
* Switch Statement
* James Nordquist
**************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
	double value1;
	double value2;
	double result;
	int operation;

	printf("Enter a Value: ");
	scanf("%lf", &value1);

	printf("Enter a Second Value: ");
	scanf("%lf", &value2);

	printf("Select an Operation\n");
	printf("1) Addition\n");
	printf("2) Subtraction\n");
	printf("3) Multiplication\n");
	printf("4) Division\n");
	printf("> ");
	scanf("%d", &operation);

	switch (operation)
	{
	case 1:
		result = value1 + value2;
		printf("Result is %lf\n", result);
		break;
	case 2:
		result = value1 - value2;
		printf("Result is %lf\n", result);
		break;
	case 3:
		result = value1 * value2;
		printf("Result is %lf\n", result);
		break;
	case 4:
		result = value1 / value2;
		printf("Result is %lf\n", result);
		break;
	default:
		printf("Invalid Statement\n");
		break;
	}

	return 0;
}