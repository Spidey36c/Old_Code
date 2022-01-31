/*************************************************************
* Author: James Nordquist
* Filename: Cell.cpp
* Date Created: 1/17/19
* Modifications: 1/20/19 - Fixed marking
**************************************************************/
#include "Cell.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* object is created
*
* Postcondition:
* object is instantiated and value is set to empty
*
************************************************************************/
Cell::Cell(): m_value("E")
{
}

/**********************************************************************
* Purpose: one arg ctor
*
* Precondition:
* value: value to set the current value of the cell
*
* Postcondition:
* object is instantiated and value is set to desired value of cell
*
************************************************************************/
Cell::Cell(string value): m_value(value)
{
}

/**********************************************************************
* Purpose: copy ctor
*
* Precondition:
* copy: object whose data is going to be copied to this object
*
* Postcondition:
* data from copy is copied and data from cell is assigned to it
*
************************************************************************/
Cell::Cell(const Cell & copy):m_value(copy.m_value), m_marked(copy.m_marked), m_uncovered(copy.m_uncovered)
{
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* object goes out of scope or is specifically deleted
*
* Postcondition:
* object is set back to default values
*
************************************************************************/
Cell::~Cell()	//string value will call its own dtor
{
	m_marked = false;
	m_uncovered = false;
}

/**********************************************************************
* Purpose: op =
*
* Precondition:
* rhs: object whose data is going to assign the data from this object
*
* Postcondition:
* this objects data is assigned to rhs objects data
*
************************************************************************/
Cell & Cell::operator=(const Cell & rhs)
{
	if (this != &rhs)
	{
		m_value = rhs.m_value;
		m_marked = rhs.m_marked;
		m_uncovered = rhs.m_uncovered;
	}
	return *this;
}

/**********************************************************************
* Purpose: marks the cell so that when displayed it will not displays its value
*		   or unmarks to cell if already marked
*
* Precondition:
* called from object
*
* Postcondition:
* m_marked is true if the cell is not marked, m_marked is false if cell is
* already marked
*
************************************************************************/
void Cell::Mark()
{
	if (m_marked != true && m_uncovered == false) //if cell is already marked unmark it
	{
		m_marked = true;
	}
	else
	{
		m_marked = false;
	}
}

/**********************************************************************
* Purpose: uncovers the cell so its value can be seen
*
* Precondition:
* called from object
*
* Postcondition:
* cell is uncovered and if it is already uncovered it doesn't bother with
* reassignment
*
************************************************************************/
void Cell::Uncover()
{
	if (m_uncovered == false) //So time isn't wasted on reassigning a true bool to be true again
	{
		m_uncovered = true;
	}
}

/**********************************************************************
* Purpose: setter for value
*
* Precondition:
* value: desired new value for cell
*
* Postcondition:
* value is changed to new value
*
************************************************************************/
void Cell::SetValue(string value)
{
	m_value = value;
}

/**********************************************************************
* Purpose: getter for value
*
* Precondition:
* called from object
*
* Postcondition:
* returns value
*
************************************************************************/
string Cell::GetValue()
{
	return m_value;
}

/**********************************************************************
* Purpose: getter for m_marked
*
* Precondition:
* called from object
*
* Postcondition:
* returns m_marked
*
************************************************************************/
bool Cell::IsMarked()
{
	return m_marked;
}

/**********************************************************************
* Purpose: getter for m_uncovered
*
* Precondition:
* called from object
*
* Postcondition:
* returns m_uncovered
*
************************************************************************/
bool Cell::IsUncovered()
{
	return m_uncovered;
}
