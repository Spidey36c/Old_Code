//*****************************************************************
//
// Author: Philip Howard
//
// Purpose: To provide a debugging challenge for my CST 116 class
//
// Part 1: Since index is increasing faster than value, why doesn't the result keep
// getting bigger? Use the debugger to figure this out. 
// 
// Part 2: If index increases faster, say by 3 or 5 or 10, will you get different behavior?
//
// Part 3: Maybe more iterations will help. Change the number of iterations to 1000 and see
// what happens
//
// Part 4: Be prepared to show me the following:
//    a) what values the variables have when the problem occurs.
//    b) How to set a breakpoint to stop the program immediately before the problem occurs. 
//       In other words, you should be able to run in the debugger and the first time it stops,
//       if you press step over, the program crashes.
//    c) Be able to explain why the problem occurs, and how to fix it.
//
#include <cstdio>

int main()
{
	unsigned char value = 1;

	for (int index = 1; index < 1000; index += 2)
	{
		double result = static_cast<double>(index) / value;

		printf("Result is %lf\n", result);

		value++; // When this increases, it causes index/value to truncate and eventually hit a maximum and prints the same number
	}
}