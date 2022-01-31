#include <cstdio>

int main()
{
	int userNumber;
	int firstNumber = 0;
	int secondNumber = 0;
	int sum = 0;
	int total = 0;

	printf("Enter a number: ");
	scanf("%d", &userNumber);
	while (userNumber > 0)
	{
		firstNumber++;
		secondNumber++;
		sum = firstNumber * secondNumber;
		total += sum;
		userNumber--;
	}
	printf("%d\n", total);


	return 0;
}