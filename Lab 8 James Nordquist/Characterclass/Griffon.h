#ifndef GRIFFON_H
#define GRIFFON_H
#include "Lion.h"
#include "GiantEagle.h"
class Griffon:virtual public Lion, virtual public GiantEagle
{
public:
	Griffon();
	Griffon(const Griffon &copy);
	Griffon &operator =(const Griffon &rhs);
	virtual ~Griffon();
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