#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Header.h"

void StringVal(String s1);
void StringRef(String &s1);
void StringPtr(String *s1);
void StringCnstRef(const String &s1);
Person PeronsRtrn();
void PersonRef(Person &p1);
void PersonPtr(Person *p1);
void PersonCnstRef(const Person &p1);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	String s1, s2("John");
	Person p1, p2(s2,32);
	s1 = s2;
	p1 = p2;
	s2 = s2;
	p2 = p2;
	StringVal(s1);
	StringRef(s1);
	StringPtr(&s1);
	StringCnstRef(s1);
	PeronsRtrn();
	PersonRef(p1);
	PersonPtr(&p1);
	PersonCnstRef(p1);

	return 0;
}

void StringVal(String s1)
{

}
void StringRef(String &s1)
{

}
void StringPtr(String *s1)
{

}
void StringCnstRef(const String &s1)
{

}
void PersonRef(Person &p1)
{

}
void PersonPtr(Person *p1)
{

}
void PersonCnstRef(const Person &p1)
{

}
Person PeronsRtrn()
{
	Person p3("Steve", 12);

	return p3;
}