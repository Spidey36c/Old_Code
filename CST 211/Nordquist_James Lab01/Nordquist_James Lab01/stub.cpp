/*************************************************************
* Author: James Nordquist
* Filename: Stub.cpp
* Date Created: 1/21/19
* Modifications: 1/21/19 – Added Srand to seed any randomizers
**************************************************************/
/*************************************************************
*
* Lab/Assignment: Lab 1 – Minesweeper
*
* Overview:
* This program is a simple ASCII version of minesweeper.
* The user will choose whether or not they want to play
* and if they chose to play the difficulty of the game.
* Once difficulty is selected a board is generated and the 
* user has the option to uncover or mark cells on the board.
* The game will end once the user either uncovers a mine or
* uncovers all cells besides the ones with mines or marks all
* the mines.
*
* Input:
* The input will consist of integers for menu and cell selection
* and of characters for difficulty selection.
*
* Output:
* The output of this program will be the current board and its cells
* as well as a win or lose message.
*
************************************************************/
#include <iostream>
#include "Minesweeper.h"
#include <ctime>
#include <crtdbg.h>
using std::time;
using std::srand;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(0));
	Minesweeper game;
	game.MainMenu();

	return 0;
}