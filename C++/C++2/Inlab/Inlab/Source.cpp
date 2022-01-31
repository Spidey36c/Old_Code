#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Header.h"

String::String():m_string(nullptr)
{
	SetString("");
	cout << "This is the default String ctor" << endl;
}

String::String(const char * string):m_string(nullptr)
{
	SetString(string);
	cout << "This is the overloaded String ctor" << endl;
}

String::String(const String & copy):m_string(nullptr)
{
	SetString(copy.m_string);
	cout << "This is the String copy ctor" << endl;
}

String & String::operator = (const String & rhs)
{
	if (this != &rhs)
	{
		delete m_string;
		if (rhs.m_string != nullptr)
		{
			m_string = new char[strlen(rhs.m_string) + 1];
			strcpy(m_string, rhs.m_string);
		}
		else
		{
			m_string = nullptr;
		}
	}
	cout << "This is the String op =" << endl;

	return *this;
}

String::~String()
{
	delete[] m_string;
	cout << "This is the default String dtor" << endl;
}

void String::SetString(const char * string)
{	
	delete[] m_string;
	m_string = new char[strlen(string) + 1];
	strcpy(m_string, string);
}

char * String::GetString() const
{
	return m_string;
}

Person::Person():m_age(0)
{
	cout << "This is the default Person ctor" << endl;
}

Person::Person(const String name, int age): m_name(name), m_age(age)
{
	cout << "This is the overloaded Person ctor" << endl;
}

Person::Person(const Person & copy):m_name(copy.m_name),m_age(copy.m_age)
{
	cout << "This is the Person copy ctor" << endl;
}

Person & Person::operator = (const Person & rhs)
{
	m_name = rhs.m_name;
	if (m_age != rhs.m_age)
	{
		m_age = rhs.m_age;
	}
	cout << "This is the Person op =" << endl;
	return *this;
}

Person::~Person()
{
	cout << "This is the default Person dtor" << endl;
}

void Person::SetName(String name)
{
	m_name = name;
}

String Person::GetName() const
{
	return m_name;
}

void Person::SetAge(int age)
{
	m_age = age;
}

int Person::GetAge() const
{
	return m_age;
}
