/*************************************************************
* Author: James Nordquist
* Filename: potion.h
* Date Created: 10/2/18
* Modifications: 10/9/18 - Added string class
*************************************************************/
/************************************************************************
* Class: Potion
*
* Purpose: This class creates a potion that has its definitions in strings
*
* Manager functions:
* Potion ( )
*	Defines all methods of the potion obj to be ""
* potion(string name, string description, string potency, string cost)
*	creates a potion object using what was passed into the function.
* potion(const potion &obj);
* potion & operator =(const potion &rhs);
* void displayAll();
*	this will provide all information of the potion that called this function
* void displayName();
*	this will display the name of a potion that called this function
* void displayTotalCost(potion stuff[], int numpotion);
*	displays the total cost of an array of potions;
* ~potion()
*
* Methods:
* m_name (String);
* m_description (String);
* m_potency (String);
* m_cost (String);
*************************************************************************/
#ifndef potion_h
#define potion_h
#endif
#include "String.h"


class potion
{
public:
	potion();
	potion(String name, String description, String potency, String cost);
	potion(const potion &obj);
	potion & operator =(const potion &rhs);
	void displayAll();
	void displayName();
	void displayTotalCost(potion stuff[], int numpotion);
	~potion();
private:
	String m_name; // name of potion obj
	String m_description; // description of potion obj
	String m_potency; // potency of potion obj
	String m_cost; // cost of potion obj
};

