#ifndef IMP_H
#define IMP_H
#include "Monster.h"
class Imp: virtual public Monster
{
public:
	Imp();
	Imp(const Imp &copy);
	Imp & operator =(const Imp &rhs);
	virtual ~Imp();
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