#ifndef KNIGHT_H
#define KNIGHT_H
#include "Monster.h"
class Knight:virtual public Monster
{
public:
	Knight();
	Knight(const Knight & copy);
	Knight & operator =(const Knight & copy);
	virtual ~Knight();
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