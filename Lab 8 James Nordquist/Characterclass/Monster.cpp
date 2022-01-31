#include "Monster.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
using std::time;
using std::srand;
using std::rand;


Monster::Monster(): m_health(0), m_dmgmin(0), m_dmgmax(0)
{

}

Monster::Monster(string name, int type): m_type(type), m_name(name)
{
}

Monster::Monster(const Monster & copy): m_health(copy.m_health), m_dmgmin(copy.m_dmgmin), m_dmgmax(copy.m_dmgmax), m_name(copy.m_name)
{
}

Monster & Monster::operator=(const Monster & rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_health = rhs.m_health;
		m_dmgmin = rhs.m_dmgmin;
		m_dmgmax = rhs.m_dmgmax;
	}
	return *this;
}

bool Monster::operator<=(const Monster & rhs)
{
	return m_dmgmin <= rhs.m_dmgmin ? true : false;
}

bool Monster::operator<(const Monster & rhs)
{
	return m_dmgmin < rhs.m_dmgmin ? true : false;
}

bool Monster::operator>(const Monster & rhs)
{
	return m_dmgmin > rhs.m_dmgmin ? true : false;
}

bool Monster::operator>=(const Monster & rhs)
{
	return m_dmgmin >= rhs.m_dmgmin ? true : false;
}


Monster::~Monster()
{
}

