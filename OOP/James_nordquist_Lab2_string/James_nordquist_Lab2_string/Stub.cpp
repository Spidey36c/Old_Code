#include <iostream>
#include "String.h"
using std::cout;
using std::endl;
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	char chr[] = "TesTiNG uPPer and LoWeR";
	char ch = 'A';
	String test1(chr);
	String test2(ch);
	String test3(test1);
	String test4;

	test4 = test1;

	test1.Upper();

	test1.Display();

	test1.Lower();

	test1.Display();

	return 0;
}