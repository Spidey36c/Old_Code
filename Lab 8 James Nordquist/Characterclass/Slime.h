#ifndef SLIME_H
#define SLIME_H
#include "Monster.h"
class Slime: virtual public Monster
{
public:
	Slime();
	Slime(const Slime &copy);
	Slime & operator =(const Slime &rhs);
	virtual ~Slime();
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