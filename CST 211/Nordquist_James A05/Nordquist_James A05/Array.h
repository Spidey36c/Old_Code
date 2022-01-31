/********************************************************************************************
* Author: James Nordquist
* Filename: Array.h
* Date Created: 1/7/19
* Modifications Made: 1/7/19 - Made Class Canonical and added necessary functions and data from UML
*					  1/8/19 - Worked on throwing exceptions
***********************************************************************************************/
/************************************************************************
* Class: Array
*
* Purpose: This class creates a dynamic one-dimensional array that can be started at any index.
*
* Manager functions:
* Array ()
*	The array is set to nullptr and size and index is zero
* Array (int length, int start_index = 0)
*	Creates the desired sized array with the starting index, zero if none is given
* Array (const Array & copy)
*	Copy Ctor
* operator = (const Array & copy)
*	op =
* ~Array()
*	data is set to default or zero
*
* Methods:
* T & operator [](int index) const;
*	returns the desired data using index as a position to get it
* int GetStartIndex() const;
*	getter for starting index
* void SetStartIndex(int start_index);
*	setter for starting index
* int GetLength() const;
*	getter for length
* void SetLength(int length);
*	setter for length
*************************************************************************/
#include "Exception.h"
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;
template <class T>
class Array
{
public:
	Array();
	Array(int length, int start_index = 0);
	Array(const Array& copy);
	~Array();
	Array & operator =(const Array& rhs);
	T & operator [](int index) const;
	int GetStartIndex() const;
	void SetStartIndex(int start_index);
	int GetLength() const;
	void SetLength(int length);
private:
	T * m_array;
	int m_length;
	int m_start_index;
};

/**********************************************************************
* Purpose: Default ctor
*
* Precondition:
* Array object is created
*
* Postcondition:
* Object is instantiated with no length or starting index
*
************************************************************************/
template<class T>
Array<T>::Array(): m_array(nullptr), m_length(0), m_start_index(0)
{

}

/**********************************************************************
* Purpose: 2 arg ctor, can be used as a one arg ctor if no starting index is given
*
* Precondition:
* length: desired length of array
* start_index: The index at which array will start, so at starting index of
*			   8 to access element 0 the user would have to object[8]
*
* Postcondition:
* object is instantiated with desired length and starting index if
* one was provided
*
************************************************************************/
template<class T>
Array<T>::Array(int length, int start_index): m_array(nullptr), m_length(length), m_start_index(start_index)
{
	m_array = new T[m_length];
}

/**********************************************************************
* Purpose: copy ctor
*
* Precondition:
* copy: Another array object to copy its data from
*
* Postcondition:
* object is instantiated with data from another object
*
************************************************************************/
template<class T>
Array<T>::Array(const Array & copy): m_array(nullptr), m_length(copy.m_length), m_start_index(copy.m_start_index)
{
	m_array = new T[copy.m_length];
	for (int i = 0; i < copy.m_length; ++i)
	{
		m_array[i] = copy.m_array[i];
	}
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* object is going out of scope or is deleted
*
* Postcondition:
* data is removed and set back to default
*
************************************************************************/
template<class T>
Array<T>::~Array()
{
	delete[] m_array;
	m_array = nullptr;
	m_length = 0;
	m_start_index = 0;
}

/**********************************************************************
* Purpose: op=
*
* Precondition:
* rhs: Another array to take its data and assign it to this object
*
* Postcondition:
* data in this object is the same as the data in the rhs object
*
************************************************************************/
template<class T>
Array<T> & Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		delete[] m_array;

		m_array = new T[rhs.m_length];
		for (int i = 0; i < rhs.m_length; ++i)
		{
			m_array[i] = rhs.m_array[i];
		}
		m_length = rhs.m_length;
		m_start_index = rhs.m_start_index;
	}
	return *this;
}

/**********************************************************************
* Purpose: op[]
*
* Precondition:
* index: Desired element in array
*
* Postcondition:
* returns T if index is inside bounds of array
*
************************************************************************/
template<class T>
T & Array<T>::operator[](int index) const
{
	index -= m_start_index;
	if (index < 0 || index > m_length)
	{
		throw  Exception("Cannot access data out of bounds");
	}
	else
	{
		return m_array[index];
	}
}

/**********************************************************************
* Purpose: getter for starting index
*
* Precondition:
* function is called from object
*
* Postcondition:
* returns m_start_index
*
************************************************************************/
template<class T>
int Array<T>::GetStartIndex() const
{
	return m_start_index;
}

/**********************************************************************
* Purpose: setter for starting index
*
* Precondition:
* start_index: desired starting index to replace current starting index
*
* Postcondition:
* M_start_index is now the desired starting index
*
************************************************************************/
template<class T>
void Array<T>::SetStartIndex(int start_index)
{
	m_start_index = start_index;
}

/**********************************************************************
* Purpose: getter for length
*
* Precondition:
* function called from object
*
* Postcondition:
* returns m_length
*
************************************************************************/
template<class T>
int Array<T>::GetLength() const
{
	return m_length;
}

/**********************************************************************
* Purpose: setter for length
*
* Precondition:
* length: desired new length for array
*
* Postcondition:
* array is now desired length with data intact;
*
************************************************************************/
template<class T>
void Array<T>::SetLength(int length)
{
	if (length < 0)
	{
		throw Exception("Length less than 0");
	}
	else
	{
		T * temp = new T[length];
		for (int i = 0; i < m_length && i < length; i++)
		{
			temp[i] = m_array[i];
		}
		
		delete[] m_array;
		m_array = temp;

		temp = nullptr;

		m_length = length;
	}
}
#endif
