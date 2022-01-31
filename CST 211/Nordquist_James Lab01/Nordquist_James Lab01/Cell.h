/*************************************************************
* Author: James Nordquist
* Filename: Cell.h
* Date Created: 1/17/19
* Modifications:
**************************************************************/
/************************************************************************
* Class: Cell
*
* Purpose: This class holds a value for a cell in a array or board for a
*		   minesweeper game
*
* Manager functions:
* Cell();
*	default ctor Value is set to E for empty
* Cell(string value);
*	one arg ctor m_value is set to value
* Cell(const Cell & copy);
*	copy ctor
* ~Cell();
*	dtor
* Cell & operator =(const Cell & rhs);
*	op =
*
* Methods:
* void Mark();
*	Sets the cells m_marked bool value to true. if cells m_marked is already true
*	sets m_marked to false
* void Uncover();
*	Sets the cells m_uncovered bool value to true. if m_uncovered is already true
*	doesn't bother with assignment
* void SetValue(string value);
*	setter for m_value
* string GetValue();
*	getter for m_value
* bool IsMarked();
*	getter m_marked
* bool IsUncovered();
*	getter for m_uncovered
*************************************************************************/
#ifndef CELL_H
#define CELL_H
#include <string>
using std::string;
class Cell
{
public:
	Cell();
	Cell(string value);
	Cell(const Cell & copy);
	~Cell();
	Cell & operator =(const Cell & rhs);
	void Mark();
	void Uncover();
	void SetValue(string value);
	string GetValue();
	bool IsMarked();
	bool IsUncovered();
private:
	string m_value; //1-8 normal M marked(not actually a value) E empty X mine
	bool m_marked = false;
	bool m_uncovered = false;
};






#endif