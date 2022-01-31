/*************************************************************
* Author: James Nordquist
* Filename: Board.h
* Date Created: 1/17/19
* Modifications: 1/18/19 - added m_uncovered and marked
*				 1/20/19 - added markMines and getters for rest of data
**************************************************************/
/************************************************************************
* Class: Board
*
* Purpose: This class holds a dynamic 2d array of cells for a game of minesweeper
*		   as well as other data to help identify win conditions
*
* Manager functions:
* Board();
*	default ctor, array's size is zero and all other data is set to zero
* Board(const Board & copy);
*	copy ctor
* ~Board();
*	default dtor calls emptyboard()
* Board & operator =(const Board & rhs);
*	op =
*
* Methods:
* bool UncoverNonEmpty(int x, int y);
*	function that uncovers a cell at coordinates x,y x being rows y being columns
*	returns a bool value, true if a mine was uncovered, false for all other cases
*	if the cell being uncovered was not already uncovered or marked m_uncovered is increased.
* void UncoverEmpty(int x, int y);
*	a function for if the cell being uncovered is empty. This function uncovers all nearby
*	cells. It also calls itself if one of the cells being uncovered is another empty cell.
*	also increases m_uncovered for the same reasons as the previous uncover function
* void Mark(int x, int y);
*	Marks the desired cell at x,y if it is already not uncovered so that it cannot be uncovered. if the cell being marked is a mine
*	it increases m_markMines and if the cell is not yet marked increases m_marked, if the cell is already marked, it unmarks it and
*	decreases the appropriate data members.
* void GenerateBoard(int size_x, int size_y, int mines);
*	Creates the 2d array using size_x and size_y and fills it randomly with mines.
*	once done filling with mines calls calculate value function for all cell
* void CalculateValue(int x, int y);
*	calculates the value of the current cell indicated by x,y and increases its value if any mines
*	are nearby. If no mines are nearby the value is E for empty, or not changed if it is already a mine.
* void Display();
*	Displays the board currently. Only displays cells values if it is uncovered.
* Cell GetCell(int x, int y) const;
*	getter for a specific cell.
* int GetUncovered() const;
*	getter for m_uncovered
* int GetMines() const;
*	getter for m_mines
* int GetMarked() const;
*	getter for m_marked
* int GetMarkedMines() const;
*	getter for m_markMines
* int GetBoardRows() const;
*	getter for the size of the boards for rows
* int GetBoardColumns() const;
*	getter for the size of the boards for columns
* void EmptyBoard();
*	sets the size of the array to zero, and sets all data back to default or zero
*************************************************************************/
#ifndef BOARD_H
#define BOARD_H
#include "Cell.h"
#include "Array2D.h"
class Board
{
public:
	Board();
	Board(const Board & copy);
	~Board();
	Board & operator =(const Board & rhs);
	bool UncoverNonEmpty(int x, int y);
	void UncoverEmpty(int x, int y);
	void Mark(int x, int y);
	void GenerateBoard(int size_x, int size_y, int mines);
	void CalculateValue(int x, int y);
	void Display();
	Cell GetCell(int x, int y) const;
	int GetUncovered() const;
	int GetMines() const;
	int GetMarked() const;
	int GetMarkedMines() const;
	int GetBoardRows() const;
	int GetBoardColumns() const;
	void EmptyBoard();
private:
	Array2D<Cell> m_cells;
	int m_uncovered;
	int m_marked;
	int m_mines;
	int m_markMines;
};
#endif