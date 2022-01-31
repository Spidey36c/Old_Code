#include <iostream>
using std::cout;
using std::endl;
#include "Stock.h"

Stock::Stock()
{
	cout << "This is a default constructor" << endl;
}
Stock::Stock(string symbol, int shares, double price) 
	: m_symbol(symbol), m_shares(shares), m_price(price)
{
	cout << symbol << endl;
}
string Stock::getStockSymbol()
{
	return m_symbol;
}
double Stock::getPrice()
{
	return m_price;
}
void Stock::setPrice(double price)
{
	m_price = price;
}
int Stock::getShares()
{
	return m_shares;
}
Stock::~Stock()
{
	cout << m_symbol << endl;
}