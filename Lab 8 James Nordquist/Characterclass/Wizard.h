#ifndef WIZARD_H
#define WIZARD_H
#include "Monster.h"
class Wizard: virtual public Monster
{
public:
	Wizard();
	Wizard(const Wizard &copy);
	Wizard & operator =(const Wizard &rhs);
	virtual ~Wizard();
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