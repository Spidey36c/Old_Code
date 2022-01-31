#ifndef BACKPACK_H
#define BACKPACK_H

#include "DynamicArray.h"

class BackPack
{
public:
	BackPack();
	BackPack(DynamicArray bp);
	BackPack(const BackPack & copy);
	BackPack & operator =(const BackPack & rhs);
	~BackPack();
	void addPotion(Potion &newp);
	void removePotion(int selection);
	void addArrayPotion(DynamicArray &newp);
	DynamicArray getDArray() const;
private:
	DynamicArray m_potions;
};

#endif