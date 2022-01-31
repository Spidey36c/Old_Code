/*************************************************************
* Author: James Nordquist
* Filename: String.cpp
* Date Created: 10/9/18
* Modifications: 10/10/18 - Comments
*				 10/16/18 - Added op =
*************************************************************/
#include <iostream>
#include "String.h"
using std::cout;
using std::endl;

String::String():m_string(nullptr)
{
	cout << "String default ctor called" << endl;
	m_string = new char[strlen("") + 1];
	strcpy(m_string, "");
}

String::String(char ch) : m_string(nullptr)
{
	cout << "String character ctor called" << endl;
	m_string = new char[strlen(&ch) + 1];
	strcpy(m_string, &ch);
	if (m_string == nullptr)
	{
		throw - 1;
	}
}

String::String(const char* chr): m_string(nullptr)
{
	cout << "String const character ptr ctor called" << endl;
	m_string = new char[strlen(chr) + 1];
	strcpy(m_string, chr);
	if (m_string == nullptr)
	{
		throw - 1;
	}
}


String::~String()
{
	cout << "String dtor called" << endl;
	delete[] m_string;
}

String::String(const String & copy): m_string(nullptr)
{
	cout << "String copy ctor called" << endl;
	m_string = new char[strlen(copy.m_string) + 1];
	strcpy(m_string, copy.m_string);
	if (m_string == nullptr)
	{
		throw - 1;
	}
}

String & String::operator=(const String & rhs)
{
	cout << "String op = called" << endl;
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

bool String::operator==(const String & rhs) const
{
	return strcmp(m_string, rhs.m_string) == 0 ? true : false;
}

void String::Display()
{
	cout << m_string << endl;
}

void String::Upper()
{
	cout << "String to upper called" << endl;
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
	cout << "String to lower called" << endl;
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

int String::length()
{
	cout << "String length called" << endl;
	int length = 0;
	char *strptr = m_string;

	while (*strptr != 0)
	{
		strptr++;
		length++;
	}
	return length;
}

const char * String::c_str()
{
	cout << "String c string called" << endl;
	return m_string;
}
