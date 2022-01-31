#ifndef COINPOUCH_H
#define COINPOUCH_H
#include  "String.h"
class CoinPouch
{
public:
	CoinPouch();
	CoinPouch(const char *str);
	CoinPouch(String str);
	CoinPouch(const CoinPouch & copy);
	CoinPouch &operator =(const CoinPouch &rhs);
	~CoinPouch();
	String getMoney() const;
	int buy(String cost);
	void sell(String cost);
private:
	String m_money;
};

#endif