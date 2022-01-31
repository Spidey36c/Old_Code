#include "Imp.h"
#include<iostream>
#include<cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::time;
using std::srand;
using std::rand;


Imp::Imp() : Monster("Imp", 2)
{
}

Imp::Imp(const Imp & copy): Monster(copy.m_name, copy.m_type)
{
	m_health = copy.m_health;
	m_dmgmin = copy.m_dmgmin;
	m_dmgmax = copy.m_dmgmax;
}

Imp & Imp::operator=(const Imp & rhs)
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


Imp::~Imp()
{

}

void Imp::generate()
{
	m_health = rand() % 5 + 7;
	m_dmgmin = rand() % 3 + 3;
	m_dmgmax = rand() % 5 + m_dmgmin + 1;
}

void Imp::display()
{
	cout << "Type: " << m_name << endl << "Health: " << m_health << endl << "Damage: " << m_dmgmin << "-" << m_dmgmax << endl;
}

int Imp::attack()
{
	srand(time(0));
	return ((rand() % (m_dmgmax - m_dmgmin + 1)) + m_dmgmin);
}

void Imp::defend(int dmg)
{
	m_health -= dmg;
	cout << "The " << m_name << " takes " << dmg << "pts of damage" << endl;;
}

void Imp::setHealth(int hp)
{
	m_health = hp;
}

void Imp::setDamage(int dmgm, int dmgmax)
{
	m_dmgmin = dmgm;
	m_dmgmax = dmgmax;
}

int Imp::getType()
{
	return m_type;
}

int Imp::getHealth()
{
	return m_health;
}

int Imp::getDmgMin()
{
	return m_dmgmin;
}

int Imp::getDmgMax()
{
	return m_dmgmax;
}
