#include "Wizard.h"
#include<iostream>
#include<cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::time;
using std::srand;
using std::rand;


Wizard::Wizard(): Monster("Wizard",6)
{
}

Wizard::Wizard(const Wizard & copy): Monster(copy.m_name,copy.m_type)
{
	m_health = copy.m_health;
	m_dmgmin = copy.m_dmgmin;
	m_dmgmax = copy.m_dmgmax;
}

Wizard & Wizard::operator=(const Wizard & rhs)
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


Wizard::~Wizard()
{
}

void Wizard::generate()
{
	m_health = rand() % 6 + 3;
	m_dmgmin = rand() % 6 + 4;
	m_dmgmax = rand() % 5 + m_dmgmin + 4;
}

void Wizard::display()
{
	cout << "Type: " << m_name << endl << "Health: " << m_health << endl << "Damage: " << m_dmgmin << "-" << m_dmgmax << endl;
}

int Wizard::attack()
{
	return ((rand() % (m_dmgmax - m_dmgmin + 1)) + m_dmgmin);
}

void Wizard::defend(int dmg)
{
	m_health -= dmg;
	cout << "The " << m_name << " takes " << dmg << "pts of damage" << endl;
}

void Wizard::setHealth(int hp)
{
	m_health = hp;
}

void Wizard::setDamage(int dmgm, int dmgmax)
{
	m_dmgmin = dmgm;
	m_dmgmax = dmgmax;
}

int Wizard::getType()
{
	return m_type;
}

int Wizard::getHealth()
{
	return m_health;
}

int Wizard::getDmgMin()
{
	return m_dmgmin;
}

int Wizard::getDmgMax()
{
	return m_dmgmax;
}
