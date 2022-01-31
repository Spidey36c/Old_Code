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

	do
	{
		printf("a\n");
		for (int aa=11; aa >= 1; aa--)
		{
			if (aa % 2 != 0)
			{
				printf("%d ", aa);
			}
			
		}

		printf("\n\nb\n");
		for (int bb = 11; bb >= 1; bb--)
		{
			if (bb % 2 != 0)
			{
				printf("%d ", bb);
			}
		}

		printf("\n\nc\n");
		for (int cc = 11; cc >= 1; cc--)
		{
			if (cc % 2 != 0)
			{
				printf("%d ", cc);
			}
		}
		start++;
	} while (start == 0);

	return 0;
}