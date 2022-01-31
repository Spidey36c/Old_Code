/*************************************************************
* Author: James Nordquist
* Filename: Source.cpp
* Date Created: 10/2/18
* Modifications: 10/3/18 - Comments
*************************************************************/
/*************************************************************
*
* Lab/Assignment: Lab 2 – Potion Class plus Self made String
*
* Overview:
* This program is a test for a potion object for the final project
* using our own string class
*
* Input:
*
* Output:
* The potion class can output the name, description, potency,
* and cost of each potion as well as the total cost of an array of potions
*
************************************************************/
#include <iostream>
#include "potion.h"
#include <string>
using std::cout;
using std::cin;
using std::endl;
#include <crtdbg.h>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int numPotion = 4; // planned to be used for rpg potion inventory
	potion items[4]; // potion array

	String names[4] = { "Potion of strength", "Potion of stealth", "Potion of health", "Potion of mystery" }; // Early thought, use string arrays and a random number generator to generate potions, Names
	String description[4] = { "Makes you strong", "Makes you invisible", "Heals half of your hp", "Who knows" }; // descriptions of potions
	String potency[4] = { "little", "strong", "medium", "???" }; // potency of potions
	String cost[4] = { "0.0.2.87","0.2.34.60","0.1.2.12","0.98.2.12" }; // cost of potions

	items[0] = { names[0],description[0],potency[0],cost[0] };
	items[1] = { names[1],description[1],potency[1],cost[1] };
	items[2] = { names[2],description[2],potency[2],cost[2] };
	items[3] = { names[3],description[3],potency[3],cost[3] };

	for (int i = 0; i < numPotion; i++)
	{
		items[i].displayName();
		items[i].displayAll();
	}

	items->displayTotalCost(items, numPotion);


	return 0;
}