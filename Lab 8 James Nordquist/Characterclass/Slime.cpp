#include "Slime.h"
#include<iostream>
#include<cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::time;
using std::srand;
using std::rand;


Slime::Slime(): Monster("Slime",3)
{
}

Slime::Slime(const Slime & copy): Monster(copy.m_name,copy.m_type)
{
	m_health = copy.m_health;
	m_dmgmin = copy.m_dmgmin;
	m_dmgmax = copy.m_dmgmax;
}

Slime & Slime::operator=(const Slime & rhs)
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


Slime::~Slime()
{
}

void Slime::generate()
{
	m_health = rand() % 3 + 7;
	m_dmgmin = rand() % 2 + 4;
	m_dmgmax = rand() % 3 + m_dmgmin + 1;
}

void Slime::display()
{
	cout << "Type: " << m_name << endl << "Health: " << m_health << endl << "Damage: " << m_dmgmin << "-" << m_dmgmax << endl;
}

int Slime::attack()
{
	return ((rand() % (m_dmgmax - m_dmgmin + 1)) + m_dmgmin);
}

void Slime::defend(int dmg)
{
	m_health -= dmg;
	cout << "The " << m_name << " takes " << dmg << "pts of damage" << endl;
}

void Slime::setHealth(int hp)
{
	m_health = hp;
}

void Slime::setDamage(int dmgm, int dmgmax)
{
	m_dmgmin = dmgm;
	m_dmgmax = dmgmax;
}

int Slime::getType()
{
	return m_type;
}

int Slime::getHealth()
{
	return m_health;
}

int Slime::getDmgMin()
{
	return m_dmgmin;
}

int Slime::getDmgMax()
{
	return m_dmgmax;
}
