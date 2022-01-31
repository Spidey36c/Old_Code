#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath> // For pow

//*******************************************
//Total Payment Calculator
//
//James Nordquist
//*******************************************

int main()
{
	double down_Payment;
	double principal;
	double interest_Rate;
	double months_Of_Payments; //inputs
	double monthly_Payment;
	double total_Payment;
	double total_Interest; //outputs
	
	printf("Enter Down Payment: ");
	scanf("%lf", &down_Payment);

	printf("Enter Principal: ");
	scanf("%lf", &principal);

	printf("Enter Interest Rate as a decimal. 1.0 being 100%% and 1%% as 0.01: ");
	scanf("%lf", &interest_Rate);

	printf("Enter Length of Payment Plan in Months: ");
	scanf("%lf", &months_Of_Payments);

	monthly_Payment = ((principal - down_Payment) * (interest_Rate / 12)) / (1 - pow(1 + interest_Rate / 12, -months_Of_Payments));

	printf("Monthly Payments = %-8.2lf\n", monthly_Payment);

	total_Payment = monthly_Payment * months_Of_Payments;

	total_Interest = total_Payment -(principal - down_Payment);

	printf("Total Interest = %-8.2lf\n", total_Interest);

	printf("Total Payment = %9.2lf\n", total_Payment);

	char exit[20];
	printf("\nEnter a key then press Enter to exit the program: ");
	scanf("%s", &exit);

	return 0;
}