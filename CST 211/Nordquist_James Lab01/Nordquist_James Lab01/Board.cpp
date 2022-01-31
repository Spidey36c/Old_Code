/*************************************************************
* Author: James Nordquist
* Filename: Board.cpp
* Date Created: 1/17/19
* Modifications: 1/20/19 - added markMines and getters for rest of data
*				 1/21/19 - fixed display marking both uncovers and generation
**************************************************************/
#include "Board.h"
#include "Cell.h"
#include <iostream>
#include <iomanip>
#include <string>
using std::string;
using std::to_string;
using std::rand;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* object is created
*
* Postcondition:
* Board is set up with no cells and no mines
*
************************************************************************/
Board::Board(): m_cells(0,0), m_uncovered(0), m_mines(0), m_marked(0), m_markMines(0)
{
}

/**********************************************************************
* Purpose: copy ctor
*
* Precondition:
* copy: object to copy over data and instantiate current object with
*
* Postcondition:
* object is instantiated with data from other object
*
************************************************************************/
Board::Board(const Board & copy): m_cells(copy.m_cells), m_uncovered(copy.m_uncovered), m_mines(copy.m_mines), m_marked(copy.m_marked), m_markMines(copy.m_markMines)
{
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* object goes out of scope or is deleted
*
* Postcondition:
* data is set to default
*
************************************************************************/
Board::~Board()
{
	EmptyBoard();
}

/**********************************************************************
* Purpose: op=
*
* Precondition:
* rhs: Object whose data is going to be used to assign the data in this object
*
* Postcondition:
* Object's data is assigned to other objects data
*
************************************************************************/
Board & Board::operator=(const Board & rhs)
{
	if (this != &rhs)
	{
		m_cells = rhs.m_cells;
		m_mines = rhs.m_mines;
		m_uncovered = rhs.m_uncovered;
		m_marked = rhs.m_marked;
		m_markMines = rhs.m_markMines;
	}

	return *this;
}

/**********************************************************************
* Purpose: Uncover cells that are not empty
*
* Precondition:
* int x,y: coordinates to the cell to be uncovered
*
* Postcondition:
* returns false if the cell uncovered is not a mine, true if it is
*
************************************************************************/
bool Board::UncoverNonEmpty(int x, int y)
{
	bool is_mine;

	if (m_cells[x][y].IsMarked() == true)
	{
		is_mine = false;
	}
	else if (m_cells[x][y].IsUncovered() == true)
	{
		is_mine = false;
	}
	else
	{
		if (m_cells[x][y].GetValue() == "X")
		{
			m_cells[x][y].Uncover();

			is_mine = true;
		}
		else
		{
			m_cells[x][y].Uncover();

			is_mine = false;
			m_uncovered++;
		}
	}
	return is_mine;
}

/**********************************************************************
* Purpose: recursive function to uncover empty cells if one is selected
*
* Precondition:
* int x,y: coordinates to current empty cell selected
*
* Postcondition:
* uncovers all connected empty cells and non empty cells
*
************************************************************************/
void Board::UncoverEmpty(int x, int y)
{
	if (m_cells[x][y].IsUncovered() == false)
	{
		m_cells[x][y].Uncover();

		m_uncovered++;
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (i >= 0 && i < m_cells.GetRow() && j >= 0 && j < m_cells.GetColumns())
				{
					if (m_cells[i][j].GetValue() == "E" && m_cells[i][j].IsUncovered() == false && m_cells[i][j].IsMarked() == false)
					{
						UncoverEmpty(i, j);
					}
					else
					{
						UncoverNonEmpty(i, j);
					}
				}
			}
		}
	}
}

/**********************************************************************
* Purpose: Marks a cell increases marked and also marked mines if the 
*		   cell marked was a mine
*
* Precondition:
* int x,y: coordinates to cell to be marked
*
* Postcondition:
* if the cells was not uncovered it is marked, or unmarked if it alread was marked
*
************************************************************************/
void Board::Mark(int x, int y)
{
	bool WasMarked = m_cells[x][y].IsMarked();

	m_cells[x][y].Mark();

	if (m_cells[x][y].IsUncovered() != true)
	{
		if (m_cells[x][y].GetValue() == "X" && WasMarked == false)
		{
			m_markMines++;
		}
		else if (m_cells[x][y].GetValue() == "X" && WasMarked == true)
		{
			m_markMines--;
		}
		if (WasMarked == false)
		{
			m_marked++;
		}
		else if (WasMarked == true)
		{
			m_marked--;
		}
	}
}

/**********************************************************************
* Purpose: Sets up the 2d array of cells and places the mines around the board
*		   randomly, and calculates the value of the cells on the board
*
* Precondition:
* size_x, size_y: desired size of board
* mines: amount of mines to place on board
*
* Postcondition:
* board is created and filled with mines and numbers
*
************************************************************************/
void Board::GenerateBoard(int size_x, int size_y, int mines)
{
	m_cells.SetRows(size_x);
	m_cells.SetColumns(size_y);

	int x;
	int y;

	while (m_mines != mines)
	{
		x = rand() % size_x;
		y = rand() % size_y;

		while (m_cells[x][y].GetValue() == "X")
		{
			x = rand() % size_x;
			y = rand() % size_y;
		}
		m_cells[x][y].SetValue("X");

		m_mines++;
	}
	for (int i = 0; i < m_cells.GetRow(); i++)
	{
		for (int j = 0; j < m_cells.GetColumns(); j++)
		{
			CalculateValue(i, j);
		}
	}
}

/**********************************************************************
* Purpose: Calculates the value of the cell by checking nearby cells for mines
*
* Precondition:
* int x,y: Coordinates to cell to calculate
*
* Postcondition:
* value is changed by amount of mines nearby, if it is not a mine already.
*
************************************************************************/
void Board::CalculateValue(int x, int y)
{
	if (m_cells[x][y].GetValue() != "X")
	{
		int value = 0;

		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (i >= 0 && i < m_cells.GetRow() && j >= 0 && j < m_cells.GetColumns())// is it in bounds
				{
					if (m_cells[i][j].GetValue() == "X") // is it a mine
					{
						if (i * m_cells.GetColumns() + j != x * m_cells.GetColumns() + y) // is it itself
						{
							value++;
						}
					}
				}
			}
		}
		if (value > 0)
		{
			m_cells[x][y].SetValue(to_string(value));
		}
	}
}

/**********************************************************************
* Purpose: Display
*
* Precondition:
* Called from object
*
* Postcondition:
* displays the board and current uncovered cells
*
************************************************************************/
void Board::Display()
{
	cout << "   ";

	for (int i = 0; i < m_cells.GetColumns(); i++)
	{
		cout << setw(3) << left << i;
	}

	cout << right << endl;

	for (int i = 0; i < m_cells.GetRow(); i++)
	{
		cout << setw(3) << left << i;

		for (int j = 0; j < m_cells.GetColumns(); j++)
		{
			cout << setw(1);

			if (m_cells[i][j].IsMarked() == false && m_cells[i][j].IsUncovered() == true)
			{
				cout << left << m_cells[i][j].GetValue() << right;
			}
			else if ((m_cells[i][j].IsMarked() == true))
			{
				cout << left << "M";
			}
			else
			{
				cout << left << " ";
			}
			cout << " |";

		}

		cout << endl;
		cout << "   ";

		for (int i = 0; i < m_cells.GetColumns(); i++)
		{
			cout << "---";
		}
		cout << endl;
	}
}

/**********************************************************************
* Purpose: getter for cells
*
* Precondition:
* int x,y: coordinates
*
* Postcondition:
* Returns specific cell if coordinates are in bounds
*
************************************************************************/
Cell Board::GetCell(int x, int y) const
{
	return m_cells[x][y];
}

/**********************************************************************
* Purpose: getter for uncovered
*
* Precondition:
* called from object
*
* Postcondition:
* returns m_uncovered
*
************************************************************************/
int Board::GetUncovered() const
{
	return m_uncovered;
}

/**********************************************************************
* Purpose: getter for mines
*
* Precondition:
* called from object
*
* Postcondition:
* returns m_mines
*
************************************************************************/
int Board::GetMines() const
{
	return m_mines;
}

/**********************************************************************
* Purpose: getter for marked
*
* Precondition:
* called from object
*
* Postcondition:
* returns marked
*
************************************************************************/
int Board::GetMarked() const
{
	return m_marked;
}

/**********************************************************************
* Purpose: getter for marked mines
*
* Precondition:
* called from object
*
* Postcondition:
* returns markedmines
*
************************************************************************/
int Board::GetMarkedMines() const
{
	return m_markMines;
}

/**********************************************************************
* Purpose: getter for amount of rows on board
*
* Precondition:
* called from object
*
* Postcondition:
* returns amount of rows on board
*
************************************************************************/
int Board::GetBoardRows() const
{
	return m_cells.GetRow();
}

/**********************************************************************
* Purpose: getter for amount of columns on board
*
* Precondition:
* called from object
*
* Postcondition:
* returns amount of columns on board
*
************************************************************************/
int Board::GetBoardColumns() const
{
	return m_cells.GetColumns();
}

/**********************************************************************
* Purpose: used to destroy object or to empty board when needed
*
* Precondition:
* called from object when object is destroyed or if board is needed to be empty for
* new data
*
* Postcondition:
* board is empty
*
************************************************************************/
void Board::EmptyBoard()
{
	m_uncovered = 0;
	m_marked = 0;
	m_mines = 0;
	m_markMines = 0;
	m_cells.SetRows(0);
	m_cells.SetColumns(0);
}
