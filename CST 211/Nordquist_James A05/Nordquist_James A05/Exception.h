/*************************************************************
* Author: James Nordquist
* Filename: Exception.h
* Date Created: 1/7/19
* Modifications: 1/14/19 - one arg takes const char *
**************************************************************/
/************************************************************************
* Class: Exception
*
* Purpose: This class creates a dynamic one-dimensional array that can be * started at any base.
*
* Manager functions:
* Exception();
*	default ctor msg is set to nullptr
* Exception(const char *msg);
*	one arg ctor where m_msg is set to msg
* Exception(const Exception & copy);
*	copy ctor
* ~Exception();
*	dtor
* Exception & operator =(const Exception & rhs);
*	op =
*
* Methods:
* const char *getMessage() const;
*	getter for m_msg
* void setMessage(char * msg);
*	setter for m_msg
* friend ostream& operator <<(ostream &stream, const Exception & except);
*	extraction operator used to output the msg in the ostream
*************************************************************************/
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <ostream>
#include <iostream>
using std::endl;
using std::ostream;
class Exception
{
public:
	Exception();
	Exception(const char *msg);
	Exception(const Exception & copy);
	~Exception();
	Exception & operator =(const Exception & rhs);
	const char *getMessage() const;
	void setMessage(char * msg);
	friend ostream& operator <<(ostream &stream, const Exception & except);
private:
	char * m_msg;
};
#endif
