/*************************************************************
* Author: James Nordquist
* Filename: Exception.cpp
* Date Created: 1/7/19
* Modifications: 1/14/19 - one arg takes const char *
**************************************************************/
#include "Exception.h"
#include <iostream>

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* object is created
*
* Postcondition:
* object is instantiated and msg is set to nullptr
*
************************************************************************/
Exception::Exception() : m_msg(nullptr)
{

}

/**********************************************************************
* Purpose: one arg ctor
*
* Precondition:
* msg: Message to throw for exception
*
* Postcondition:
* msg is set to desired msg
*
************************************************************************/
Exception::Exception(const char * msg) : m_msg(nullptr)
{
	m_msg = new char[strlen(msg) + 1];
	strcpy(m_msg, msg);
}

/**********************************************************************
* Purpose: copy ctor
*
* Precondition:
* copy: object whose data is going to be copied to assign and instantiate this object
*
* Postcondition:
* object's data is assigned to copys data and is instantiated
*
************************************************************************/
Exception::Exception(const Exception & copy) : m_msg(nullptr)
{
	m_msg = new char[strlen(copy.m_msg) + 1];
	strcpy(m_msg, copy.m_msg);
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* object goes out of scope or is deleted
*
* Postcondition:
* data is set to default
*
************************************************************************/
Exception::~Exception()
{
	delete[] m_msg;
	m_msg = nullptr;
}

/**********************************************************************
* Purpose: op=
*
* Precondition:
* rhs: object whose data is going to assign this objects data
*
* Postcondition:
* this objects data is assigned to rhs's data
*
************************************************************************/
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

/**********************************************************************
* Purpose: getter for msg
*
* Precondition:
* called from object
*
* Postcondition:
* returns msg
*
************************************************************************/
const char * Exception::getMessage() const
{
	return m_msg;
}

/**********************************************************************
* Purpose: setter for msg
*
* Precondition:
* msg: new exception msg
*
* Postcondition:
* msg is set to new desired msg
*
************************************************************************/
void Exception::setMessage(char * msg)
{
	delete[] m_msg;

	m_msg = new char[strlen(msg) + 1];
	strcpy(m_msg, msg);
}

/**********************************************************************
* Purpose: op <<
*
* Precondition:
* stream: ostream to output msg
* except: this exception object
*
* Postcondition:
* outputs the msg in the ostream object
*
************************************************************************/
ostream & operator<<(ostream & stream, const Exception & except)
{
	stream << except.m_msg << endl;
	return stream;
}
