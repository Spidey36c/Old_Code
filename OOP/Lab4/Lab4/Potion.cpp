/*************************************************************
* Author: James Nordquist
* Filename: Potion.cpp
* Date Created: 10/3/18
* Modifications: 10/9/18 - added string class
*				 10/16/18 - Added op =
*				 10/19/18 - Added getters
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

Potion::Potion(const char * name, const char * description, const char * potency, const char * cost): m_name(name), m_description(description), m_cost(cost)
{
	cout << "4 arg char ctor Potion called" << endl;
	m_potency = potency;
	m_potency.Upper();
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

String Potion::getName() const
{
	return m_name;
}

String Potion::getDescription() const
{
	return m_description;
}

String Potion::getPotency() const
{
	return m_potency;
}

String Potion::getCost() const
{
	return m_cost;
}

void Potion::setName(String name)
{
	m_name = name;
}

void Potion::setName(const char * name)
{
	m_name = name;
}

void Potion::setDescription(String description)
{
	m_description = description;
}

void Potion::setDescription(const char * description)
{
	m_description = description;
}

void Potion::setPotency(String potency)
{
	m_potency = potency;
}

void Potion::setPotency(const char * potency)
{
	m_potency = potency;
}

void Potion::setCost(String cost)
{
	m_cost = cost;
}

void Potion::setCost(const char * cost)
{
	m_cost = cost;
}

Potion::~Potion()
{

}
