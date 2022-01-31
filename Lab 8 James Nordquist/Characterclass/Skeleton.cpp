#include "Skeleton.h"
#include<iostream>
#include<cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::time;
using std::srand;
using std::rand;



Skeleton::Skeleton(): Monster("Skeleton",8)
{
}

Skeleton::Skeleton(const Skeleton & copy): Monster(copy.m_name,copy.m_type)
{
	m_health = copy.m_health;
	m_dmgmin = copy.m_dmgmin;
	m_dmgmax = copy.m_dmgmax;
}

Skeleton & Skeleton::operator=(const Skeleton & rhs)
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


Skeleton::~Skeleton()
{
}

void Skeleton::generate()
{
	m_health = rand() % 7 + 6;
	m_dmgmin = rand() % 4 + 4;
	m_dmgmax = rand() % 6 + m_dmgmin + 1;
}

void Skeleton::display()
{
	cout << "Type: " << m_name << endl << "Health: " << m_health << endl << "Damage: " << m_dmgmin << "-" << m_dmgmax << endl;
}

int Skeleton::attack()
{
	return ((rand() % (m_dmgmax - m_dmgmin + 1)) + m_dmgmin);
}

void Skeleton::defend(int dmg)
{
	m_health -= dmg;
	cout << "The " << m_name << " takes " << dmg << "pts of damage" << endl;
}

void Skeleton::setHealth(int hp)
{
	m_health = hp;
}

void Skeleton::setDamage(int dmgm, int dmgmax)
{
	m_dmgmin = dmgm;
	m_dmgmax = dmgmax;
}

int Skeleton::getType()
{
	return m_type;
}

int Skeleton::getHealth()
{
	return m_health;
}

int Skeleton::getDmgMin()
{
	return m_dmgmin;
}

int Skeleton::getDmgMax()
{
	return m_dmgmax;
}