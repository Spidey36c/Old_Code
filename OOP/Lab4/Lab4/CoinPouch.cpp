#include <iostream>
using std::cout;
using std::endl;
#include "CoinPouch.h"



CoinPouch::CoinPouch(): m_money("0.0.0.0")
{
	cout << "CoinPouch default ctor called" << endl;
}

CoinPouch::CoinPouch(const char * str): m_money(str)
{
	cout << "CoinPouch char one arg Ctor called" << endl;
}

CoinPouch::CoinPouch(String str): m_money(str)
{
	cout << "CoinPouch String one arg Ctor called" << endl;
}

CoinPouch::CoinPouch(const CoinPouch & copy): m_money(copy.m_money)
{
	cout << "CoinPouch copy ctor called" << endl;
}

CoinPouch & CoinPouch::operator=(const CoinPouch & rhs)
{
	cout << "CoinPouch op = called" << endl;
	if (this != &rhs)
	{
		m_money = rhs.m_money;
	}
	return *this;
}


CoinPouch::~CoinPouch()
{
}

String CoinPouch::getMoney() const
{
	return m_money;
}

int CoinPouch::buy(String cost)
{
	int afford = 0;

	int charplat = 0;
	int chargold = 0;
	int charsilver = 0;
	int charcopper = 0;

	int itemplat = 0;
	int itemgold = 0;
	int itemsilver = 0;
	int itemcopper = 0;

	char * cstr = new char[m_money.length() + 1];
	strcpy(cstr, m_money.c_str());
	charplat += atoi(strtok(cstr, "."));
	chargold += atoi(strtok(NULL, "."));
	charsilver += atoi(strtok(NULL, "."));
	charcopper += atoi(strtok(NULL, "."));
	delete[] cstr;

	cstr = new char[cost.length() + 1];
	strcpy(cstr, cost.c_str());
	itemplat += atoi(strtok(cstr, "."));
	itemgold += atoi(strtok(NULL, "."));
	itemsilver += atoi(strtok(NULL, "."));
	itemcopper += atoi(strtok(NULL, "."));
	delete[] cstr;

	if (itemplat > charplat)
	{
		afford = -1;
	}
	else
	{
		charplat -= itemplat;
	}
	if (itemgold > chargold && afford == 0)
	{
		if(charplat > 0 && itemgold > chargold)
		{
			charplat -= 1;
			chargold += 100;
		}
		if (itemgold > chargold)
		{
			afford = -1;
		}
		else
		{
			chargold -= itemgold;
		}
	}
	else if(itemgold <= chargold && afford == 0)
	{
		chargold -= itemgold;
	}	
	if (itemsilver > charsilver && afford == 0)
	{
		if (chargold == 0 && charplat != 0)
		{
			charplat -= 1;
			chargold += 100;
			chargold -= 1;
			charsilver += 100;
			charsilver -= itemsilver;
		}
		else if (chargold != 0)
		{
			chargold -= 1;
			charsilver += 100;
			charsilver -= itemsilver;
		}
		else
		{
			afford = -1;
		}
	}
	else if(itemsilver < charsilver && afford == 0)
	{
		charsilver -= itemsilver;
	}
	if (itemcopper > charcopper && afford == 0)
	{
		if (charsilver == 0 && chargold != 0)
		{
			chargold -= 1;
			charsilver += 100;
			charsilver -= 1;
			charcopper += 100;
			charcopper -= itemcopper;
		}
		else if (charsilver == 0 && charplat != 0)
		{
			charplat -= 1;
			chargold += 100;
			chargold -= 1;
			charsilver += 100;
			charsilver -= 1;
			charcopper += 100;
			charcopper -= itemcopper;
		}
		else if (charsilver != 0)
		{
			charsilver -= 1;
			charcopper += 100;
			charcopper -= itemcopper;
		}
		else
		{
			afford = -1;
		}
	}
	else if(itemcopper < charcopper && afford == 0)
	{
		charcopper -= itemcopper;
	}

	if (afford == 0)
	{
		charsilver += charcopper / 100;
		charcopper = charcopper % 100;
		chargold += charsilver / 100;
		charsilver = charsilver % 100;
		charplat += chargold / 100;
		chargold = chargold % 100;


		int size = 0;
		for (int i = charplat; i > 0; size++)
		{
			i /= 10;
		}
		for (int i = chargold; i > 0; size++)
		{
			i /= 10;
		}
		for (int i = charsilver; i > 0; size++)
		{
			i /= 10;
		}
		for (int i = charcopper; i > 0; size++)
		{
			i /= 10;
		}

		char *temp = new char[size + 5];
		char *buffer = new char[size];
		strcpy(temp, itoa(charplat, buffer, 10));
		strcat(temp, ".");
		strcat(temp, itoa(chargold, buffer, 10));
		strcat(temp, ".");
		strcat(temp, itoa(charsilver, buffer, 10));
		strcat(temp, ".");
		strcat(temp, itoa(charcopper, buffer, 10));

		m_money = temp;

		delete[] temp;
		delete[] buffer;

	}

	return afford;
}

void CoinPouch::sell(String cost)
{
	int charplat = 0;
	int chargold = 0;
	int charsilver = 0;
	int charcopper = 0;

	int itemplat = 0;
	int itemgold = 0;
	int itemsilver = 0;
	int itemcopper = 0;

	char * cstr = new char[m_money.length() + 1];
	strcpy(cstr, m_money.c_str());
	charplat += atoi(strtok(cstr, "."));
	chargold += atoi(strtok(NULL, "."));
	charsilver += atoi(strtok(NULL, "."));
	charcopper += atoi(strtok(NULL, "."));
	delete[] cstr;

	cstr = new char[cost.length() + 1];
	strcpy(cstr, cost.c_str());
	itemplat += atoi(strtok(cstr, "."));
	itemgold += atoi(strtok(NULL, "."));
	itemsilver += atoi(strtok(NULL, "."));
	itemcopper += atoi(strtok(NULL, "."));
	delete[] cstr;

	charplat += itemplat;
	chargold += itemgold;
	charsilver += itemsilver;
	charcopper += itemcopper;

	charsilver += charcopper / 100;
	charcopper = charcopper % 100;
	chargold += charsilver / 100;
	charsilver = charsilver % 100;
	charplat += chargold / 100;
	chargold = chargold % 100;


	int size = 0;
	for (int i = charplat; i > 0; size++)
	{
		i /= 10;
	}
	for (int i = chargold; i > 0; size++)
	{
		i /= 10;
	}
	for (int i = charsilver; i > 0; size++)
	{
		i /= 10;
	}
	for (int i = charcopper; i > 0; size++)
	{
		i /= 10;
	}

	char *temp = new char[size + 5];
	char *buffer = new char[size];
	strcpy(temp, itoa(charplat, buffer, 10));
	strcat(temp, ".");
	strcat(temp, itoa(chargold, buffer, 10));
	strcat(temp, ".");
	strcat(temp, itoa(charsilver, buffer, 10));
	strcat(temp, ".");
	strcat(temp, itoa(charcopper, buffer, 10));

	m_money = temp;

	delete[] temp;
	delete[] buffer;
}
