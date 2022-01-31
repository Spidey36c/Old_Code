#define _CRT_SECURE_NO_WARNING
#include <cstdio>
#include <conio.h>
//******************************************
//Expressions
//
//James nordquist
//******************************************

int main()
{
	double xX;
	double cC;
	double aA;
	double bB;

	printf("Enter a Value for X: ");
	scanf("%lf", &xX);

	cC = xX*xX + 3 * xX + 2;

	printf("Expression A: %f^2 + 3*%f + 2 = %f\n", xX, xX, cC);

	aA = ((10 + 6.0) / 9.0) * 3.5;

	printf("Expression B: ((10+6.0)/9.0)*3.5 = %f\n", aA);

	bB = (-6 + 7/4.0) / 3;

	printf("Expression C: ((-6 + (7 / 4)) / 3.0 = %f\n", bB);


	char exit;
	printf("Enter a key to exit");
	exit = _getch();

	return 0;
}