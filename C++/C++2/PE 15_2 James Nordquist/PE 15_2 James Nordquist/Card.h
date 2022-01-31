/*************************************************************
* Author:		James Nordquist
* Filename:		Card.h
* Date Created:	5/24/18
* Modifications:
**************************************************************/
#pragma once

enum Rank
{
	Ace = 1,Deuce=2,Trey=3,Four=4,Five=5,Six=6,Seven=7,Eight=8,Nine=9,Ten=10,Jack=11,Queen=12,King=13
};

enum Suit
{
	Spades,Hearts,Clubs,Diamonds
};

/************************************************************************
* Class: Card
*
* Purpose: This class sets a specific card to with m_rank and m_set
*
* Manager functions:
* 	Card(Rank rank = Ace, Suit suit = Spades);
*		base Ctor which sets m_rank and m_suit to their first possible value, 
*		ace and spades respectively, unless a rank or suit is passed to the function
*	Display()
*		Displays whatever the current m_rank and m_suit combination is
*	SetRank(Rank rank)
*		sets m_rank to rank
*	SetSuit(Suit suit)
*		sets m_suit to suit
*	GetRank()
*		returns m_rank
*	GetSuit()
*		returns m_suit
*
* Methods:
*	m_rank
*	m_suit
*************************************************************************/
class Card
{
public:
	Card(Rank rank = Ace, Suit suit = Spades);
	void Display();
	void SetRank(Rank rank);
	void SetSuit(Suit suit);
	Rank GetRank();
	Suit GetSuit();
private:
	Rank m_rank;
	Suit m_suit;
};

/************************************************************************
* Class: Card
*
* Purpose: This class sets a specific card to with m_rank and m_set
*
* Manager functions:
* 	Deck();
*		base Ctor which fills m_deck with cards of m_rank and m_suit
*	Shuffle();
*		Runs through m_deck three times randomizing m_deck
*	Deal();
*		deals one card from m_deck and checks if m_current_card is above the array of m_deck
*
* Methods:
*	m_deck
*	m_current_card
*************************************************************************/
class Deck
{
public:
	Deck();
	void Shuffle();
	Card Deal();
private:
	Card m_deck[52];
	int m_current_card;
};