#include <cstdio>


int main()
{
	const int ARRAY_SIZE1 = 3;
	const int ARRAY_SIZE2 = 5;
	int data[ARRAY_SIZE1][ARRAY_SIZE2] = { 0 };
	for (int ii = 0; ii < ARRAY_SIZE1; ii++)
	{
		for (int jj = 0; jj < ARRAY_SIZE2; jj++)
		{
			data[ii][jj] = ii*100 + jj;
		}
	}
	for (int ii = 0; ii < ARRAY_SIZE1; ii++)
	{
		for (int jj = 0; jj < ARRAY_SIZE2; jj++)
		{
			printf("%3d ", data[ii][jj]);
		}
		printf("\n");
	}
}