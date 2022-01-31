#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "List.h"

int main()
{
	int a = 10;
	int b = 16;
	int c = 5;
	int d = 18;
	int e = 14;
	int f = 15;
	float g = 3.66;
	float h = 5.01;
	float i = 2.70;
	float j = 7;
	float k = 1.243;
	string l = "John";
	string m = "Jake";
	string o = "Allie";
	List <int> itest;
	itest.insertOrdered(a);
	itest.insertOrdered(b);
	itest.insertOrdered(c);
	itest.insertOrdered(d);
	itest.insertOrdered(e);
	itest.insertOrdered(f);
	itest.display();
	List <float> ftest;
	ftest.insertOrdered(g);
	ftest.insertOrdered(h);
	ftest.insertOrdered(i);
	ftest.insertOrdered(j);
	ftest.insertOrdered(k);
	ftest.display();
	List <string> stest;
	stest.insertOrdered(l);
	stest.insertOrdered(m);
	stest.insertOrdered(o);
	stest.display();
	cout << endl;
	return 0;
}