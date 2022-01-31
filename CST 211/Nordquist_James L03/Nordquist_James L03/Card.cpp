/********************************************************************************************
* Author: James Nordquist
* Filename: Card.cpp
* Date Created: 2/6/19
* Modifications Made: 2/8/19 - Added Ivalue
*					  2/11/19 - added comparison operators and m_suit
***********************************************************************************************/
#include <windows.h>
#include "Card.h"
#include <string>
using std::string;

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* Object is created
*
* Postcondition:
* Object is instantiated with default values;
*
************************************************************************/
Card::Card(): m_value("0"), m_ivalue(0), m_suit("N") //if the value is still 0 when displayed, something went wrong
{
}

/**********************************************************************
* Purpose: copy ctor
*
* Precondition:
* Object is created using another existing object
*
* Postcondition:
* Object is instantiated with the existing objects values
*
************************************************************************/
Card::Card(const Card & copy): m_value(copy.m_value), m_red(copy.m_red), m_ivalue(copy.m_ivalue), m_suit(copy.m_suit)
{
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* Object is deleted or goes out of scope
*
* Postcondition:
* Objects data is set to default or 0
*
************************************************************************/
Card::~Card()
{
	m_value = "0";
	m_ivalue = 0;
	m_red = false;
	m_suit = "N";
}

/**********************************************************************
* Purpose: op =
*
* Precondition:
* Object is set to equal another object
*
* Postcondition:
* Objects data is set to the same as the other objects data
*
************************************************************************/
Card & Card::operator=(const Card & rhs)
{
	if (this != &rhs)
	{
		m_value = rhs.m_value;
		m_red = rhs.m_red;
		m_ivalue = rhs.m_ivalue;
		m_suit = rhs.m_suit;
	}
	return *this;
}

/**********************************************************************
* Purpose: op <
*
* Precondition:
* rhs - another object to use in comparison
*
* Postcondition:
* returns true if m_ivalue is less than rhs.m_value otherwise false
*
************************************************************************/
bool Card::operator<(const Card & rhs)
{
	return m_ivalue < rhs.m_ivalue ? true : false;
}

/**********************************************************************
* Purpose: op >
*
* Precondition:
* rhs - another object to use in comparison
*
* Postcondition:
* returns true if m_ivalue is greater than rhs.m_value otherwise false
*
************************************************************************/
bool Card::operator>(const Card & rhs)
{
	return m_ivalue > rhs.m_ivalue ? true : false;
}

/**********************************************************************
* Purpose: op ==
*
* Precondition:
* rhs - another object to use in comparison
*
* Postcondition:
* returns true if m_ivalue is equal to rhs.m_value, and m_red is the equal to rhs.m_red
* and m_suit is equal to rhs.m_suit, otherwise false
*
************************************************************************/
bool Card::operator==(const Card & rhs)
{
	bool issame = false;
	if (m_ivalue == rhs.m_ivalue && m_red == rhs.m_red && m_suit == rhs.m_suit)
	{
		issame = true;
	}
	return issame;
}

/**********************************************************************
* Purpose: setter for m_value
*
* Precondition:
* value - desired value of card
*
* Postcondition:
* sets m_value to value and sets m_ivalue to the equivalent integer value
* of m_value
*
************************************************************************/
void Card::SetValue(string value)
{
	m_value = value;
	if (m_value == "A")
	{
		m_ivalue = 1;
	}
	else if (m_value == "J")
	{
		m_ivalue = 11;
	}
	else if (m_value == "Q")
	{
		m_ivalue = 12;
	}
	else if (m_value == "K")
	{
		m_ivalue = 13;
	}
	else
	{
		m_ivalue = stoi(m_value);
	}
}

/**********************************************************************
* Purpose: setter for m_suit
*
* Precondition:
* suit - desired suit of card
*
* Postcondition:
* sets m_suit to suit
*
************************************************************************/
void Card::SetSuit(string suit)
{
	m_suit = suit;
}

/**********************************************************************
* Purpose: setter for m_red
*
* Precondition:
* function is called
*
* Postcondition:
* sets m_red to the opposite of istelf
*
************************************************************************/
void Card::SetRed()
{
	m_red = !m_red;
}

/**********************************************************************
* Purpose: getter for m_value
*
* Precondition:
* function is called
*
* Postcondition:
* returns m_value
*
************************************************************************/
string Card::GetValue() const
{
	return m_value;
}

/**********************************************************************
* Purpose: getter for m_suit
*
* Precondition:
* function is called
*
* Postcondition:
* returns m_suit
*
************************************************************************/
string Card::GetSuit() const
{
	return m_suit;
}

/**********************************************************************
* Purpose: getter for m_ivalue
*
* Precondition:
* function is called
*
* Postcondition:
* returns m_ivalue
*
************************************************************************/
int Card::GetIValue() const
{
	return m_ivalue;
}

/**********************************************************************
* Purpose: getter for m_ivalue
*
* Precondition:
* function is called
*
* Postcondition:
* returns m_value
*
************************************************************************/
bool Card::GetRed() const
{
	return m_red;
}

/**********************************************************************
* Purpose: op <<
*
* Precondition:
* os - output stream
* rhs - desired card to output
*
* Postcondition:
* outputs the cards value and suit, in red if m_red is true
*
************************************************************************/
ostream & operator<<(ostream & os, const Card & rhs)
{
	if (rhs.m_red == true)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		os << rhs.m_value + rhs.m_suit;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	else
	{
		os << rhs.m_value + rhs.m_suit;
	}
	return os;
}
