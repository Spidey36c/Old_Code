#include "Lion.h"
#include<iostream>
#include<cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::time;
using std::srand;
using std::rand;


Lion::Lion(): Monster("Lion",4)
{
}

Lion::Lion(const Lion & copy): Monster(copy.m_name,copy.m_type)
{
	m_health = copy.m_health;
	m_dmgmin = copy.m_dmgmin;
	m_dmgmax = copy.m_dmgmax;
}

Lion & Lion::operator=(const Lion & rhs)
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

Lion::~Lion()
{
}

void Lion::generate()
{
	m_health = (rand() % 5 + 10) + 1;
	m_dmgmin = rand() % 6 + 5;
	m_dmgmax = rand() % 4 + m_dmgmin + 1;
}

void Lion::display()
{
	cout << "Type: " << m_name << endl << "Health: " << m_health << endl << "Damage: " << m_dmgmin << "-" << m_dmgmax << endl;
}

int Lion::attack()
{
	return ((rand() % (m_dmgmax - m_dmgmin + 1)) + m_dmgmin);
}

void Lion::defend(int dmg)
{
	m_health -= dmg;
	cout << "The " << m_name << " takes " << dmg << "pts of damage" << endl;
}

void Lion::setHealth(int hp)
{
	m_health = hp;
}

void Lion::setDamage(int dmgm, int dmgmax)
{
	m_dmgmin = dmgm;
	m_dmgmax = dmgmax;
}

int Lion::getType()
{
	return m_type;
}

int Lion::getHealth()
{
	return m_health;
}

int Lion::getDmgMin()
{
	return m_dmgmin;
}

int Lion::getDmgMax()
{
	return m_dmgmax;
}
