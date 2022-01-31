/********************************************************************************************
* Author: James Nordquist
* Filename : Deck.h
* Date Created : 2/6/19
* Modifications Made :
*********************************************************************************************** /
/************************************************************************
* Class:Deck
*
* Purpose: This class holds an array of cards as well as a string array of the cards values.
*		   Can also deal cards out of its array
* Manager functions:
* Deck ()
*	m_current is set to 0 and a seed for rand() is made
* Deck (const Deck & copy)
*	Copy Ctor
* operator = (const Deck & copy)
*	op =
* ~Deck()
*	data is set to default or zero
*
* Methods:
* Card & operator[](int index);
*	returns the card at index
* void GenerateDeck();
*	fills the card array with cards from a standard deck in order. I.E. A-K Spades A-K Clubs A-K Diamonds A-K Hearts
* void RandomizeDeck();
*	Randomizes the cards by swapping them randomly
* Card Deal();
*	sets a temp to m_cards[m_current], increments current and then returns the temp
*************************************************************************/
#ifndef DECK_H
#define DECK_H
#include <string>
#include "Card.h"
using std::string;

class Deck
{
public:
	Deck();
	Deck(const Deck & copy);
	~Deck();
	Deck & operator = (const Deck & rhs);
	void GenerateDeck(); //places cards in the deck in order
	void RandomizeDeck();
	Card Deal();
private:
	Card m_cards[52];
	int m_current;
	string m_values[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
};
#endif
