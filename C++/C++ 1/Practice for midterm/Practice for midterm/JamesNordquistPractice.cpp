/**********************
* Practice for midterm
* James Nordquist
*************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <math.h>

double calculationSin(double math);

void foo(int count, double multiplier, double factor);

int main()
{
	double math = 0;
	char states[3];
	int num_flamingos = 15;
	int numbers = 6;
	double multiplication = 2;
	double factor = 7;
	char end[1];
	
	foo(numbers, multiplication, factor);

	printf("Enter a state abbriviation: ");
	scanf("%s", &states);
	printf("%s\n", states);

	math = calculationSin(math);
	printf("The radian is %lf\n", math);

	printf("There are %d flamingos\n", num_flamingos);

	for (int i = 1; i <= 20; i+=2)
	{
		printf("%d ", i);
	}
	printf("\n");
	printf("Press any key to end the program: ");
	scanf("%c\n", &end);
	return 0;
}

void foo(int count, double multiplier, double factor)
{
	printf("The count is %d, the multipler is %lf, the factor is %lf\n", count, multiplier, factor);
}

double calculationSin(double complicatedMath)
{
	printf("Enter an angle: ");
	scanf("%lf", &complicatedMath);
	complicatedMath = sin(complicatedMath);
	return complicatedMath;
}