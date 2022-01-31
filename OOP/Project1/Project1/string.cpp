#include <iostream>
#include "string.h"
using std::cout;
using std::endl;


string::string():m_string(nullptr)
{
	m_string = new char[sizeof("") + 1];
	strcpy(m_string, "");
}

string::string(const char * string)
{
	m_string = new char[strlen(string) + 1];
	strcpy(m_string, string);
}

string::string(const string & obj) : m_string(nullptr)
{
	m_string = new char[strlen(obj.m_string) + 1];
	strcpy(m_string, obj.m_string);
}

string & string::operator=(const string & rhs)
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


string::~string()
{
}

void string::display()
{
}
