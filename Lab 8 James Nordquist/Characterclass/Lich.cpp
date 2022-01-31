#include "Lich.h"
#include<iostream>
#include<cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::time;
using std::srand;
using std::rand;


Lich::Lich() : Monster("Lich", 10)
{
}

Lich::Lich(const Lich & copy): Monster(copy.m_name,copy.m_type)
{
	m_health = copy.m_health;
	m_dmgmin = copy.m_dmgmin;
	m_dmgmax = copy.m_dmgmax;
}

Lich & Lich::operator=(const Lich & rhs)
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


Lich::~Lich()
{
}

void Lich::generate()
{
	m_health = rand() % 12 + 9;
	m_dmgmin = rand() % 4 + 5;
	m_dmgmax = rand() % 5 + m_dmgmin + 1;
}

void Lich::display()
{
	cout << "Type: " << m_name << endl << "Health: " << m_health << endl << "Damage: " << m_dmgmin << "-" << m_dmgmax << endl;
}

int Lich::attack()
{
	return ((rand() % (m_dmgmax - m_dmgmin + 1)) + m_dmgmin);
}

void Lich::defend(int dmg)
{
	m_health -= dmg;
	cout << "The " << m_name << " takes " << dmg << "pts of damage" << endl;
}

void Lich::setHealth(int hp)
{
	m_health = hp;
}

void Lich::setDamage(int dmgm, int dmgmax)
{
	m_dmgmin = dmgm;
	m_dmgmax = dmgmax;
}

int Lich::getType()
{
	return m_type;
}

int Lich::getHealth()
{
	return m_health;
}

int Lich::getDmgMin()
{
	return m_dmgmin;
}

int Lich::getDmgMax()
{
	return m_dmgmax;
}