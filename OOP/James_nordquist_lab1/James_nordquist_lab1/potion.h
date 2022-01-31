#pragma once
#include <string>
using std::string;

class potion
{
public:
	potion();
	potion(string name, string description, string potency, string cost);
	potion(const potion &obj);
	potion & operator =(const potion &rhs);
	void displayAll();
	void displayName();
	void displayTotalCost(potion stuff[], int numpotion);
	~potion();
private:
	string m_name;
	string m_description;
	string m_potency;
	string m_cost;
};

