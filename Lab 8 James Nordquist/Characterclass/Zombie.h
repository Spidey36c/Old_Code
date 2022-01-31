#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Monster.h"
class Zombie: virtual public Monster
{
public:
	Zombie();
	Zombie(const Zombie & copy);
	Zombie &operator =(const Zombie & rhs);
	virtual ~Zombie();
	virtual void generate();
	virtual void display();
	virtual int attack();
	virtual void defend(int dmg);
	virtual void setHealth(int hp);
	virtual void setDamage(int dmgm, int dmgmax);
	virtual int getType();
	virtual int getHealth();
	virtual int getDmgMin();
	virtual int getDmgMax();
};

#endif