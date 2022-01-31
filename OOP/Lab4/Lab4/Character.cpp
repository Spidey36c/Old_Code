#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include "Character.h"



Character::Character()
{
	cout << "Character default ctor called" << endl;
}

Character::Character(BackPack inventory, CoinPouch money, String name): m_inventory(inventory), m_pouch(money), m_name(name)
{
	cout << "Character one arg ctor called" << endl;
}

Character::Character(const Character & copy): m_inventory(copy.m_inventory), m_pouch(copy.m_pouch), m_name(copy.m_name)
{
	cout << "Character copy ctor called" << endl;
}

Character & Character::operator=(const Character & rhs)
{
	if (this != &rhs)
	{
		m_inventory = rhs.m_inventory;
		m_pouch = rhs.m_pouch;
		m_name = rhs.m_name;
	}
	return *this;
}


Character::~Character()
{
	cout << "Character dtor called" << endl;
}

BackPack Character::getInventory() const
{
	return m_inventory;
}

CoinPouch Character::getPouch() const
{
	return m_pouch;
}

String Character::getName() const
{
	return m_name;
}

void Character::setInv(BackPack inventory)
{
	m_inventory = inventory;
}

void Character::setPouch(CoinPouch pouch)
{
	m_pouch = pouch;
}

void Character::setName(String name)
{
	m_name = name;
}

void Character::buyItem(Potion itemtobuy)
{
	int afford;
	afford = m_pouch.buy(itemtobuy.getCost());
	if (afford = 0)
	{
		m_inventory.addPotion(itemtobuy);
	}
	else
	{
		cout << "You can't afford this." << endl;
	}
}

void Character::addItem(Potion itemtoadd)
{
	m_inventory.addPotion(itemtoadd);
}

void Character::useItem()
{
	int selection;
	DynamicArray temp;
	Potion *temp2;
	temp = m_inventory.getDArray();
	temp2 = new Potion[temp.GetElements()];
	temp2 = temp.getArray();
	for (int i = 0; i < temp.GetElements(); i++)
	{
		cout << i+1 << ") " << temp2[i].getName() << endl;
	}
	cout << endl << "Which potion do you want to use? 0 for no selection." << endl;
	cin >> selection;
	while (selection < 0 || selection > temp.GetElements())
	{
		cout << "Invalid selection" << endl;
		for (int i = 0; i < temp.GetElements(); i++)
		{
			cout << i + 1 << ") " << temp2[i].getName() << endl;
		}
		cout << endl << "Which potion do you want to use? 0 for no selection" << endl;
		cin >> selection;
	}
	if (selection != 0)
	{
		// do the potion effects
		m_inventory.removePotion(selection-1);
	}
	delete[] temp2;
}

void Character::sellItem()
{
	int selection;
	DynamicArray temp;
	Potion *temp2;
	temp = m_inventory.getDArray();
	temp2 = new Potion[temp.GetElements()];
	temp2 = temp.getArray();
	for (int i = 0; i < temp.GetElements(); i++)
	{
		cout << i + 1 << ") " << temp2[i].getName() << endl;
	}
	cout << endl << "Which potion do you want to sell? 0 for no selection." << endl;
	cin >> selection;
	while (selection < 0 || selection > temp.GetElements())
	{
		cout << "Invalid selection" << endl;
		for (int i = 0; i < temp.GetElements(); i++)
		{
			cout << i + 1 << ") " << temp2[i].getName() << endl;
		}
		cout << endl << "Which potion do you want to sell? 0 for no selection" << endl;
		cin >> selection;
	}
	if (selection != 0)
	{
		m_pouch.sell(temp2[selection-1].getCost());
		m_inventory.removePotion(selection - 1);
	}
	delete[] temp2;
}
