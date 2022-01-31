/********************************************************************************************
* Author: James Nordquist
* Filename : Deck.h
* Date Created : 2/6/19
* Modifications Made :
***********************************************************************************************/
#include "Deck.h"
#include <iostream>
#include <ctime>
using std::cout;
using std::endl;
using std::time;
using std::rand;
using std::srand;

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* Object is created
*
* Postcondition:
* Object is instantiated with default values
*
************************************************************************/
Deck::Deck(): m_current(0)
{
	srand(time(0));
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
Deck::Deck(const Deck & copy): m_current(copy.m_current)
{
	srand(time(0));
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* Object is deleted or goes out of scope
*
* Postcondition:
* Objects data is set to default values
*
************************************************************************/
Deck::~Deck()
{
	m_current = 0;
}

/**********************************************************************
* Purpose: op =
*
* Precondition:
* Object is set to equal another object
*
* Postcondition:
* Objects data is set to the same as the other object
*
************************************************************************/
Deck & Deck::operator=(const Deck & rhs)
{
	if (this != &rhs)
	{
		m_current = rhs.m_current;
		for (int i = 0; i < 52; i++)
		{
			m_cards[i] = rhs.m_cards[i];
		}
	}
	return *this;
}

/**********************************************************************
* Purpose: Places the cards in order in the array
*
* Precondition:
* function is called
*
* Postcondition:
* m_cards array is filled with standard card values and suits in order
*
************************************************************************/
void Deck::GenerateDeck()
{
	m_current = 0;
	for (int i = 0; i < 13; i++)
	{
		m_cards[i].SetValue(m_values[i]);
		m_cards[i].SetSuit("S");
	}
	for (int i = 13; i < 26; i++)
	{
		m_cards[i].SetValue(m_values[i % 13]);
		m_cards[i].SetSuit("C");
	}
	for (int i = 26; i < 39; i++)
	{
		m_cards[i].SetValue(m_values[i % 13]);
		m_cards[i].SetRed();
		m_cards[i].SetSuit("D");
	}
	for (int i = 39; i < 52; i++)
	{
		m_cards[i].SetValue(m_values[i % 13]);
		m_cards[i].SetRed();
		m_cards[i].SetSuit("H");
	}

	RandomizeDeck();
}

/**********************************************************************
* Purpose: randomizes the deck by swapping two cards randomly
*
* Precondition:
* function is called
*
* Postcondition:
* m_cards array is randomized
*
************************************************************************/
void Deck::RandomizeDeck()
{
	Card temp;
	int rtemp;
	for (int i = 0; i < 52; i++)
	{
		rtemp = rand() % 52;
		temp = m_cards[i];
		m_cards[i] = m_cards[rtemp];
		m_cards[rtemp] = temp;
	}
}

/**********************************************************************
* Purpose: Returns the current card
*
* Precondition:
* function is called
*
* Postcondition:
* current card is returned and m_current is incremented
*
************************************************************************/
Card Deck::Deal()
{
	Card temp = m_cards[m_current];
	m_current++;
	return temp;
}
