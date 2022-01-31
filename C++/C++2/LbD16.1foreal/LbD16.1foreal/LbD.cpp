#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int RecursivePow(int val, int mult, int amt);

int main()
{
	int val;
	int exponent;
	cout << "Enter Base ";
	cin >> val;
	cout << "\nEnter Exponent ";
	cin >> exponent;

	val = RecursivePow(val, val, exponent);

	cout << val << endl;

	return 0;
}

int RecursivePow(int val, int mult, int amt)
{
	if (amt > 1)
	{
		amt--;
		val *= mult;
		val = RecursivePow(val, mult, amt);
	}
	else if (amt == 0)
	{
		val = 1;
	}
	return val;
}