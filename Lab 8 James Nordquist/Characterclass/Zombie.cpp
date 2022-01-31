#include "Zombie.h"
#include<iostream>
#include<cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::time;
using std::srand;
using std::rand;

Zombie::Zombie(): Monster("Zombie",1)
{

}

Zombie::Zombie(const Zombie & copy): Monster(copy.m_name,copy.m_type)
{
	m_health = copy.m_health;
	m_dmgmin = copy.m_dmgmin;
	m_dmgmax = copy.m_dmgmax;
}

Zombie & Zombie::operator=(const Zombie & rhs)
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


Zombie::~Zombie()
{
}

void Zombie::generate()
{
	m_health = rand() % 6 + 6;
	m_dmgmin = rand() % 3 + 4;
	m_dmgmax = rand() % 6 + m_dmgmin + 1;
}

void Zombie::display()
{
	cout << "Type: " << m_name << endl << "Health: " << m_health << endl << "Damage: " << m_dmgmin << "-" << m_dmgmax << endl;
}

int Zombie::attack()
{
	return ((rand() % (m_dmgmax - m_dmgmin + 1))+m_dmgmin);
}

void Zombie::defend(int dmg)
{
	m_health -= dmg;
	cout << "The " << m_name << " takes " << dmg << "pts of damage" << endl;
}

void Zombie::setHealth(int hp)
{
	m_health = hp;
}

void Zombie::setDamage(int dmgm, int dmgmax)
{
	m_dmgmin = dmgm;
	m_dmgmax = dmgmax;
}

int Zombie::getType()
{
	return m_type;
}

int Zombie::getHealth()
{
	return m_health;
}

int Zombie::getDmgMin()
{
	return m_dmgmin;
}

int Zombie::getDmgMax()
{
	return m_dmgmax;
}
