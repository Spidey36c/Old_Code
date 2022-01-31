#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>
using std::cout;
using std::cin;
using std::endl;
using std::stoi;
using std::ofstream;
using std::ifstream;
using std::srand;
using std::rand;
using std::time;
using std::getline;
#include "Monster.h"
#include "Character.h"
#include "Zombie.h"
#include "Wizard.h"
#include "Imp.h"
#include "Griffon.h"
#include "Knight.h"
#include "Slime.h"
#include "Lion.h"
#include "GiantEagle.h"
#include "Lich.h"
#include "Skeleton.h"
#include "List.h"
#include <crtdbg.h>

void Save(List<Monster *> &tosave, Character tosavechar);
void Load(List<Monster *> &restart, Character &restartchar);
void FillList(List<Monster *> &tofill);
void Restart(List<Monster *> &restartlist, Character &restartchar);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(0));
	int selection = 0;
	int cselect = 0;
	int restart = 1;
	int wonround = 1;
	string temp;
	string buffer;

	Monster * currentmonster;
	List<Monster *> monsters;
	Character premade1;
	Character premade2;
	Character premade3;
	Character Chosen;

	premade1.generateFull();
	premade2.generateFull();
	premade3.generateFull();

	cout << "Welcome to the Arena!" << endl;
	cout << "1) Start a new game with a generated character" << endl;
	cout << "2) Start a new game with your own character" << endl;
	cout << "3) Load a game" << endl;
	cout << "4) Exit" << endl;
	cout << "> ";
	cin >> selection;
	while (selection < 1 || selection > 4)
	{
		cout << "Invalid Selection" << endl;
		cout << "1) Start a new game with a generated character" << endl;
		cout << "2) Start a new game with your own character" << endl;
		cout << "3) Load a game" << endl;
		cout << "4) Exit" << endl;
		cout << "> ";
		cin >> selection;
	}
	while (selection != 4)
	{
		switch (selection)
		{
		case 1:
			cout << "1) " << premade1;
			cout << "2) " << premade2;
			cout << "3) " << premade3;
			cout << "Who do you choose? If you don't like anyone pick 4 to redo their stats" << endl;
			cout << "> ";
			cin >> selection;
			while (selection < 1 || selection > 4)
			{
				cout << "Invalid Selection" << endl;
				cout << "1) " << premade1;
				cout << "2) " << premade2;
				cout << "3) " << premade3;
				cout << "Who do you choose? If you don't like anyone pick 4 to redo their stats" << endl;
				cout << "> ";
				cin >> selection;
			}
			while (selection == 4)
			{
				premade1.generateFull();
				premade2.generateFull();
				premade3.generateFull();

				cout << "1) " << premade1;
				cout << "2) " << premade2;
				cout << "3) " << premade3;
				cout << "Who do you choose? If you don't like anyone pick 4 to redo their stats" << endl;
				cout << "> ";
				cin >> selection;
				while (selection < 1 || selection > 4)
				{
					cout << "Invalid Selection" << endl;
					cout << "1) " << premade1;
					cout << "2) " << premade2;
					cout << "3) " << premade3;
					cout << "Who do you choose? If you don't like anyone pick 4 to redo their stats" << endl;
					cout << "> ";
					cin >> selection;
				}
			}
			if (selection == 1)
			{
				Chosen = premade1;
			}
			else if (selection == 2)
			{
				Chosen = premade2;
			}
			else
			{
				Chosen = premade3;
				selection = 2;
			}
			break;
		case 2:
			cout << "What is the name of your character?" << endl;
			cout << "> ";

			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, buffer);
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());

			Chosen.setName(buffer);
			Chosen.generateStats();

			cout << Chosen;
			cout << "Is this what you would like your character to be?(y/n) ";

			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, buffer);
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			while (buffer != "y" && buffer != "Y" && buffer != "n" && buffer != "N")
			{
				cout << "Invalid Selection" << endl;
				cout << Chosen;
				cout << "Is this what you would like your character to be?(y/n) ";

				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, buffer);
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}
			while (buffer == "n" || buffer == "N")
			{
				Chosen.generateStats();

				cout << Chosen;
				cout << "Is this what you would like your character to be?(y/n) ";

				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, buffer);
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				while (buffer != "y" && buffer != "Y" && buffer != "n" && buffer != "N")
				{
					cout << "Invalid Selection" << endl;
					cout << Chosen;
					cout << "Is this what you would like your character to be?(y/n) ";

					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, buffer);
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
				}
			}
			break;
		case 3:
			Load(monsters, Chosen);
			if (Chosen.getName() == "")
			{
				cout << "Something went wrong and the character didn't load" << endl;
				cout << "Do you want to try again?(y/n) ";

				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, buffer);
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				while (buffer != "y" && buffer != "Y" && buffer != "n" && buffer != "N")
				{
					cout << "Invalid Selection" << endl;
					cout << "Something went wrong and the character didn't load" << endl;
					cout << "Do you want to try again?(y/n) ";

					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, buffer);
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
				}
				while ((buffer == "y" || buffer == "Y" )&& Chosen.getName() == "")
				{
					Load(monsters, Chosen);
					if (Chosen.getName() == "" && restart == 1)
					{
						cout << "Something went wrong and the character didn't load" << endl;
						cout << "Do you want to try again?(y/n) ";

						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, buffer);
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						while (buffer != "y" && buffer != "Y" && buffer != "n" && buffer != "N")
						{
							cout << "Invalid Selection" << endl;
							cout << "Something went wrong and the character didn't load" << endl;
							cout << "Do you want to try again?(y/n) ";

							cin.ignore(cin.rdbuf()->in_avail());
							getline(cin, buffer);
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
						}
					}
				}
				if(buffer == "n" || buffer == "N")
				{
					restart = 0;
					selection = 4;
				}
			}
			if (restart == 1)
			{
				cout << Chosen;
				cout << "Is this the character you wanted to load?(y/n) ";

				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, buffer);
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}
			while (buffer != "y" && buffer != "Y" && buffer != "n" && buffer != "N")
			{
				cout << "Invalid Selection" << endl;
				cout << Chosen;
				cout << "Is this the character you wanted to load?(y/n) ";

				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, buffer);
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}
			while ((buffer == "n" || buffer == "N") && restart == 1)
			{
				temp = Chosen.getName();
				Load(monsters, Chosen);

				if (Chosen.getName() == temp)
				{
					cout << "Something went wrong and the character didn't load" << endl;
					cout << "Do you want to try again?(y/n) ";

					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, buffer);
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					while (buffer != "y" && buffer != "Y" && buffer != "n" && buffer != "N")
					{
						cout << "Invalid Selection" << endl;
						cout << "Something went wrong and the character didn't load" << endl;
						cout << "Do you want to try again?(y/n) ";

						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, buffer);
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
					}
					while ((buffer == "y" || buffer == "Y") && Chosen.getName() == "")
					{
						Load(monsters, Chosen);
						if (Chosen.getName() == "" && restart == 1)
						{
							cout << "Something went wrong and the character didn't load" << endl;
							cout << "Do you want to try again?(y/n) ";

							cin.ignore(cin.rdbuf()->in_avail());
							getline(cin, buffer);
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							while (buffer != "y" && buffer != "Y" && buffer != "n" && buffer != "N")
							{
								cout << "Invalid Selection" << endl;
								cout << "Something went wrong and the character didn't load" << endl;
								cout << "Do you want to try again?(y/n) ";

								cin.ignore(cin.rdbuf()->in_avail());
								getline(cin, buffer);
								cin.clear();
								cin.ignore(cin.rdbuf()->in_avail());
							}
						}
					}
					if (buffer == "n" || buffer == "N")
					{
						restart = 0;
						selection = 4;
					}
				}
				if (restart == 1)
				{
					cout << Chosen;
					cout << "Is this the character you wanted to load?(y/n) ";

					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, buffer);
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					while (buffer != "y" && buffer != "Y" && buffer != "n" && buffer != "N")
					{
						cout << "Invalid Selection" << endl;
						cout << Chosen;
						cout << "Is this the character you wanted to load?(y/n) ";

						cin.ignore(cin.rdbuf()->in_avail());
						getline(cin, buffer);
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
					}
				}
			}
			break;
		}
		if (selection != 3 && restart == 1)
		{
			monsters.purge();
			FillList(monsters);
			Save(monsters, Chosen);
		}
		while (Chosen.getGameState() == 0 && restart == 1)
		{
			if (wonround == 1)
			{
				restart = 0;
				wonround = 0;
			}
			if (restart == 1)
			{
				monsters.purge();
				Restart(monsters, Chosen);
			}
			cout << endl << "You are " << Chosen.getName() << ". You've joined the arena and you are currently at round " << Chosen.getRound() << " out of 10" << endl;
			cout << "Your foe approaches..." << endl << endl;

			currentmonster = monsters.getSpecificData(Chosen.getRound());
			currentmonster->display();

			while (Chosen.getHealth() > 0 && currentmonster->getHealth() > 0 && Chosen.getRound() <= 10)
			{
				cout << Chosen;
				cout << "What will you do?" << endl;
				cout << "1) Attack" << endl;
				cout << "2) Change Stance" << endl;

				cin >> cselect;
				while (cselect < 1 || cselect > 2)
				{
					cout << "Invalid Selection" << endl;
					cout << Chosen;
					cout << "What will you do?" << endl;
					cout << "1) Attack" << endl;
					cout << "2) Change Stance" << endl;

					cin >> cselect;
				}
				while (cselect == 2)
				{
					Chosen.stanceChange();
					cout << Chosen;
					cout << "What will you do?" << endl;
					cout << "1) Attack" << endl;
					cout << "2) Change Stance" << endl;

					cin >> cselect;
					while (cselect < 1 || cselect > 2)
					{
						cout << "Invalid Selection" << endl;
						cout << Chosen;
						cout << "What will you do?" << endl;
						cout << "1) Attack" << endl;
						cout << "2) Change Stance" << endl;

						cin >> cselect;
					}
				}
				cout << "You attack!" << endl << endl;

				currentmonster->defend(Chosen.attack());
				if (currentmonster->getHealth() <= 0)
				{
					cout << "Your opponent has died!" << endl << endl;
				}
				else
				{
					currentmonster->display();
					cout << "Your opponent attacks!" << endl << endl;
					Chosen.defend(currentmonster->attack());
				}
			}

			Chosen.gameOver();

			if (Chosen.getGameState() == 0)
			{
				wonround = 1;

				cout << "You've won this fight. You have been healed by the arenas apothecaries" << endl;
				Chosen.setHealth(Chosen.getMaxHealth());
				Chosen.setRound(Chosen.getRound() + 1);

				Save(monsters, Chosen);

				cout << "Your progress has been saved. Do you wish to fight your next opponent?(y/n) ";

				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, buffer);
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				while (buffer != "y" && buffer != "Y" && buffer != "n" && buffer != "N")
				{
					cout << "Invalid Selection" << endl;
					cout << "Your progress has been saved. Do you wish to fight your next opponent?(y/n) ";

					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, buffer);
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
				}
				if (buffer == "y" || buffer == "Y")
				{
					restart = 1;
				}
				else
				{
					selection = 4;
				}
			}
			else if (Chosen.getGameState() == 1)
			{
				cout << "Do you wish to try again?(y/n)";

				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, buffer);
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				while (buffer != "y" && buffer != "Y" && buffer != "n" && buffer != "N")
				{
					cout << "Invalid Selection" << endl;
					cout << "Do you wish to try again?(y/n)";

					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, buffer);
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
				}
				if (buffer == "y" || buffer == "Y")
				{
					restart = 1;
					Chosen.setGameState(0);
				}
				else
				{
					selection = 4;
				}
			}
		}
		if (Chosen.getGameState() == 2)
		{
			cout << "The arena may have more use of you" << endl;
			cout << "1) Start another game with a generated character" << endl;
			cout << "2) Start another game with a new character" << endl;
			cout << "3) Load a game" << endl;
			cout << "4) Exit" << endl;
			cout << "> ";

			cin >> selection;
		}
		if (selection == 4)
		{
			cout << "We will see you again in the arena soon" << endl;
		}
		
	}
	return 0;
}

void Save(List<Monster*> &tosave, Character tosavechar)
{
	string fileend = ".txt";
	string name = tosavechar.getName();
	string filename = name + fileend;
	Monster *temp;

	ofstream fout;
	fout.open(filename);
	if (fout.is_open())
	{
		fout << tosavechar.getName().c_str() << endl;
		fout << tosavechar.getHealth() << " " << tosavechar.getArmor() << endl;
		fout << tosavechar.getDamageMin() << " " << tosavechar.getDamageMax() << endl;
		fout << tosavechar.getRound() << endl;
		for (int i = 0; i < 10; i++)
		{
			temp = tosave.getSpecificData(i + 1);

			fout << temp->getType() << endl;
			fout << temp->getHealth() << endl;
			fout << temp->getDmgMin() << " " << temp->getDmgMax() << endl;
		}
		fout.close();
	}
	else
	{
		cout << "File could not be opened" << endl;
	}
}

void Load(List<Monster*>& toload, Character & toloadchar)
{
	Monster * temp;
	string fileend = ".txt";
	string buffer;

	cout << "Whats the name of the Character you are trying to load? ";

	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, buffer);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	string filename = buffer + fileend;

	int i = 0;
	int itemp1;
	int itemp2;
	int selection;

	ifstream fin;
	fin.open(filename);
	if(fin.is_open())
	{
		getline(fin, buffer);
		toloadchar.setName(buffer);

		fin >> buffer;
		itemp1 = stoi(buffer);
		toloadchar.setHealth(itemp1);

		fin >> buffer;
		itemp1 = stoi(buffer);
		toloadchar.setArmor(itemp1);

		fin >> buffer;
		itemp1 = stoi(buffer);
		fin >> buffer;
		itemp2 = stoi(buffer);
		toloadchar.setDamage(itemp1, itemp2);

		fin >> buffer;
		itemp1 = stoi(buffer);
		toloadchar.setRound(itemp1);
		while(i < 10)
		{
			fin >> buffer;
			selection = stoi(buffer);
			switch (selection)
			{
			case 1:
				temp = new Zombie;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				toload.append(temp);
				break;
			case 2:
				temp = new Imp;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				toload.append(temp);
				break;
			case 3:
				temp = new Slime;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				toload.append(temp);
				break;
			case 4:
				temp = new Lion;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				toload.append(temp);
				break;
			case 5:
				temp = new GiantEagle;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				toload.append(temp);
				break;
			case 6:
				temp = new Wizard;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				toload.append(temp);
				break;
			case 7:
				temp = new Knight;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				toload.append(temp);
				break;
			case 8:
				temp = new Skeleton;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				toload.append(temp);
				break;
			case 9:
				temp = new Griffon;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				toload.append(temp);
				break;
			case 10:
				temp = new Lich;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				toload.append(temp);
				break;
			}
			i++;
		}
		fin.close();
	}
	else
	{
		cout << "Character could not be loaded" << endl;
	}
}

void FillList(List<Monster*>& tofill)
{
	int x = 0;
	Monster * temp;
	while (x < 10)
	{
		while (x < 10)
		{
			int selection;
			selection = rand() % 10 + 1;
			switch (selection)
			{
			case 1:
				temp = new Zombie;
				temp->generate();

				tofill.insertOrdered(temp);
				break;
			case 2:
				temp = new Imp;
				temp->generate();

				tofill.insertOrdered(temp);
				break;
			case 3:
				temp = new Slime;
				temp->generate();

				tofill.insertOrdered(temp);
				break;
			case 4:
				temp = new Lion;
				temp->generate();

				tofill.insertOrdered(temp);
				break;
			case 5:
				temp = new GiantEagle;
				temp->generate();

				tofill.insertOrdered(temp);
				break;
			case 6:
				temp = new Wizard;
				temp->generate();

				tofill.insertOrdered(temp);
				break;
			case 7:
				temp = new Knight;
				temp->generate();

				tofill.insertOrdered(temp);
				break;
			case 8:
				temp = new Skeleton;
				temp->generate();

				tofill.insertOrdered(temp);
				break;
			case 9:
				temp = new Griffon;
				temp->generate();

				tofill.insertOrdered(temp);
				break;
			case 10:
				temp = new Lich;
				temp->generate();

				tofill.insertOrdered(temp);
				break;
			}
			x++;
		}
	}
}

void Restart(List<Monster*>& restart, Character & restartchar)
{
	Monster * temp;
	string fileend = ".txt";
	string buffer;
	string filename = restartchar.getName() + fileend;

	int i = 0;
	int itemp1;
	int itemp2;
	int selection;

	ifstream fin;
	fin.open(filename);
	if (fin.is_open())
	{
		getline(fin, buffer);
		restartchar.setName(buffer);

		fin >> buffer;
		itemp1 = stoi(buffer);
		restartchar.setHealth(itemp1);

		fin >> buffer;
		itemp1 = stoi(buffer);
		restartchar.setArmor(itemp1);

		fin >> buffer;
		itemp1 = stoi(buffer);
		fin >> buffer;
		itemp2 = stoi(buffer);
		restartchar.setDamage(itemp1, itemp2);

		fin >> buffer;
		itemp1 = stoi(buffer);
		restartchar.setRound(itemp1);

		while (i < 10)
		{
			fin >> buffer;
			selection = stoi(buffer);
			switch (selection)
			{
			case 1:
				temp = new Zombie;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				restart.append(temp);
				break;
			case 2:
				temp = new Imp;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				restart.append(temp);
				break;
			case 3:
				temp = new Slime;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				restart.append(temp);
				break;
			case 4:
				temp = new Lion;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				restart.append(temp);
				break;
			case 5:
				temp = new GiantEagle;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				restart.append(temp);
				break;
			case 6:
				temp = new Wizard;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				restart.append(temp);
				break;
			case 7:
				temp = new Knight;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				restart.append(temp);
				break;
			case 8:
				temp = new Skeleton;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				restart.append(temp);
				break;
			case 9:
				temp = new Griffon;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				restart.append(temp);
				break;
			case 10:
				temp = new Lich;
				fin >> buffer;
				itemp1 = stoi(buffer);
				temp->setHealth(itemp1);

				fin >> buffer;
				itemp1 = stoi(buffer);
				fin >> buffer;
				itemp2 = stoi(buffer);
				temp->setDamage(itemp1, itemp2);

				restart.append(temp);
				break;
			}
			i++;
		}
		fin.close();
	}
	else
	{
		cout << "Character could not be loaded" << endl;
	}
}
