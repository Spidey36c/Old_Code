#ifndef GIANTEAGLE_H
#define GIANTEAGLE_H
#include "Monster.h"
class GiantEagle: virtual public Monster
{
public:
	GiantEagle();
	GiantEagle(const GiantEagle &copy);
	GiantEagle &operator =(const GiantEagle &rhs);
	virtual ~GiantEagle();
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