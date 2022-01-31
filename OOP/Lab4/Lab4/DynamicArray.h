/*************************************************************
* Author: James Nordquist
* Filename: DynamicArray.h
* Date Created: 10/15/18
* Modifications: 10/16/18 - comments and bug fixes
*				 10/18/18 - Comment blocks on this and cpp
*************************************************************/
/************************************************************************
* Class: Dynamic Array
*
* Purpose: This class creates a Dynamic array for potions
*
* Manager functions:
*	DynamicArray();
*		Sets m_array to nullptr and elements to 0
*	~DynamicArray();
*		deletes m_array and sets it to nullptr
*	DynamicArray(const DynamicArray &copy);
*		copy ctor
*	DynamicArray & operator =(const DynamicArray &rhs);
*		op =
*	int GetElements();
*		returns m_elements
*	Potion getData();
*		returns a specified element in the array
*	Potion * getArray();
*		returns m_array as a potion * so that whatever is calling it can access all elements of the array
*	void Insert(const Potion &to_add);
*		dynamically creates room to fit another potion in the array
*	void Delete(const Potion &to_delete);
*		uses the Find manager function to see if the potion to delete exists
*	int Find(const Potion &target);
*		searches for a matching potion in array
* Methods:
*		m_array (Potion *)
*		m_elements (int)
*************************************************************************/
#ifdef DynamicArray_h
#define DynamicArray_h
#endif
#include "Potion.h"
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();
	DynamicArray(const DynamicArray &copy);
	DynamicArray & operator =(const DynamicArray &rhs);
	int GetElements();
	Potion getData();
	Potion * getArray();
	void Insert(const Potion &to_add);
	void Delete(const Potion &to_delete);
private:
	int Find(const Potion &target);
	Potion * m_array;
	int m_elements;
};

