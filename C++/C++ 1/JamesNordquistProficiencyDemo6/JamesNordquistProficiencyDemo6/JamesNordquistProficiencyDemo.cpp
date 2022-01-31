#include <cstdio>

int main()
{
	const int ARRAY_SIZE = 10;
	int data[ARRAY_SIZE];


	for (int ii = 0; ii < ARRAY_SIZE; ii++)
	{
		data[ii] = ii;
	}
	for (int ii = 0; ii < ARRAY_SIZE; ii++)
	{
		printf("%d\n", data[ii]);
	}
	return 0;
}