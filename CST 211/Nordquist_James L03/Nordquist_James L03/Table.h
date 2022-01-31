/********************************************************************************************
* Author: James Nordquist
* Filename : Table.h
* Date Created : 2/8/19
* Modifications Made : 2/9/19 - added CalculateMoveCards() and Win() m_efreecells and m_ecolumns
*					   2/11/19 - added m_ocards
***********************************************************************************************/
/************************************************************************
* Class:Table
*
* Purpose: This class is the main class for freecell, holds the freecells
*		   home cells and the columns
* Manager functions:
* Table ()
*	sets m_freecells arrays to size of 4, m_efreecells to 4, m_movcards to 5, and sets the size of home cells to 13
* Table (const Table & copy)
*	Copy Ctor
* operator = (const Table & copy)
*	op =
* ~Table()
*	data is set to default or zero
*
* Methods:
* void CalculateMoveCards();
*	calculates the amount of cards that can be moved, sets m_movcards to that value
* void GenerateTable();
*	fills the columns with cards from m_cards
* void Move();
*	prompts the user with move commands to move the cards around the table, then moves
*	the cards if possible
* void Display();
*	displays the current table
* void Win();
*	checks to see if the user has won the game
* void Game();
*	The "main menu" where all the functions are called to be able to play the game
*************************************************************************/
#ifndef TABLE_H
#define TABLE_H
#include "Card.h"
#include "Deck.h"
#include "ListStack.h"
#include "Stack.h"
#include "Exception.h"
#include "Array.h"
#include <ostream>
using std::ostream;

class Table
{
public:
	Table();
	Table(const Table & copy);
	~Table();
	Table & operator =(const Table & rhs);
	void CalculateMoveCards();
	void GenerateTable();
	void Move();
	void Display();
	void Win();
	void Game();
private:
	int m_efreecells;
	int m_ecolumns;
	int m_movcards; //total amount of moveable cards
	int m_ocards; //counter for how many cards are out of the columns
	Deck m_cards;
	ListStack<Card> m_columns[8];
	Array<Card> m_freecells;
	Stack<Card> m_home[4];
	bool m_win = false;
};
#endif
