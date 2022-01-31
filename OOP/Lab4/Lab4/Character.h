#ifndef CHARACTER_H
#define CHARACTER_H
#include "BackPack.h"
#include "CoinPouch.h"
class Character
{
public:
	Character();
	Character(BackPack inventory, CoinPouch money, String name);
	Character(const Character &copy);
	Character &operator =(const Character &rhs);
	~Character();
	BackPack getInventory() const;
	CoinPouch getPouch() const;
	String getName() const;
	void setInv(BackPack inventory);
	void setPouch(CoinPouch pouch);
	void setName(String name);
	void buyItem(Potion itemtobuy);
	void addItem(Potion itemtoadd);
	void useItem();
	void sellItem();
private:
	BackPack m_inventory;
	CoinPouch m_pouch;
	String m_name;
};

#endif