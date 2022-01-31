/********************************************************************************************
* Author: James Nordquist
* Filename: Card.h
* Date Created: 2/6/19
* Modifications Made: 2/8/19 - Added Ivalue
*					  2/11/19 - added comparison operators and m_suit
***********************************************************************************************/
/************************************************************************
* Class: Card
*
* Purpose: This class creates a card that holds a value and a suit
* Manager functions:
* Card ()
*	The value is set to 0
* Card (const Card & copy)
*	Copy Ctor
* operator = (const Card & copy)
*	op =
* ~Card()
*	data is set to default or zero
*
* Methods:
* bool operator <(const Card & rhs);
*	returns true if m_ivalue < rhs.m_ivalue otherwise returns false
* bool operator >(const Card & rhs);
*	returns true if m_ivalue > rhs.m_ivalue otherwise returns false
* bool operator ==(const Card & rhs);
*	returns true if m_ivalue, m_red and m_suit are = to rhs.m_ivalue, rhs.m_red, rhs.m_suit otherwise returns false
* void SetValue(string value);
*	setter for m_value and m_ivalue based on whatever value m_value is
* void SetSuit(string suit);
*	setter for suit
* void SetRed();
*	setter for Red, makes it the opposite of whatever it is now
* string GetValue() const;
*	return m_value
* string GetSuit() const;
*	returns m_suit
* int GetIValue() const;
*	returns m_ivalue
* bool GetRed() const;
*	returns m_red
* friend ostream &operator <<(ostream & os,const Card & rhs);
*	outputs the card value and suit, text changes to red if m_red is true
*************************************************************************/
#ifndef CARD_H
#define CARD_H
#include <string>
#include <ostream>
using std::string;
using std::ostream;

class Card
{
public:
	Card();
	Card(const Card & copy);
	~Card();
	Card & operator =(const Card & rhs);
	bool operator <(const Card & rhs);
	bool operator >(const Card & rhs);
	bool operator ==(const Card & rhs);
	void SetValue(string value);
	void SetSuit(string suit);
	void SetRed();
	string GetValue() const;
	string GetSuit() const;
	int GetIValue() const;
	bool GetRed() const;
	friend ostream &operator <<(ostream & os,const Card & rhs);
private:
	string m_value;
	string m_suit;
	bool m_red = false;
	int m_ivalue;
};
#endif