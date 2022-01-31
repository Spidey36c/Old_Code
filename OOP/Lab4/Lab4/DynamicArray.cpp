/*************************************************************
* Author: James Nordquist
* Filename: DynamicArray.h
* Date Created: 10/15/18
* Modifications: 10/16/18 - comments and bug fixes
*				 10/18/18 - Comment blocks on this and .h
*************************************************************/
#include "DynamicArray.h"
#include <iostream>
using std::endl;
using std::cout;
using std::cin;

DynamicArray::DynamicArray(): m_array(nullptr),m_elements(0)
{
	cout << "Dynamic Array ctor called" << endl;
}

DynamicArray::~DynamicArray()
{
	cout << "Dynamic Array dtor called" << endl;
	delete[] m_array;
	m_array = nullptr;
}

DynamicArray::DynamicArray(const DynamicArray & copy): m_array(nullptr), m_elements(copy.m_elements)
{
	cout << "Dynamic Array copy ctor called" << endl;
	m_array = new Potion[copy.m_elements];
	for (int i = 0; i < copy.m_elements; i++)
	{
		m_array[i] = copy.m_array[i];
	}
}

DynamicArray & DynamicArray::operator=(const DynamicArray & rhs)
{
	cout << "Dynamic Array op = called" << endl;
	// 1. Check for self assignment
	if (this != &rhs)
	{
		// 2. Purge the left hand side
		delete[] m_array;

		// 3. Make the deep copy
		m_array = new Potion[rhs.m_elements];
		for (int i = 0; i < rhs.m_elements; i++)
		{
			m_array[i] = rhs.m_array[i];
		}
		m_elements = rhs.m_elements;
	}
	// 4. return reference to self
	return *this;
}

int DynamicArray::GetElements()
{
	cout << "Dynamic Array getElements called" << endl;
	return m_elements;
}

Potion DynamicArray::getData()
{
	cout << "Dynamic Array getData called" << endl;
	int element;
	cout << "You currently have " << m_elements << " potions in your inventory" << endl;
	for (int i = 0; i < m_elements; i++)
	{
		cout << i+1 << ") ";
		m_array[i].displayName();
	}
	cout << "Which potion do you want to look at? ";
	cin >> element;

	while (element < 1 || element > m_elements)
	{
		cout << "That is not a viable potion to look at." << endl;
		cout << "You currently have " << m_elements << " potions in your inventory" << endl;
		for (int i = 0; i < m_elements; i++)
		{
			cout << i+1 << ") ";
			m_array[i].displayName();
		}
		cout << "Which potion do you want to look at? ";
		cin >> element;
	}
	return m_array[element-1];
}

Potion * DynamicArray::getArray()
{
	cout << "Dynamic Array getArray called" << endl;
	return m_array;
}

void DynamicArray::Insert(const Potion & to_add)
{
	cout << "Dynamic Array insert called" << endl;
	Potion *temp = new Potion[m_elements+1];
	for (int i = 0; i < m_elements; i++)
	{
		temp[i] = m_array[i];
	}
	
	temp[m_elements] = to_add;
	
	delete[] m_array;

	m_array = temp;

	m_elements++;
}

void DynamicArray::Delete(const Potion & to_delete)
{
	cout << "Dynamic Array Delete called" << endl;
	int found = Find(to_delete);
	if (found != -1)
	{
		Potion *temp = new Potion[m_elements];
		for (int i = 0; i <	found; i++)
		{
			temp[i] = m_array[i];
		}
		for (int i = found; i < m_elements - 1; i++)
		{
			temp[i] = m_array[i + 1];
		}
		delete[] m_array;
		m_array = temp;
		m_elements--;
	}
	else
	{
		cout << "That potion was not found" << endl;
	}
}

int DynamicArray::Find(const Potion & target)
{
	cout << "Dynamic Array find called" << endl;
	int index = -1;
	int i = 0;
	while (i <m_elements && index == -1)
	{
		if (m_array[i].getName() == target.getName() && m_array[i].getDescription() == target.getDescription() && m_array[i].getPotency() == target.getPotency() && m_array[i].getCost() == target.getCost())
		{
			index = i;
		}
		i++;
	}
	return index;
}
