/*************************************************************
* Author: Todd Breedlove
* Filename: Minesweeper.cpp
* Date Created: 1/20/19
* Modifications: 1/21/19 - added main menu and fixed win conditions
**************************************************************/
#include "Minesweeper.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* Object is created
*
* Postcondition:
* Object is instantiated with boards default ctor
*
************************************************************************/
Minesweeper::Minesweeper(): m_board()
{
}

/**********************************************************************
* Purpose: copy ctor
*
* Precondition:
* copy: Minesweeper game data to copy to this object
*
* Postcondition:
* Minesweeper is instantiated with other objects data
*
************************************************************************/
Minesweeper::Minesweeper(const Minesweeper & copy): m_board(copy.m_board)
{
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* object goes out of scope or is specifically deleted
*
* Postcondition:
* Data is reset to default
*
************************************************************************/
Minesweeper::~Minesweeper()
{
	m_win = false;
	m_lose = false;
}

/**********************************************************************
* Purpose: op=
*
* Precondition:
* rhs: object whose data is going to be assigned to this object
*
* Postcondition:
* this object is equal to rhs object
*
************************************************************************/
Minesweeper & Minesweeper::operator=(const Minesweeper & rhs)
{
	if (this != &rhs)
	{
		m_board = rhs.m_board;
		m_win = rhs.m_win;
		m_lose = rhs.m_lose;
	}

	return *this;
}

/**********************************************************************
* Purpose: Sets the difficulty of the game by changing its size and amount
*		   of mines, chose by the player with three distinct choices.
*
* Precondition:
* function is called from object
*
* Postcondition:
* changes the size of the board and how many mines are on it.
*
************************************************************************/
void Minesweeper::SetDifficulty()
{
	string buffer;
	cout << "Select the difficulty" << endl;
	cout << "b) Beginner 10 x 10 grid with 10 mines" << endl;
	cout << "i) Intermediate 16 x 16 grid with 40 mines" << endl;
	cout << "e) Expert 16 x 30 grid with 100 mines" << endl;
	cout << ">";
	cin >> buffer;
	while (buffer != "b" && buffer != "B" && buffer != "i" && buffer != "I" && buffer != "e" && buffer != "E")
	{
		cout << "Invalid Selection" << endl;
		cout << "Select the difficulty" << endl;
		cout << "b) Beginner 10 x 10 grid with 10 mines" << endl;
		cout << "i) Intermediate 16 x 16 grid with 40 mines" << endl;
		cout << "e) Expert 16 x 30 grid with 100 mines" << endl;
		cout << ">";
		cin >> buffer;
	}

	if (buffer == "b" || buffer == "B")
	{
		m_board.GenerateBoard(10,10,10);
	}
	else if (buffer == "i" || buffer == "I")
	{
		m_board.GenerateBoard(16, 16, 40);
	}
	else if (buffer == "e" || buffer == "E")
	{
		m_board.GenerateBoard(16, 30, 100);
	}
}

/**********************************************************************
* Purpose: Allows the user to either mark or uncover a cell on the board
*		   this can either be a number, a mine, or empty. If it is a mine
*		   the game is over.
*
* Precondition:
* Function is called from object
*
* Postcondition:
* Either the game continues or the player wins or loses based on their choices
*
************************************************************************/
void Minesweeper::ChooseSquare()
{
	int selection;
	m_board.Display();
	cout << "Do you want to mark or uncover a cell?" << endl;
	cout << "1) Uncover" << endl;
	cout << "2) Mark" << endl;
	cout << ">";
	cin >> selection;
	while (selection != 1 && selection != 2)
	{
		cout << "Invalid Selection" << endl;
		cout << "Do you want to mark or uncover a cell?" << endl;
		cout << "1) Uncover" << endl;
		cout << "2) Mark" << endl;
		cout << ">";
		cin >> selection;
	}

	int x;
	int y;
	int size_y = m_board.GetBoardRows() - 1;
	int size_x = m_board.GetBoardColumns() - 1;
	cout << "Choose a Y coordinate. >";
	cin >> y;
	while (y < 0 || y > size_y)
	{
		cout << "Invalid Y coordinate" << endl;
		cout << "Choose a Y coordinate. >";
		cin >> y;
	}

	cout << "Choose a X coordinate. >";
	cin >> x;
	while (x < 0 || x > size_x)
	{
		cout << "Invalid X coordinate" << endl;
		cout << "Choose a X coordinate. >";
		cin >> x;
	}

	if (selection == 1)
	{
		if (m_board.GetCell(y, x).GetValue() != "E")
		{
			m_lose = m_board.UncoverNonEmpty(y, x);
		}
		else
		{
			m_board.UncoverEmpty(y, x);
		}
	}
	else
	{
		m_board.Mark(y, x);
	}
}

/**********************************************************************
* Purpose: checks to see if a win condition is met
*
* Precondition:
* called from object
*
* Postcondition:
* returns true if win condition is met, false if none have been met. m_win
* should be assigned to whatever this function returns
*
************************************************************************/
bool Minesweeper::Win()
{
	bool win = false;
	if ((m_board.GetUncovered() + m_board.GetMines()) == (m_board.GetBoardRows() * m_board.GetBoardColumns()))// the amount of uncovered cells plus the amount of mines should = the area of the board if the game is over
	{
		win = true;

		cout << "You have uncovered the entire field without setting off the mines! You win!" << endl;
		m_board.Display();
	}
	else if (m_board.GetMarkedMines() == m_board.GetMines() && m_board.GetMarkedMines() == m_board.GetMarked())//The player will win if only all the mines are marked and nothing else
	{
		win = true;

		cout << "You have marked all the mines on the board! You win!" << endl;
		m_board.Display();
	}
	return win;
}

/**********************************************************************
* Purpose: place to hold the game as it is being played
*
* Precondition:
* called from object
*
* Postcondition:
* Exits the game once the player chooses too
*
************************************************************************/
void Minesweeper::MainMenu()
{
	int buffer;
	cout << "Welcome to Minesweeper!" << endl;
	cout << "1) Play a game" << endl;
	cout << "2) Exit" << endl;
	cout << ">";
	cin >> buffer;
	while (buffer != 1 && buffer != 2)
	{
		cout << "Invalid Selection" << endl;
		cout << "1) Play a game" << endl;
		cout << "2) Exit" << endl;
		cout << ">";
		cin >> buffer;
	}

	while (buffer == 1)
	{
		SetDifficulty();

		while (m_win == false && m_lose == false)
		{
			ChooseSquare();

			if (m_lose == true)
			{
				m_board.Display();

				cout << "You hit a mine. Game Over" << endl;
			}
			else
			{
				m_win = Win();
			}
		}
		m_board.EmptyBoard();

		m_win = false;
		m_lose = false;

		cout << "Do you want to play again?" << endl;
		cout << "1) Yes" << endl;
		cout << "2) No" << endl;
		cout << ">";
		cin >> buffer;
		while (buffer != 1 && buffer != 2)
		{
			cout << "Invalid Selection" << endl;
			cout << "Do you want to play again?" << endl;
			cout << "1) Yes" << endl;
			cout << "2) No" << endl;
			cout << ">";
			cin >> buffer;
		}
	}
}
