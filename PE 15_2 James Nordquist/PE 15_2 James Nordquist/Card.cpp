/*************************************************************
* Author:		James Nordquist
* Filename:		Card.cpp
* Date Created:	5/24/18
* Modifications:	
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Programming Excercise 15.2
*
* Overview:
*	This program uses classes to create a deck of cards, shuffle them
*	then deal them.
*
* Input:
*	The input is only asking how many cards the user wishes to deal
*
* Output:
*	The output of this program will be the amount of cards the user asked
*	for dealt in sequential order of what they are in the deck
*
************************************************************/


#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Card.h"

int main()
{
	int selection;
	Deck deck;
	Card card;
	cout << "How many cards do you want to deal? ";
	cin >> selection;
	for (int i = 0; i < selection; i++)
	{
		card = deck.Deal();
		card.Display();
	}

	return 0;
}