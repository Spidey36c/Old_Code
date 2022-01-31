#include <iostream>
#include "potion.h"
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
#include <crtdbg.h>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int numpotion = 4;
	potion items[4];
	string names[4] = { "Potion of strength", "Potion of stealth", "Potion of health", "Potion of mystery" };
	string description[4] = { "Makes you strong", "Makes you invisible to the naked eye", "Heals half of your hp", "Who knows" };
	string potency[4] = { "little", "strong", "medium", "???" };
	string cost[4] = { "0.0.2.87","0.2.34.60","0.1.2.12","0.98.2.12" };
	items[0] = { names[0],description[0],potency[0],cost[0] };
	items[1] = { names[1],description[1],potency[1],cost[1] };
	items[2] = { names[2],description[2],potency[2],cost[2] };
	items[3] = { names[3],description[3],potency[3],cost[3] };

	items->displayTotalCost(items, numpotion);


	return 0;
}