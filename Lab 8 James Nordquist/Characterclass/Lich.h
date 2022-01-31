#ifndef LICH_H
#define LICH_H
#include "Zombie.h"
#include "Wizard.h"
class Lich:virtual public Wizard, virtual public Zombie
{
public:
	Lich();
	Lich(const Lich& copy);
	Lich &operator =(const Lich &rhs);
	virtual ~Lich();
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