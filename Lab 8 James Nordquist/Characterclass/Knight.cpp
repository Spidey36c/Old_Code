#include "Knight.h"
#include<iostream>
#include<cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::time;
using std::srand;
using std::rand;


Knight::Knight(): Monster("Knight",7)
{
}

Knight::Knight(const Knight & copy):Monster(copy.m_name,copy.m_type)
{
	m_health = copy.m_health;
	m_dmgmin = copy.m_dmgmin;
	m_dmgmax = copy.m_dmgmax;
}

Knight & Knight::operator=(const Knight & rhs)
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


Knight::~Knight()
{
}

void Knight::generate()
{
	m_health = rand() % 8 + 10;
	m_dmgmin = rand() % 3 + 4;
	m_dmgmax = rand() % 4 + m_dmgmin + 2;
}

void Knight::display()
{
	cout << "Type: " << m_name << endl << "Health: " << m_health << endl << "Damage: " << m_dmgmin << "-" << m_dmgmax << endl;
}

int Knight::attack()
{
	return ((rand() % (m_dmgmax - m_dmgmin + 1)) + m_dmgmin);
}

void Knight::defend(int dmg)
{
	m_health -= dmg;
	cout << "The " << m_name << " takes " << dmg << "pts of damage" << endl;
}

void Knight::setHealth(int hp)
{
	m_health = hp;
}

void Knight::setDamage(int dmgm, int dmgmax)
{
	m_dmgmin = dmgm;
	m_dmgmax = dmgmax;
}

int Knight::getType()
{
	return m_type;
}

int Knight::getHealth()
{
	return m_health;
}

int Knight::getDmgMin()
{
	return m_dmgmin;
}

int Knight::getDmgMax()
{
	return m_dmgmax;
}
