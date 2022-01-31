#include <iostream>
using std::cout;
using std::endl;
#include "BackPack.h"



BackPack::BackPack()
{
	cout << "BackPack Default ctor called" << endl;
}

BackPack::BackPack(DynamicArray bp): m_potions(bp)
{
	cout << "BackPack one arg ctor called" << endl;
}

BackPack::BackPack(const BackPack & copy): m_potions(copy.m_potions)
{
	cout << "BackPack copy ctor called" << endl;
}

BackPack & BackPack::operator=(const BackPack & rhs)
{
	cout << "BackPack op = called" << endl;
	if (this != &rhs)
	{
		m_potions = rhs.m_potions;
	}
	return *this;
}


BackPack::~BackPack()
{
	cout << "BackPack dtor called" << endl;
}

void BackPack::addPotion(Potion &newp)
{
	m_potions.Insert(newp);
}

void BackPack::removePotion(int selection)
{
	Potion *inventory = new Potion[m_potions.GetElements()];
	inventory = m_potions.getArray();
	m_potions.Delete(inventory[selection]);
	delete[] inventory;
}

void BackPack::addArrayPotion(DynamicArray &newp)
{
	Potion *inventory = new Potion[newp.GetElements()];
	inventory = newp.getArray();
	for (int i = 0; i < newp.GetElements(); i++)
	{
		m_potions.Insert(inventory[i]);
	}
	delete[] inventory;
}

DynamicArray BackPack::getDArray() const
{
	return m_potions;
}
