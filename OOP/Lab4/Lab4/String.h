/*************************************************************
* Author: James Nordquist
* Filename: String.h
* Date Created: 10/9/18
* Modifications: 10/10/18 - comments
*				 10/16/18 - Added op =
*************************************************************/
/************************************************************************
* Class: String
*
* Purpose: This class is a self made string class to be used in the potion class
*
* Manager functions:
* String ( )
*	Defines the method of the string obj to be ""
* String(char ch)
*	assigns a single character that was passed into the function to m_string
* String(const char *str)
*	takes a character array or character pointer and assigns it to m_string
* ~String();
*	String dtor that deletes the string
* String(const String &copy);
*	copy ctor
* String & operator =(const String &rhs);
*	Op =
* void Display();
*	Displays m_string
* void Upper();
*	turns all characters in m_string into uppercase
* void Lower();
*	turns all characters in m_string into lowercase
* int length();
*	returns the length of m_string
* char *c_str();
*	returns m_string to be used in functions that require c strings
*
* Methods:
* char * m_string
*************************************************************************/
#ifndef String_h
#define String_h
#include <ostream>
using std::ostream;
class String
{
public:
	String();
	String(char ch);
	String(const char *str);
	~String();
	String(const String& copy);
	String & operator =(const String& rhs);
	bool operator ==(const String&rhs) const;
	void Display();
	void Upper();
	void Lower();
	int length();
	char *c_str();
	friend ostream & operator <<(ostream & os, const String &rhs);
private:
	char * m_string; // main method of class, used to be passed to other classes or used in main
};
#endif
