#include <iostream>
#include "String.h"
using std::cout;
using std::endl;

String::String():m_string(nullptr)
{
	m_string = new char[strlen("") + 1];
	strcpy(m_string, "");
}

String::String(char ch) : m_string(nullptr)
{
	m_string = new char[strlen(&ch) + 1];
	strcpy(m_string, &ch);
}

String::String(char * str): m_string(nullptr)
{
	m_string = new char[strlen(str) + 1];
	strcpy(m_string, str);
}


String::~String()
{
	delete[] m_string;
}

String::String(const String & copy): m_string(nullptr)
{
	m_string = new char[strlen(copy.m_string) + 1];
	strcpy(m_string, copy.m_string);
}

String & String::operator=(const String & rhs)
{
	// 1. Check for self assignment
	if (this != &rhs)
	{
		// 2. Purge the left hand side
		delete[] m_string;

		// 3. Make the deep copy
		m_string = new char[strlen(rhs.m_string) + 1];
		strcpy(m_string, rhs.m_string);
	}
	// 4. Return reference to self
	return *this;
}

void String::Display()
{
	cout << m_string << endl;
}

void String::Upper()
{
	char *strptr = m_string;
	while (*strptr != 0)
	{

		if (*strptr >= 97 && *strptr <= 122)
		{
			*strptr = *strptr - 32;
		}
		strptr++;
	}
}

void String::Lower()
{
	char *strptr = m_string;
	while (*strptr != 0)
	{
		if (*strptr >= 65 && *strptr <= 90)
		{
			*strptr = *strptr + 32;
		}
		strptr++;
	}
}
