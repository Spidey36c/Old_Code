/**************************************
*Looping
*James Nordquist
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
	int value;
	int start = 0;

	for (int ii = 0; ii < 10; ii++)
	{
		printf("%d\n", ii);
	}

	printf("Enter value. Negative to stop: ");
	scanf("%d", &value);

	while (value >= 0)
	{
		printf("%d\n", value);

		printf("Enter value. Negative to stop: ");
		scanf("%d", &value);
	}

	char letter = 'a';
	do
	{
		printf("%c\n", letter);
		for (int aa = 11; aa >= 1; aa--)
		{
			if (aa % 2 != 0)
			{
				printf("%d ", aa);
			}

		}
		printf("\n");
		letter++;
	} while (letter <= 'c');

	return 0;
}