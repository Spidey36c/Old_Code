#pragma once
#include <string>
using std::string;

class Stock
{
public:
	Stock();
	Stock(string symbol, int shares, double price = .01);
	~Stock();
	string getStockSymbol();
	double getPrice();
	void setPrice(double price);
	int getShares();

private:
	string  m_symbol;
	double m_price;
	int m_shares;
};
