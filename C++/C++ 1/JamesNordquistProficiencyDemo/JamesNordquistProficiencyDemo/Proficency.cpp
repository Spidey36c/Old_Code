#include <cstdio>

void MultTable(int row, int collum);
int main()
{
	int row = 5;
	int collum = 8;

	MultTable(row, collum);

	return 0;
}





void MultTable(int row, int collum)
{
	printf("     ");

	for (int ii = 1; ii <= collum; ii++)
	{
		{
			printf("%5d", ii);
		}
	}
	printf("\n");
	for (int ii = 1; ii <= row; ii++)
	{

		printf("%5d", ii);
		
		for (int jj = 1; jj <= collum; jj++)
		{

			printf("%5d", jj*ii);
	
		}
		printf("\n");
	}
}