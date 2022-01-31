#include "GiantEagle.h"
#include<iostream>
#include<cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::time;
using std::srand;
using std::rand;


GiantEagle::GiantEagle(): Monster("Giant Eagle",5)
{
}

GiantEagle::GiantEagle(const GiantEagle & copy): Monster(copy.m_name,copy.m_type)
{
	m_health = copy.m_health;
	m_dmgmin = copy.m_dmgmin;
	m_dmgmax = copy.m_dmgmax;
}

GiantEagle & GiantEagle::operator=(const GiantEagle & rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_type = rhs.m_type;
		m_health = rhs.m_health;
		m_dmgmin = rhs.m_dmgmin;
		m_dmgmax = rhs.m_dmgmax;
	}
	return *this;
}


GiantEagle::~GiantEagle()
{
}

void GiantEagle::generate()
{
	m_health = (rand() % 9 + 8)+1;
	m_dmgmin = rand() % 4 + 6;
	m_dmgmax = rand() % 2 + m_dmgmin + 3;
}

void GiantEagle::display()
{
	cout << "Type: " << m_name << endl << "Health: " << m_health << endl << "Damage: " << m_dmgmin << "-" << m_dmgmax << endl;
}

int GiantEagle::attack()
{
	return ((rand() % (m_dmgmax - m_dmgmin + 1)) + m_dmgmin);
}

void GiantEagle::defend(int dmg)
{
	m_health -= dmg;
	cout << "The " << m_name << " takes " << dmg << "pts of damage" << endl;
}

void GiantEagle::setHealth(int hp)
{
	m_health = hp;
}

void GiantEagle::setDamage(int dmgm, int dmgmax)
{
	m_dmgmin = dmgm;
	m_dmgmax = dmgmax;
}

int GiantEagle::getType()
{
	return m_type;
}

int GiantEagle::getHealth()
{
	return m_health;
}

int GiantEagle::getDmgMin()
{
	return m_dmgmin;
}

int GiantEagle::getDmgMax()
{
	return m_dmgmax;
}
