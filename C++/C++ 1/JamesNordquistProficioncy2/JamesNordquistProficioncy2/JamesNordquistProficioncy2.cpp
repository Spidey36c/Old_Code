/*************************
* Proficioncy Demo 2
* James Nordquist
*/
#include <math.h>
#include <cstdio>

int main()
{
	float x = 5;
	printf("%-5.2f\n", x);
	x++;
	printf("%-5.2f\n", x);
	x = pow(x, 2) + 3 * x - 2;
	printf("%-5.2f\n", x);
	x *= 6;
	printf("%-5.2f\n", x);

	return 0;
}