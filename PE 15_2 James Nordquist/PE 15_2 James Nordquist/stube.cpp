/*************************************************************
* Author:		James Nordquist
* Filename:		stube.cpp
* Date Created:	5/24/18
* Modifications:	
**************************************************************/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iomanip>
using std::setw;
#include <cstdlib>
using std::srand;
using std::rand;
#include <ctime>
using std::time;
#include "Card.h"

const char * RankType[13]
{
	"Ace","Deuce","Trey","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"
};
const char * SuitType[4]
{
	"Spades","Hearts","Clubs","Diamonds"
};
/**********************************************************************
* Purpose: This function sets the specific cards rank and suit
*
* Precondition:
*     rank - a number used to access the enum Rank in Card.h
*	  suit - a number used to access the enum suit in Card.h
*
* Postcondition:
*      m_rank and m_suit are set to rank and suit respectivly
*
************************************************************************/
Card::Card(Rank rank, Suit suit)
{
	SetRank(rank);
	SetSuit(suit);
}
/**********************************************************************
* Purpose: This function outputs the specific cards rank and suit
*
* Precondition:
*
* Postcondition:
*      outputs the cards rank and suit based of the enum and the parralel
*	   array so if GetRank returns 1 and Get Suit returns 0 the output will
*	   be Ace of Spades
*
************************************************************************/
void Card::Display()
{
	cout <<	RankType[GetRank()-1] << " of " << SuitType[GetSuit()];
}
/**********************************************************************
* Purpose: This function sets the specific cards rank
*
* Precondition:
*     rank - a number used to access the enum Rank in Card.h
* Postcondition:
*      m_rank is set to rank
*
************************************************************************/
void Card::SetRank(Rank rank)
{
	m_rank = rank;
}
/**********************************************************************
* Purpose: This function sets the specific suit
*
* Precondition:
*	  suit - a number used to access the enum suit in Card.h
*
* Postcondition:
*	  m_suit is set to suit
*
************************************************************************/
void Card::SetSuit(Suit suit)
{
	m_suit = suit;
}
/**********************************************************************
* Purpose: This function returns m_rank
*
* Precondition:
*
* Postcondition:
*     m_rank is returned
*
************************************************************************/
Rank Card::GetRank()
{
	return m_rank;
}
/**********************************************************************
* Purpose: This function returns m_suit
*
* Precondition:
*
* Postcondition:
*     m_suit is returned
*
************************************************************************/
Suit Card::GetSuit()
{
	return m_suit;
}
/**********************************************************************
* Purpose: This function fills m_deck with 52 standard playing cards
*
* Precondition:
*
* Postcondition:
*     m_deck is filled and then shuffled by a seperate function
*
************************************************************************/
Deck::Deck()
{
	Card card;
	m_current_card = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			card.SetRank(static_cast<Rank>(j));
			card.SetSuit(static_cast<Suit>(i));
			m_deck[m_current_card] = card;
			m_current_card++;
		}
	}
	cout << "Done setting the deck, now shuffling" << endl;
	Shuffle();
}
/**********************************************************************
* Purpose: This function randomizes m_deck 
*
* Precondition:
*
* Postcondition:
*     m_deck is randomized and m_current_card is set back to 0 to get ready for dealing
*
************************************************************************/
void Deck::Shuffle()
{
	Card temp;
	int temp2;
	srand(time(0));
	for (int i = 0; i < 3; i++)
	{
		for (int ii = 0; ii < 52; ii++)
		{
			temp2 = rand() % 51;
			temp = m_deck[ii];
			m_deck[ii] = m_deck[temp2];
			m_deck[temp2] = temp;
		}
	}
	m_current_card = 0;
}
/**********************************************************************
* Purpose: This function sets a card to what is currently in m_deck and returns it
*
* Precondition:
*
* Postcondition:
*     card is returned and m_current_card is incremented, and if the first deck
*	  is all dealt out, it is reshuffled and starts again
*
************************************************************************/
Card Deck::Deal()
{
	Card card;
	if (m_current_card != 52)
	{
		card = m_deck[m_current_card];
		m_current_card++;
	}
	else
	{
		cout << "Out of cards reshuffling" << endl;
		Shuffle();
		card = m_deck[m_current_card];
		m_current_card++;
	}
	return card;
}