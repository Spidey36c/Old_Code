/*************************************************************
* Author: James Nordquist
* Filename: Potion.h
* Date Created: 10/2/18
* Modifications: 10/9/18 - Added string class
*				 10/16/18 - Added op =
*************************************************************/
/************************************************************************
* Class: Potion
*
* Purpose: This class creates a Potion that has its definitions in strings
*
* Manager functions:
* Potion ( )
*	Defines all methods of the Potion obj to be ""
* Potion(string name, string description, string potency, string cost)
*	creates a Potion object using what was passed into the function.
* Potion(const Potion &obj);
* Potion & operator =(const Potion &rhs);
* void displayAll();
*	this will provide all information of the Potion that called this function
* void displayName();
*	this will display the name of a Potion that called this function
* void displayTotalCost(Potion stuff[], int numPotion);
*	displays the total cost of an array of Potions;
* ~Potion()
*
* Methods:
* m_name (String);
* m_description (String);
* m_potency (String);
* m_cost (String);
*************************************************************************/
#ifndef Potion_h
#define Potion_h
#endif
#include "String.h"


class Potion
{
public:
	Potion();
	Potion(String name, String description, String potency, String cost);
	Potion(const Potion &obj);
	Potion & operator =(const Potion &rhs);
	bool operator ==(const Potion &rhs) const;
	void displayAll();
	void displayName();
	void displayTotalCost(Potion stuff[], int numPotion);
	~Potion();
private:
	String m_name; // name of Potion obj
	String m_description; // description of Potion obj
	String m_potency; // potency of Potion obj
	String m_cost; // cost of Potion obj
};

