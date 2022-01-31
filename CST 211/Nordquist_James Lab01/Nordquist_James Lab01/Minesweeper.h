/*************************************************************
* Author: James Nordquist
* Filename: Minesweeper.h
* Date Created: 1/20/19
* Modifications: 1/21/19 - removed repetative functions
**************************************************************/
/************************************************************************
* Class: Minesweeper
*
* Purpose: This class is the main class for a simple minesweeper game
*		   it is used to access the board and see if the player wins or loses
*
* Manager functions:
* Minesweeper();
*	Default values are set, board is zero size with no mines
* Minesweeper(const Minesweeper & copy);
*	Copy ctor
* ~Minesweeper();
*	dtpr
* Minesweeper & operator=(const Minesweeper & rhs);
*	op =
*
* Methods:
* void SetDifficulty();
*	used to set the size of the board and how many mines there will be on it
* void ChooseSquare();
*	used to allow the user to select a cell to either uncover or mark, can
*	result in the player winning or losing
* bool Win();
*	used to check if the user has met a win condition yet. the win conditions being
*	either the user has marked all the mines and only the mines or the user has uncovered
*	all cells excluding the mines
* void MainMenu();
*	used as a way for the user to start a game, exit, or once a game is over start again
*	or exit. all other functions are called through this function
*************************************************************************/
#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "Board.h"
#include "Cell.h"

class Minesweeper
{
public:
	Minesweeper();
	Minesweeper(const Minesweeper & copy);
	~Minesweeper();
	Minesweeper & operator=(const Minesweeper & rhs);
	void SetDifficulty();
	void ChooseSquare();
	bool Win();
	void MainMenu();
private:
	Board m_board;
	bool m_win = false;
	bool m_lose = false;
};
#endif