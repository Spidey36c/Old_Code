#include <iostream>
#include "potion.h"
using std::cin;
using std::cout;
using std::endl;


potion::potion() :m_name(""), m_description(""),m_potency(""), m_cost("")
{
}


potion::potion(string name, string description, string potency, string cost) : m_name(name), m_description(description),
m_potency(potency), m_cost(cost)
{
}

potion::potion(const potion & obj) : m_name(obj.m_name), m_description(obj.m_description),m_potency(obj.m_potency), 
m_cost(obj.m_cost)
{
}

potion & potion::operator=(const potion & rhs)
{
	if (m_name != rhs.m_name)
	{
		m_name = rhs.m_name;
	}
	if (m_description != rhs.m_description)
	{
		m_description = rhs.m_description;
	}
	if (m_potency != rhs.m_potency)
	{
		m_potency = rhs.m_potency;
	}
	if (m_cost != rhs.m_cost)
	{
		m_cost = rhs.m_cost;
	}

	return *this;
}

void potion::displayAll()
{
	cout << "Name: " << m_name << endl;
	cout << "Description: " << m_description << endl;
	cout << "Potency: " << m_potency << endl;
	char * cstr = new char[m_cost.length() + 1];
	strcpy(cstr, m_cost.c_str());
	cout << "Cost: ";
	cout << "Platinum: " << strtok(cstr, ".") << " ";
	cout << "Gold: " << strtok(NULL, ".") << " ";
	cout << "Silver: " << strtok(NULL, ".") << " ";
	cout << "Copper: " << strtok(NULL, ".") << endl;
	delete[] cstr;
}

void potion::displayName()
{
	cout << m_name << endl;
}

void potion::displayTotalCost(potion stuff[], int numpotion)
{
	int totalplat= 0;
	int totalgold = 0;
	int totalsilver = 0;
	int totalcopper = 0;
	for (int i = 0; i < numpotion; i++)
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
	cout << "The total cost of all the potions is " << totalplat << " Platinum, " << totalgold << " Gold, " << totalsilver
		<< " Silver, and "
		<< totalcopper << " Copper" << endl;
}

void potion::setName(string name)
{
	m_name = name;
}

void potion::setDesc(string description)
{
	m_description = description;
}

void potion::setPotency(string potency)
{
	m_potency = potency;
}

void potion::setCost(string cost)
{
	m_cost = cost;
}

potion::~potion()
{
}
