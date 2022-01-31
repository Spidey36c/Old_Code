/************************************
* Author: James Nordquist
* Filename: Exception.cpp
* Date Created: 1/7/19
* Modifications:
*
*************************************/
#include "Exception.h"
#include <iostream>
using std::endl;

Exception::Exception(): m_msg(nullptr)
{
	m_msg = new char[strlen("") + 1];
	strcpy(m_msg, "");
}

Exception::Exception(const char * msg): m_msg(nullptr)
{
	m_msg = new char[strlen(msg) + 1];
	strcpy(m_msg, msg);
}

Exception::Exception(const Exception & copy): m_msg(nullptr)
{
	m_msg = new char[strlen(copy.m_msg) + 1];
	strcpy(m_msg, copy.m_msg);
}

Exception::~Exception()
{
	delete[] m_msg;
}

Exception & Exception::operator=(const Exception & rhs)
{
	if (this != &rhs)
	{
		delete[] m_msg;

		m_msg = new char[strlen(rhs.m_msg) + 1];
		strcpy(m_msg, rhs.m_msg);
	}
	return *this;
}

const char * Exception::getMessage()
{
	return m_msg;
}

void Exception::setMessage(char * msg)
{
	delete[] m_msg;

	m_msg = new char[strlen(msg) + 1];
	strcpy(m_msg, msg);
}

ostream & operator<<(ostream & stream, const Exception & except)
{
	stream << except.m_msg << endl;
	return stream;
}
