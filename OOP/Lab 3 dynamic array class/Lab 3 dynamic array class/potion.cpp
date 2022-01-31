/*************************************************************
* Author: James Nordquist
* Filename: Potion.cpp
* Date Created: 10/3/18
* Modifications: 10/9/18 - added string class
*				 10/16/18 - Added op =
*************************************************************/
#include <iostream>
#include "Potion.h"
using std::cin;
using std::cout;
using std::endl;
using std::atoi;


Potion::Potion() :m_name(""), m_description(""),m_potency(""), m_cost("")
{
	cout << "default Potion ctor called" << endl;
}


Potion::Potion(String name, String description, String potency, String cost) : m_name(name), m_description(description),
m_cost(cost)
{
	cout << "4 arg ctor Potion called" << endl;

	potency.Upper();
	m_potency = potency;
}

Potion::Potion(const Potion & obj) : m_name(obj.m_name), m_description(obj.m_description),m_potency(obj.m_potency) ,m_cost(obj.m_cost)
{
	cout << "Copy ctor called" << endl;
}

Potion & Potion::operator=(const Potion & rhs)
{
	cout << "Potion Op = called" << endl;

	m_name = rhs.m_name;

	m_description = rhs.m_description;

	m_potency = rhs.m_potency;

	m_cost = rhs.m_cost;

	return *this;
}

bool Potion::operator==(const Potion & rhs) const
{
	return m_name == rhs.m_name ? true : false;
}

void Potion::displayAll()
{
	cout << "Name: ";
	m_name.Display(); 
	cout << "Description: ";
	m_description.Display();
	cout << "Potency: ";
	m_potency.Display();

	char * cstr = new char[m_cost.length() + 1];
	strcpy(cstr, m_cost.c_str());

	cout << "Cost: ";
	cout << "Platinum: " << strtok(cstr, ".") << " ";
	cout << "Gold: " << strtok(NULL, ".") << " ";
	cout << "Silver: " << strtok(NULL, ".") << " ";
	cout << "Copper: " << strtok(NULL, ".") << endl << endl;

	delete[] cstr;
}

void Potion::displayName()
{
	cout << "Name: ";

	m_name.Display();
	cout << endl;
}

void Potion::displayTotalCost(Potion stuff[], int numPotion)
{
	int totalplat= 0;
	int totalgold = 0;
	int totalsilver = 0;
	int totalcopper = 0;

	for (int i = 0; i < numPotion; i++)
	{
		char * cstr = new char[stuff[i].m_cost.length() + 1];
		strcpy(cstr, stuff[i].m_cost.c_str());
		totalplat += atoi(strtok(cstr, "."));
		totalgold += atoi(strtok(NULL, "."));
		totalsilver += atoi(strtok(NULL, "."));
		totalcopper += atoi(strtok(NULL, "."));
		delete[] cstr;
	}

	while (totalcopper >= 100)
	{
		totalcopper -= 100;
		totalsilver += 1;
	}

	while (totalsilver >= 100)
	{
		totalsilver -= 100;
		totalgold += 1;
	}

	while (totalgold >= 100)
	{
		totalgold -= 100;
		totalplat += 1;
	}

	cout << "The total cost of all the Potions is " << totalplat << " Platinum, " << totalgold << " Gold, " << totalsilver
		<< " Silver, and "
		<< totalcopper << " Copper" << endl;
}

Potion::~Potion()
{

}
