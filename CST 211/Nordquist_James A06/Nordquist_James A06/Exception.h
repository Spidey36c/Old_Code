/************************************
* Author: James Nordquist
* Filename: Exception.h
* Date Created: 1/7/19
* Modifications:
*
*************************************/
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
	const char *getMessage();
	void setMessage(char * msg);
	friend ostream& operator <<(ostream &stream, const Exception & except);
private:
	char * m_msg;
};
#endif
