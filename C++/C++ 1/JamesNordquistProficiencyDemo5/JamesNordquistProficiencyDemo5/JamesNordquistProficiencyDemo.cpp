#include <cstdio>

void printAllNumbers(int ii, int jj);

int main()
{
	
	
	printAllNumbers(-2, 5);
	printf("\n");
	printAllNumbers(10, 0);
	
	return 0;
}

void printAllNumbers(int ii, int jj)
{
	if (ii >= jj)
	{
		while (ii >= jj)
		{
			printf("%d ", ii);
			ii--;
		}
	}
	if (ii <= jj)
	{
		while (ii <= jj)
		{
			printf("%d ", ii);
			ii++;
		}
	}
}