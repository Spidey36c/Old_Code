#include <iostream>
#include "person.h"
using std::cout;
using std::endl;

int main()
{
	person foo("foobar", 21);
	person *bar = new person;
	person foobar(foo);
	person barfoo = foo;

	*bar = foo;

	delete bar;
	return 0;
}