#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Header.h"

void CoolStuff(Sample s1);
void Stuff();
int main()
{
	Sample s1(18), s2[5];
	Sample test = s1;
	Sample test2(s1);
	s2[1] = test;
	CoolStuff(s1);
	Stuff();
	return 0;
}

void Stuff()
{
	Sample t1;
}
void CoolStuff(Sample s1)
{

}