/*************************************************************
* Author: James Nordquist
* Filename: Array2D.h
* Date Created: 1/12/19
* Modifications: 1/14/19 - Made select and op[] const compliant
*				 1/15/19 - Made select and op[] Actually const compliant
**************************************************************/
/************************************************************************
* Class: Array2d
*
* Purpose: This class creates a dynamic 2d array using a dynamic 1d array
*		   by chaning the size of the 1d array in relative to the desired
*		   amount of rows and columns
*
* Manager functions:
* Array2D();
*	default ctor, array uses its own default ctor, and row and col are set to zero
* Array2D(int row, int col = 0);
*	two arg ctor, sets the array's size to row multiplied by col, m_row is set to row
*	and if no col is provided m_col is 0, otherwise m_col = col
* Array2D(const Array2D & copy);
*	copy ctor
* ~Array2D();
*	dtor sets everything to default or zero
* Array2D & operator =(const Array2D & rhs);
*	op =
*
* Methods:
* Row<T> operator[](int index);
*	returns a Row object which is then used for another bracket to return a specified data
* const Row<T> operator[](int index) const;
*	same as normal op[] but const complient
* int GetRow() const;
*	getter for row
* void SetRows(int row);
*	setter for row
* int GetColumns() const;
*	getter for columns
* void SetColumns(int col);
*	setter for columns
* T& Select(int row, int column);
*	used in conjunction with the row class created in op[] to return the desired data
* const T& Select(int row, int column) const;
*	same as normal Select but const complient
*************************************************************************/
#ifndef ARRAY2D_H
#define ARRAY2D_H
#include "Array.h"
#include "Row.h"
#include "Exception.h"
#include <iostream>

template<typename T>
class Array2D
{
public:
	Array2D();
	Array2D(int row, int col = 0);
	Array2D(const Array2D & copy);
	~Array2D();
	Array2D & operator =(const Array2D & rhs);
	Row<T> operator[](int index); //non const objects will use this
	const Row<T> operator[](int index) const; //only can be called by const objects
	int GetRow() const;
	void SetRows(int row);
	int GetColumns() const;
	void SetColumns(int col);
	T& Select(int row, int column); //non const objects will use this
	const T& Select(int row, int column) const; //only can be called by const objects
private: //making new select, array2D op[] and row op[] const and const methods will allow const methods to get the data, but not change the data
	Array<T> m_array;
	int m_row;
	int m_col;
};

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* object is created
*
* Postcondition:
* object is instantiated with array being nothing and row and col being 0
*
************************************************************************/
template<typename T>
Array2D<T>::Array2D():m_array(), m_row(0), m_col(0)
{
}

/**********************************************************************
* Purpose: 2 arg ctor can function as a 1 arg ctor
*
* Precondition:
* row: desired amount of rows
* col: desired amount of columns
*
* Postcondition:
* object is instantiated and array is set to desired size and row and col are
* set to desired size
*
************************************************************************/
template<typename T>
Array2D<T>::Array2D(int row, int col) : m_array(col * row), m_row(row), m_col(col)
{
}

/**********************************************************************
* Purpose: copy ctor
*
* Precondition:
* copy: Object to instantiate this object with its data
*
* Postcondition:
* object is instantiated with copy's data
*
************************************************************************/
template<typename T>
Array2D<T>::Array2D(const Array2D & copy) : m_array(copy.m_array), m_row(copy.m_row), m_col(copy.m_col)
{
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* object goes out of scope or is deleted
*
* Postcondition:
* data is set to default or none
*
************************************************************************/
template<typename T>
Array2D<T>::~Array2D()
{
	m_row = 0;
	m_col = 0;
}

/**********************************************************************
* Purpose: op =
*
* Precondition:
* rhs: Object whose data is going to assign this objects data
*
* Postcondition:
* Object's data is assigned to rhs's data
*
************************************************************************/
template<typename T>
Array2D<T> & Array2D<T>::operator=(const Array2D & rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;
		m_col = rhs.m_col;
		m_row = rhs.m_row;
	}
	return *this;
}

/**********************************************************************
* Purpose: op[]
*
* Precondition:
* index: desired row
*
* Postcondition:
* returns a row object to use the next bracket
*
************************************************************************/
template<typename T>
Row<T> Array2D<T>::operator[](int index)
{
	if (index > m_row || index < 0)
	{
		throw Exception("Out of bounds: Rows");
	}
	return Row<T>(*this, index);
}

/**********************************************************************
* Purpose: const complient op[]
*
* Precondition:
* index: desired row
*
* Postcondition:
* returns a const row object to use the next bracket
*
************************************************************************/
template<typename T>
const Row<T> Array2D<T>::operator[](int index) const
{
	if (index > m_row || index < 0)
	{
		throw Exception("Out of bounds: Rows");
	}
	return Row<T>(const_cast<Array2D&>(*this), index);
}

/**********************************************************************
* Purpose: getter for rows
*
* Precondition:
* called from object
*
* Postcondition:
* returns row
*
************************************************************************/
template<typename T>
int Array2D<T>::GetRow() const
{
	return m_row;
}

/**********************************************************************
* Purpose: setter for row
*
* Precondition:
* row: new desired row
*
* Postcondition:
* array's size is changed and row is set to new desired row
*
************************************************************************/
template<typename T>
void Array2D<T>::SetRows(int row)
{
	m_row = row; //similar to setlength of array as all we do is add data to the end of the array
	m_array.SetLength(m_row * m_col);
}

/**********************************************************************
* Purpose: getter for columns
*
* Precondition:
* called from object
*
* Postcondition:
* returns m_col
*
************************************************************************/
template<typename T>
int Array2D<T>::GetColumns() const
{
	return m_col;
}

/**********************************************************************
* Purpose: setter for columns
*
* Precondition:
* col: new desired amount of columns
*
* Postcondition:
* array's size is changed and col is set to new desired col
*
************************************************************************/
template<typename T> 
void Array2D<T>::SetColumns(int col) //add data between two existing data elements 0-4 are the same but 5-9 are new and 10-14 are the continuation of 0-4
{									 // example data array 1,2,3,4,5,6,7,8,9,10 example what new data array should be 1,2,3,4,5,?,?,?,?,?,6,7,8,9,10
	Array<T> temp(m_row*col);
	for (int i(0); i < m_row; i++)
	{
		for (int j(0); j < m_col && j < col; j++) //whichever is smaller m_col or col will copy the right amount into the new array
		{
			temp[i*col + j] = m_array[i*m_col + j]; //multiplying i*col in temps subscript is to make sure the right row will be selected if the array is smaller or larger
		}
	}
	m_array = temp;
	m_col = col;
}

/**********************************************************************
* Purpose: returns the desired data from the array
*
* Precondition:
* row,column: coordinates to desired data
*
* Postcondition:
* returns desired data if it is within the bounds
*
************************************************************************/
template<typename T>
T & Array2D<T>::Select(int row, int column)
{
	if (column > m_col || column < 0)
	{
		throw Exception("Out of bounds: Columns");
	}
	return m_array[row * m_col + column];
}

/**********************************************************************
* Purpose: returns the desired data from the array (const complient)
*
* Precondition:
* row,column: coordinates to desired data
*
* Postcondition:
* returns desired data if it is within the bounds
*
************************************************************************/
template<typename T>
const T & Array2D<T>::Select(int row, int column) const
{
	if (column > m_col || column < 0)
	{
		throw Exception("Out of bounds: Columns");
	}
	return m_array[row * m_col + column];
}

#endif