/***************************************
* Final Program
* James Nordquist
*****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int LargestNumber(int data[],int ARRAY_SIZE);
void EnterArray(int data[], int &count,int ARRAY_SIZE);

int main()
{
	const int ARRAY_SIZE = 10;
	printf("James Nordquist\n");
	int count = 0;
	int data[ARRAY_SIZE];
	int largest;

	EnterArray(data, count, ARRAY_SIZE);
	if (count != 0)
	{
		largest = LargestNumber(data, count);

		printf("The largest number is %d\n", largest);
	}
	else
	{
		printf("No valid numbers were entered\n");
	}
	return 0;
}

int LargestNumber(int data[],int ARRAY_SIZE)
{
	int temp;
	for (int ii = 0; ii < ARRAY_SIZE; ii++)
	{
		if (ii == 0)
		{
			temp = data[ii];
		}
		if (data[ii] > temp)
		{
			temp = data[ii];
		}
	
	}
	return temp;
}

void EnterArray(int data[], int &count,int ARRAY_SIZE)
{
	int temp = 0;
	while (temp >= 0 && count < ARRAY_SIZE)
	{
		if (count < ARRAY_SIZE)
		{
			printf("Enter a number, negative to exit: ");
			scanf("%d", &temp);
		}
		if (temp >= 0 && count < ARRAY_SIZE)
		{
			data[count] = temp;
			if (count != ARRAY_SIZE)
			{
				count++;
			}
		}
	}
	if (count == ARRAY_SIZE)
	{
		printf("You have entered the max amount of numbers\n");
	}
}