#ifndef LION_H
#define LION_H
#include "Monster.h"
class Lion: virtual public Monster
{
public:
	Lion();
	Lion(const Lion &copy);
	Lion & operator =(const Lion &rhs);
	virtual ~Lion();
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