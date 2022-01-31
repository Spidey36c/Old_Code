#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>


int main()
{
	int value;
	double floatingPointValue;

	printf("Enter an Integer: ");
	scanf("%d", &value);
	printf("Enter a Decimal: ");
	scanf("%lf", &floatingPointValue);

	if (floatingPointValue > value)
	{
		printf("%lf\n", floatingPointValue);
		printf("Floating wins\n");
	}
	else if(value > floatingPointValue)
	{
		printf("%d\n", value);
	}
	else if (value == floatingPointValue && value < 0 || floatingPointValue < 0)
	{
		printf("They are the same, but don't be so negative");
		printf("\n");
	}
	else
	{
		printf("They are the same");
		printf("\n");
	}
}