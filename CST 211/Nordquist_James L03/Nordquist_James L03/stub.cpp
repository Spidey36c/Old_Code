/*************************************************************
* Author: James Nordquist
* Filename: stub.cpp
* Date Created: 2/8/19
* Modifications: 
**************************************************************/
#include "Table.h"
/*************************************************************
*
* Lab/Assignment: Lab 3 – Freecell
*
* Overview:
* This program is a game of freecell using personally made
* stack objects and card objects. The game will end when
* all cards are on the home cells
*
* Input:
* The input will consist of move commands by the player
* given in the format
*
*		  from   to
*	<cmd> <int> <int>
*
* Output:
* The output of this program will be the current play area
* anytime a command is made, even if no changes are made.
* Once the user wins the game, a the user is prompted if they
* want to play again
*
************************************************************/
int main()
{
	Table play;
	play.Game();

	return 0;
}