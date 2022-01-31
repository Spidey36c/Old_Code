/***************************
* Sorting Arrays
* James Nordquist
****************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>


void SortDecreasing(int data[], int numvalues)
{
	for (int ii = 0; ii < numvalues; ii++)
	{
		for (int jj = 0; jj < numvalues - 1; jj++)
		{
			if (data[jj] < data[jj + 1])
			{
				int temp = data[jj];
				data[jj] = data[jj + 1];
				data[jj + 1] = temp;
			}
		}
	}
}

void InsertInCorrectPosition(int value, int data[], int arraySize)
{
	int pos = 0;
	while (pos < arraySize&&value > data[pos])
	{
		pos++;
	}
	if (pos < arraySize)
	{
		while (arraySize >= pos)
		{
			data[arraySize + 1] = data[arraySize];
			arraySize--;
		}
	}

	data[pos] = value;
}

int ReadData(char *filename, int data[], int arraySize)
{
	FILE *input = fopen(filename, "r");
	if (input == nullptr)
	{
		printf("Unable to open %s\n", filename);
		return 0;
	}

	int value;
	int count = 0;

	fscanf(input, "%d", &value);
	while (!feof(input) && count < arraySize)
	{

		InsertInCorrectPosition(value, data, count);
		
		count++;
		

		fscanf(input, "%d", &value);

	}

	return count;
}

void PrintData(int data[], int numvalues)
{
	for (int ii = 0; ii < numvalues; ii++)
	{
		fprintf(stdout, "%d: %d\n", ii, data[ii]);
	}

	printf("\n");

}

int main()
{
	const int ARRAY_SIZE = 100;
	int data[ARRAY_SIZE] = { 0 };
	char filename[50];

	printf("Enter file name: ");
	scanf("%s", filename);

	int count = ReadData(filename, data, ARRAY_SIZE);
	if (count != 0)
	{
		printf("Sorted in increasing order\n");

		PrintData(data, count);

		SortDecreasing(data, count);
		printf("Sorted in decreasing order\n");

		PrintData(data, count);
	}

	return 0;
}