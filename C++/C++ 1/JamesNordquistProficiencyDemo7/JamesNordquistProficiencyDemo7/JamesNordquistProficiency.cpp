#include <cstdio>



void ArrayZero(int data[],int numvalues);
int main()
{
	const int ARRAY_SIZE = 20;
	int data[ARRAY_SIZE];

	ArrayZero(data, ARRAY_SIZE);

	for (int ii = 0; ii < ARRAY_SIZE; ii++)
	{
		printf("%d\n", data[ii]);
	}

	return 0;
}
void ArrayZero(int data[], int numvalues)
{
	for (int ii = 0; ii < numvalues; ii++)
	{
		data[ii] = 0;
	}
}