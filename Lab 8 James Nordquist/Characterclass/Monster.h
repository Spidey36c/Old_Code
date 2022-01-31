#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include <ostream>
using std::string;
using std::ostream;

class Monster
{
public:
	Monster();
	Monster(string name, int m_type);
	Monster(const Monster & copy);
	Monster & operator =(const Monster &rhs);
	bool operator <=(const Monster &rhs);
	bool operator <(const Monster &rhs);
	bool operator >(const Monster &rhs);
	bool operator >=(const Monster &rhs);
	virtual ~Monster();
	virtual void generate() = 0;
	virtual int attack() = 0;
	virtual void display() = 0;
	virtual void defend(int dmg) = 0;
	virtual void setHealth(int hp) = 0;
	virtual void setDamage(int dmgm, int dmgmax) = 0;
	virtual int getType() = 0;
	virtual int getHealth() = 0;
	virtual int getDmgMin() = 0;
	virtual int getDmgMax() = 0;
protected:
	int m_type; //to distinguish type of monster when reading from file
	string m_name;
	int m_health;
	int m_dmgmin;
	int m_dmgmax;
};

#endif