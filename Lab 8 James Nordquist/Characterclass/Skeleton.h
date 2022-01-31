#ifndef SKELETON_H
#define SKELETON_H
#include "Monster.h"
class Skeleton: virtual public Monster
{
public:
	Skeleton();
	Skeleton(const Skeleton &copy);
	Skeleton &operator=(const Skeleton &rhs);
	virtual ~Skeleton();
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