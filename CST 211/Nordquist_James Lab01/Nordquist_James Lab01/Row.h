/*************************************************************
* Author: James Nordquist
* Filename: Row.h
* Date Created: 1/12/19
* Modifications: 1/14/19 - op[] const compliant
*				 1/15/19 - op[] Actually const compliant
**************************************************************/
/************************************************************************
* Class: Row
*
* Purpose: This class is used to access the rows of the 2darray and get the columns
*		   required to return the desired data
*
* Manager functions:
* Row (Array2D<T> & array, int row)
*	two arg ctor, usually gets this data from Array2D class's op[] and the array passed
*	is the array that holds the desired data
*
* Methods:
* T & operator [](int index)
*	calls Array2D's select function which returns T as well
* const T & operator [](int column) const
*	a const complient version of op[]
*************************************************************************/
#ifndef ROW_H
#define ROW_H
#include <iostream>
#include "Exception.h"
template<class T>
class Array2D;
template<class T>
class Row
{
public:
	Row(Array2D<T> & array, int row);
	T & operator[](int column);
	const T & operator[](int column) const; //only be called by const objects
private:
	Array2D<T>& m_array2d;
	int m_row;
};



/**********************************************************************
* Purpose: 2 arg ctor
*
* Precondition:
* array: A 2d array given by the 2d array class itself in its op[]
* row: The desired row to get when accessing the 2d array taken from the first []
*
* Postcondition:
* Instantiates object
*
************************************************************************/
template<class T>
Row<T>::Row(Array2D<T>& array, int row): m_array2d(array), m_row(row)
{

}

/**********************************************************************
* Purpose: op[]
*
* Precondition:
* column: Desired column in 2d array. The second []
*
* Postcondition:
* returns T if column is in bounds of 2d array
*
************************************************************************/
template<class T>
T & Row<T>::operator[](int column)
{
	return m_array2d.Select(m_row, column);
}

/**********************************************************************
* Purpose: const complient op[]
*
* Precondition:
* column: Desired column in 2d array. The second []
*
* Postcondition:
* returns T if column is in bounds of 2d array
*
************************************************************************/
template<class T>
const T & Row<T>::operator[](int column) const
{
	return m_array2d.Select(m_row, column);
}

#endif