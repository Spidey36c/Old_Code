#include "Griffon.h"
#include<iostream>
#include<cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::time;
using std::srand;
using std::rand;


Griffon::Griffon(): Monster("Griffon",9)
{
}

Griffon::Griffon(const Griffon & copy):Monster(copy.m_name,copy.m_type)
{
	m_health = copy.m_health;
	m_dmgmin = copy.m_dmgmin;
	m_dmgmax = copy.m_dmgmax;
}

Griffon & Griffon::operator=(const Griffon & rhs)
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


Griffon::~Griffon()
{
}

void Griffon::generate()
{
	m_health = (rand() % 11 + 7) + 1;
	m_dmgmin = rand() % 3 + 7;
	m_dmgmax = rand() % 6 + m_dmgmin + 3;
}

void Griffon::display()
{
	cout << "Type: " << m_name << endl << "Health: " << m_health << endl << "Damage: " << m_dmgmin << "-" << m_dmgmax << endl;
}

int Griffon::attack()
{
	return ((rand() % (m_dmgmax - m_dmgmin + 1)) + m_dmgmin);
}

void Griffon::defend(int dmg)
{
	m_health -= dmg;
	cout << "The " << m_name << " takes " << dmg << "pts of damage" << endl;
}

void Griffon::setHealth(int hp)
{
	m_health = hp;
}

void Griffon::setDamage(int dmgm, int dmgmax)
{
	m_dmgmin = dmgm;
	m_dmgmax = dmgmax;
}

int Griffon::getType()
{
	return m_type;
}

int Griffon::getHealth()
{
	return m_health;
}

int Griffon::getDmgMin()
{
	return m_dmgmin;
}

int Griffon::getDmgMax()
{
	return m_dmgmax;
}