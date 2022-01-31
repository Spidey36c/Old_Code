#include "Character.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::srand;
using std::rand;
using std::time;


Character::Character() : m_health(0), m_armor(0), m_dmgmin(0), m_dmgmax(0), m_name(""), m_round(1), m_maxhealth(0), m_gameState(0)
{

}

Character::Character(int hp, int armor, int dmg, string name) : m_health(hp), m_armor(armor), m_dmgmin(dmg), m_name(name), m_round(1),m_gameState(0)
{
	m_dmgmax = rand() % 5 + m_dmgmin + 1;
	m_maxhealth = m_health;
}

Character::Character(const Character & copy) : m_health(copy.m_health), m_armor(copy.m_armor), m_dmgmin(copy.m_dmgmin), m_dmgmax(copy.m_dmgmax), m_name(copy.m_name), m_round(copy.m_round), m_maxhealth(copy.m_maxhealth)
{

}

Character & Character::operator=(const Character & rhs)
{
	if (this != &rhs)
	{
		m_health = rhs.m_health;
		m_maxhealth = m_health;
		m_armor = rhs.m_armor;
		m_round = rhs.m_round;
		m_dmgmin = rhs.m_dmgmin;
		m_dmgmax = rhs.m_dmgmax;
		m_name = rhs.m_name;
	}
	return *this;
}

Character::~Character()
{
}

void Character::generateFull()
{
	const char * nameGenerate[20] =
	{
		"Joshua", "Grindwald", "Attano", "Feldwin", "Seymour", "Colborn", "Carol", "Oswall", "Asher", "Bradley", "Uhland", "Kent", "Denys", "Humbie", "Ruffe", "Burns", "Damian", "Gideon", "Troy", "Caldwell"
	};
	m_health = rand() % 8 + 7;
	m_armor = rand() % 4 + 1;
	m_dmgmin = rand() % 3 + 3;
	m_dmgmax = rand() % 7 + m_dmgmin + 1;
	m_name = nameGenerate[rand() % 20];
	m_maxhealth = m_health;
}

void Character::generateStats()
{
	m_health = rand() % 8 + 7;
	m_armor = rand() % 5 + 1;
	m_dmgmin = rand() % 6 + 3;
	m_dmgmax = rand() % 4 + m_dmgmin + 1; //max damage will always be atleast 1 greater than minimum damage
	m_maxhealth = m_health;
}

int Character::attack()
{
	int tempDmgMin = m_dmgmin;
	int tempDmgMax = m_dmgmax;
	if (m_stance == 2) //block
	{
		tempDmgMin = m_dmgmin * .5;
		tempDmgMax = m_dmgmax * .5;
	}
	if (m_stance == 3) //berserk
	{
		tempDmgMin = m_dmgmin * 1.5;
		tempDmgMax = m_dmgmax * 1.5;
	}
	return ((rand() % (tempDmgMax - tempDmgMin + 1)) + tempDmgMin); //if m_dmgmax is 8 and m_dmgmin is 5 first it will choose a random number between 0 and 3 (rand() % (8-5+1)) then add 5 to generate a number between min and max
}

void Character::defend(int dmg)
{
	if (m_stance == 1) //normal
	{
		if (m_armor >= dmg)
		{
			cout << "No Damage" << endl;
		}
		else
		{
			dmg -= m_armor;
			m_health -= dmg;
			cout << "Took " << dmg << " pts of damage" << endl;
		}
	}
	else if (m_stance == 2) //block
	{
		int tempArmor = m_armor * 1.5;
		if (m_armor < 4)
		{
			tempArmor += 1;
		}
		if (tempArmor >= dmg)
		{
			cout << "No Damage" << endl;
		}
		else
		{
			dmg -= tempArmor;
			m_health -= dmg;
			cout << "Took " << dmg << " pts of damage" << endl;
		}
	}
	else if (m_stance == 3) //berserk
	{
		int tempArmor = m_armor * .5;
		if (tempArmor >= dmg)
		{
			cout << "No Damage" << endl;
		}
		else
		{
			dmg -= tempArmor;
			m_health -= dmg;
			cout << "Took " << dmg << " pts of damage" << endl;
		}
	}
	if (m_health <= 0)
	{
		m_gameState = 1;
	}
}

void Character::stanceChange()
{
	int selection;
	cout << "1) Normal" << endl;
	cout << "2) Block" << endl;
	cout << "3) Berserk" << endl;
	cout << "What stance do you want to use? ";
	cin >> selection;
	while (selection < 1 || selection > 3)
	{
		cout << "Invalid selection" << endl;
		cout << "1) Normal" << endl;
		cout << "2) Block" << endl;
		cout << "3) Berserk" << endl;
		cout << "What stance do you want to use? ";
		cin >> selection;
	}
	m_stance = selection;
}

void Character::setHealth(int hp)
{
	m_health = hp;
	m_maxhealth = m_health;
}

void Character::setGameState(int state)
{
	m_gameState = state;
}

void Character::setArmor(int armor)
{
	m_armor = armor;
}

void Character::setRound(int round)
{
	m_round = round;
}

void Character::setDamage(int dmgm, int dmgx)
{
	m_dmgmin = dmgm;
	m_dmgmax = dmgx;
}

void Character::setName(string name)
{
	m_name = name;
}

void Character::gameOver()
{
	if ((m_health) <= 0)
	{
		m_gameState = 1;
	}
	else if ((m_round + 1) > 10)
	{
		m_gameState = 2;
	}
	if (m_gameState == 1)
	{
		cout << "You have died!" << endl;
	}
	else if (m_gameState == 2)
	{
		cout << "You have bested the Arena" << endl;
	}
}

int Character::getGameState() const
{
	return m_gameState;
}

int Character::getHealth() const
{
	return m_health;
}

int Character::getMaxHealth() const
{
	return m_maxhealth;
}

int Character::getArmor() const
{
	return m_armor;
}

int Character::getRound() const
{
	return m_round;
}

int Character::getDamageMin() const
{
	return m_dmgmin;
}

int Character::getDamageMax() const
{
	return m_dmgmax;
}

string Character::getName() const
{
	return m_name;
}

ostream &operator<<(ostream &os, const Character & rhs)
{
	int tempDmgMax = rhs.m_dmgmax;
	int tempDmgMin = rhs.m_dmgmin;
	int tempArmor = rhs.m_armor;
	if (rhs.m_stance == 2) //block
	{
		tempDmgMax *= .5;
		tempDmgMin *= .5;
		tempArmor *= 1.5;
		if (rhs.m_armor < 4)
		{
			tempArmor += 1;
		}
		os << "Name: " << rhs.m_name << endl << "Health: " << rhs.m_health << endl << "Armor: " << tempArmor << endl << "Damage: " << tempDmgMin << "-" << tempDmgMax << endl
			<< "Stance: Blocking" << endl;
	}
	else if (rhs.m_stance == 3) //berserk
	{
		tempDmgMax *= 1.5;
		tempDmgMin *= 1.5;
		tempArmor *= .5;
		os << "Name: " << rhs.m_name << endl << "Health: " << rhs.m_health << endl << "Armor: " << tempArmor << endl << "Damage: " << tempDmgMin << "-" << tempDmgMax << endl
			<< "Stance: Berserk" << endl;
	}
	else //normal
	{
		os << "Name: " << rhs.m_name << endl << "Health: " << rhs.m_health << endl << "Armor: " << tempArmor << endl << "Damage: " << tempDmgMin << "-" << tempDmgMax << endl
			<< "Stance: Normal" << endl;
	}
	return os;
}
