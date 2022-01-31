/********************************************************************************************
* Author: James Nordquist
* Filename : Table.h
* Date Created : 2/8/19
* Modifications Made : 2/9/19 - added CalculateMoveCards() and Win() m_efreecells and m_ecolumns
*					   2/11/19 - added m_ocards
*					   2/12/19 - fixed Move(), didn't accuratly move the right amount of cards
***********************************************************************************************/
#include "Table.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
using std::exception;
using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::stoi;
using std::setw;
using std::cin;
using std::right;
using std::left;

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* Object is created
*
* Postcondition:
* Object is instantiated with default values
*
************************************************************************/
Table::Table(): m_freecells(4), m_efreecells(4), m_ocards(0), m_ecolumns(0), m_movcards(5) //1 + m_efreecells * 2^m_ecolumns
{
	for (int i = 0; i < 4; i++)
	{
		m_home[i].SetSize(13);
	}
}

/**********************************************************************
* Purpose: default ctor
*
* Precondition:
* Object is created using another existing object
*
* Postcondition:
* Object is instantiated with the other objects values
*
************************************************************************/
Table::Table(const Table & copy) : m_cards(copy.m_cards), m_freecells(copy.m_freecells), m_efreecells(copy.m_efreecells), m_ocards(copy.m_ocards), m_ecolumns(copy.m_ecolumns), m_movcards(copy.m_movcards)
{
	for (int i = 0; i < 8; i++)
	{
		m_columns[i] = copy.m_columns[i];
	}
	for (int i = 0; i < 4; i++)
	{
		m_home[i] = copy.m_home[i];
	}
}

/**********************************************************************
* Purpose: dtor
*
* Precondition:
* Object is deleted or goes out of scope
*
* Postcondition:
* Objects data is set to default or 0
*
************************************************************************/
Table::~Table()
{
	m_freecells.SetLength(0);
	m_win = false;
	m_ecolumns = 0;
	m_efreecells = 0;
	m_ocards = 0;
	m_movcards = 0;
}

/**********************************************************************
* Purpose: op = 
*
* Precondition:
* Object is set to equal another object
*
* Postcondition:
* Objects data is set to the same as the other objects value
*
************************************************************************/
Table & Table::operator=(const Table & rhs)
{
	if (this != &rhs)
	{
		m_cards = rhs.m_cards;
		for (int i = 0; i < 8; i++)
		{
			m_columns[i] = rhs.m_columns[i];
		}
		m_freecells = rhs.m_freecells;
		for (int i = 0; i < 4; i++)
		{
			m_home[i] = rhs.m_home[i];
		}
		m_efreecells = rhs.m_efreecells;
		m_ocards = rhs.m_ocards;
		m_ecolumns = rhs.m_ecolumns;
		m_movcards = rhs.m_movcards;
	}
	return *this;
}

/**********************************************************************
* Purpose: calculates how many cards can be moved
*
* Precondition:
* function is called
*
* Postcondition:
* m_movcards is set to how many cards can be moved
*
************************************************************************/
void Table::CalculateMoveCards()
{
	m_movcards = m_efreecells + 1;
	for (int i = 0; i < m_ecolumns; i++)
	{
		m_movcards *= 2;
	}
}

/**********************************************************************
* Purpose: fills the columns with m_cards cards
*
* Precondition:
* function is called
*
* Postcondition:
* m_columns is filled with cards from the deck
*
************************************************************************/
void Table::GenerateTable()
{
	m_cards.GenerateDeck();
	m_cards.RandomizeDeck();

	for (int i = 0; i < 4; i++) //build left side of table
	{
		while (m_columns[i].Size() != 7)
		{
			m_columns[i].Push(m_cards.Deal());
		}
	}

	for (int i = 4; i < 8; i++) //build right side of table
	{
		while (m_columns[i].Size() != 6)
		{
			m_columns[i].Push(m_cards.Deal());
		}
	}
}

/**********************************************************************
* Purpose: allows the user to move cards using different commands
*
* Precondition:
* function is called
*
* Postcondition:
* moves the cards the user wants to move if the move command is possible
*
************************************************************************/
void Table::Move()
{
	ListStack<Card> tomove;
	bool pmove = true; //possible move
	int a;
	int b;
	string buffer;
	int pos;
	string temp1;
	string temp2;
	cout << "mcc #A #B - Move cards from column #A to column #B" << endl;
	cout << "mcf #A #B - Move a card from column #A to freecell #B" << endl;
	cout << "mch #A #B - Move a card from column #A to home cell #B" << endl;
	cout << "mfc #A #B - Move a card from freecell #A to column #B" << endl;
	cout << "mfh #A #B - Move a card from freecell #A to home cell #B" << endl;
	cout << "> ";
	getline(cin, buffer);
	pos = buffer.find(" ");
	temp2 = buffer.substr(pos+1); //holds the numbers
	temp1 = buffer.substr(0, pos); //holds the command

	for (int i = 0; i < temp1.size(); i++)
	{
		temp1[i] = tolower(temp1[i]);
	}

	if (temp1 == "mcc")
	{
		pos = temp2.find(" ");
		buffer = temp2.substr(pos + 1);
		temp1 = temp2.substr(0, pos);

		try
		{
			a = stoi(temp1);
		}
		catch (exception &e)
		{
			pmove = false;
			cout << "Invalid #A" << endl;
		}

		try
		{
			b = stoi(buffer);
		}
		catch (exception &e)
		{
			pmove = false;
			cout << "Invalid #B" << endl;
		}

		if (pmove == true && a >= 8 || a < 0 || b >= 8 || b < 0)
		{
			cout << "Out of bounds" << endl;
			pmove = false;
		}

		if (pmove == true)
		{
			if (m_columns[a].IsEmpty() == false)
			{
				if (m_columns[b].IsEmpty() == true)
				{
					tomove.Push(m_columns[a].Pop());
					m_ecolumns--;
					CalculateMoveCards();
					while (pmove == true && m_columns[a].IsEmpty() == false && tomove.Size() < m_movcards)
					{
						if (m_columns[a].Peek().GetIValue() == tomove.Peek().GetIValue() + 1 && m_columns[a].Peek().GetRed() != tomove.Peek().GetRed())
						{
							tomove.Push(m_columns[a].Pop());
						}
						else
						{
							pmove = false; //drop out of loop
						}
					}

					while (tomove.IsEmpty() == false)
					{
						m_columns[b].Push(tomove.Pop()); //put the cards in the b column
					}
					if (m_columns[a].IsEmpty())
					{
						m_ecolumns++;
					}
				}
				else if (m_columns[a].Peek() < m_columns[b].Peek())
				{
					tomove.Push(m_columns[a].Pop());
					CalculateMoveCards();
					while (pmove == true && m_columns[a].IsEmpty() == false && tomove.Size() < m_movcards && m_columns[a].Peek().GetIValue() <= m_columns[b].Peek().GetIValue() - 1)
					{
						if ((m_columns[a].Peek().GetIValue()) == (tomove.Peek().GetIValue() + 1) && m_columns[a].Peek().GetRed() != tomove.Peek().GetRed())
						{
							tomove.Push(m_columns[a].Pop());
						}
						else
						{
							pmove = false; //drop out of loop
						}
					}
					if (tomove.Peek().GetIValue() == m_columns[b].Peek().GetIValue() - 1 && tomove.Peek().GetRed() != m_columns[b].Peek().GetRed())
					{
						while (tomove.IsEmpty() == false)
						{
							m_columns[b].Push(tomove.Pop()); //put the cards in the b column
						}
						if (m_columns[a].IsEmpty())
						{
							m_ecolumns++;
						}
					}
					else
					{
						while (tomove.IsEmpty() == false)
						{
							m_columns[a].Push(tomove.Pop()); //return the cards to the a column
						}
					}
				}
			}
			else
			{
				cout << "No cards in Column " << a << endl;
			}
		}
	}
	else if (temp1 == "mcf")
	{
		pos = temp2.find(" ");
		buffer = temp2.substr(pos + 1);
		temp1 = temp2.substr(0, pos);

		try
		{
			a = stoi(temp1);
		}
		catch (exception &e)
		{
			pmove = false;
			cout << "Invalid #A" << endl;
		}

		try
		{
			b = stoi(buffer);
		}
		catch (exception &e)
		{
			pmove = false;
			cout << "Invalid #B" << endl;
		}

		if (pmove == true && a >= 8 || a < 0 || b >= 4 || b < 0)
		{
			cout << "Out of bounds" << endl;
			pmove = false;
		}

		if (pmove == true)
		{
			if (m_columns[a].IsEmpty() == false)
			{
				if (m_freecells[b].GetValue() == "0")
				{
					m_freecells[b] = m_columns[a].Pop(); //freecell now has a value
					if (m_columns[a].IsEmpty())
					{
						m_ecolumns++;
					}
					m_efreecells--;
					m_ocards++;
				}
				else
				{
					cout << "Already a value in freecell " << b << endl;
				}
			}
			else
			{
				cout << "No cards in column " << a << endl;
			}
		}
	}
	else if (temp1 == "mch")
	{
		pos = temp2.find(" ");
		buffer = temp2.substr(pos + 1);
		temp1 = temp2.substr(0, pos);

		try
		{
			a = stoi(temp1);
		}
		catch (exception &e)
		{
			pmove = false;
			cout << "Invalid #A" << endl;
		}

		try
		{
			b = stoi(buffer);
		}
		catch (exception &e)
		{
			pmove = false;
			cout << "Invalid #B" << endl;
		}

		if (pmove == true && a >= 8 || a < 0 || b >= 4 || b < 0)
		{
			cout << "Out of bounds" << endl;
			pmove = false;
		}

		if (pmove == true)
		{
			if (m_columns[a].IsEmpty() == false)
			{
				if (m_home[b].IsEmpty() == true)
				{
					if (m_columns[a].Peek().GetValue() == "A")
					{
						m_home[b].Push(m_columns[a].Pop());
						m_ocards++;
					}
					if (m_columns[a].IsEmpty())
					{
						m_ecolumns++;
					}
				}
				else
				{
					if (m_columns[a].Peek().GetIValue() == m_home[b].Peek().GetIValue() + 1 && m_columns[a].Peek().GetSuit() == m_home[b].Peek().GetSuit())
					{
						m_home[b].Push(m_columns[a].Pop());
						m_ocards++;
					}
					if (m_columns[a].IsEmpty())
					{
						m_ecolumns++;
					}
				}
			}
			else
			{
				cout << "No cards in column " << a << endl;
			}
		}
	}
	else if (temp1 == "mfc")
	{
		pos = temp2.find(" ");
		buffer = temp2.substr(pos + 1);
		temp1 = temp2.substr(0, pos);

		try
		{
			a = stoi(temp1);
		}
		catch (exception &e)
		{
			pmove = false;
			cout << "Invalid #A" << endl;
		}

		try
		{
			b = stoi(buffer);
		}
		catch (exception &e)
		{
			pmove = false;
			cout << "Invalid #B" << endl;
		}

		if (pmove == true && a >= 4 || a < 0 || b >= 8 || b < 0)
		{
			cout << "Out of bounds" << endl;
			pmove = false;
		}

		if (pmove == true)
		{
			if (m_freecells[a].GetValue() != "0")
			{
				if (m_columns[b].IsEmpty())
				{
					m_columns[b].Push(m_freecells[a]);
					m_freecells[a].SetValue("0");
					m_efreecells++;
					m_ecolumns--;
					m_ocards--;
				}
				else if (m_freecells[a].GetIValue() == m_columns[b].Peek().GetIValue() - 1 && m_freecells[a].GetRed() != m_columns[b].Peek().GetRed())
				{
					m_columns[b].Push(m_freecells[a]);
					m_freecells[a].SetValue("0");
					m_efreecells++;
					m_ocards--;
				}
			}
			else
			{
				cout << "Freecell " << a << " is empty" << endl;
			}
		}
	}
	else if (temp1 == "mfh")
	{
		pos = temp2.find(" ");
		buffer = temp2.substr(pos + 1);
		temp1 = temp2.substr(0, pos);

		try
		{
			a = stoi(temp1);
		}
		catch (exception &e)
		{
			pmove = false;
			cout << "Invalid #A" << endl;
		}

		try
		{
			b = stoi(buffer);
		}
		catch (exception &e)
		{
			pmove = false;
			cout << "Invalid #B" << endl;
		}

		if (pmove == true && a >= 4 || a < 0 || b >= 4 || b < 0)
		{
			cout << "Out of bounds" << endl;
			pmove = false;
		}

		if (pmove == true)
		{
			if (m_freecells[a].GetValue() != "0")
			{
				if (m_home[b].IsEmpty() == true)
				{
					if (m_freecells[a].GetValue() == "A")
					{
						m_home[b].Push(m_freecells[a]);
						m_freecells[a].SetValue("0");
						m_efreecells++;
					}
				}
				else
				{
					if (m_freecells[a].GetIValue() == m_home[b].Peek().GetIValue() + 1 && m_freecells[a].GetSuit() == m_home[b].Peek().GetSuit())
					{
						m_home[b].Push(m_freecells[a]);
						m_freecells[a].SetValue("0");
						m_efreecells++;
					}
				}
			}
			cout << "Freecell " << a << " is empty" << endl;
		}
	}
	else
	{
		cout << "I don't understand that command" << endl;
	}
}

/**********************************************************************
* Purpose: displays the current state of the table
*
* Precondition:
* function is called
*
* Postcondition:
* table is displayed
*
************************************************************************/
void Table::Display()
{
	ListStack<Card> temp[8];
	Array<Card> todisplay[8];
	int index = 0;
	int size = 0;
	
	for (int i = 0; i < 8; i++)
	{
		temp[i] = m_columns[i]; //copy over the columns so no change is made to the game itself
	}

	for (int i = 0; i < 8; i++)
	{
		todisplay[i].SetLength(temp[i].Size());
		for (int j = temp[i].Size() - 1; j >= 0; j--)
		{
			todisplay[i][j] = temp[i].Pop(); //put the cards in the array backwards
		}
	}

	cout << "Freecells" << setw(13) << "Home Cells" << endl;
	for (int i = 0; i < 4; i++)
	{
		if (m_freecells[i].GetValue() != "0")
		{
			cout << m_freecells[i] << " ";
		}
		else
		{
			cout << "_ ";
		}
	}
	cout << setw(6);
	for (int i = 0; i < 4; i++)
	{
		if (m_home[i].IsEmpty() == false)
		{
			cout << m_home[i].Peek() << " ";
		}
		else
		{
			cout << "_ ";
		}
	}
	cout << endl << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << setw(4) << left << i << right;
	}
	cout << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << "----";
	}
	cout << endl;

	cout << setw(4) << right;
	for (int i = 0; i < 52 - m_ocards; i++)
	{
		if (size >= todisplay[index].GetLength())
		{
			cout << "    ";
			i--;
		}
		else
		{
			cout << setw(4) << left << todisplay[index][size] << right;
		}

		if (index != 7)
		{
			index++;
		}
		else
		{
			size++;
			index = 0;
			cout << endl << setw(4) << right;
		}
	}
	cout << endl;
}

/**********************************************************************
* Purpose: checks to see if the user has won
*
* Precondition:
* function is called
*
* Postcondition:
* m_win is set to true if all the cards are on the home cells
*
************************************************************************/
void Table::Win()
{
	int check = 0;

	for (int i = 0; i < 4; i++)
	{
		if (m_home[i].IsEmpty() == false && m_home[i].Peek().GetValue() == "K")
		{
			check++;
		}
	}

	if (check == 4)
	{
		m_win = true;
	}
}

/**********************************************************************
* Purpose: main menu
*
* Precondition:
* function is called
*
* Postcondition:
* the game is played until the user wins and decides to quit
*
************************************************************************/
void Table::Game()
{
	int choice;
	while (m_win == false)
	{
		GenerateTable();
		Display();

		while (m_win == false)
		{
			Move();
			Win();
			Display();
		}

		cout << "You Won!" << endl;
		cout << "Do you want to try again?" << endl;
		cout << "1) Yes" << endl;
		cout << "2) exit" << endl;
		cin >> choice;
		while (choice < 1 || choice > 2)
		{
			cout << "Invalid selection" << endl;
			cout << "Do you want to try again?" << endl;
			cout << "1) Yes" << endl;
			cout << "2) exit" << endl;
			cin >> choice;
		}

		if (choice == 1)
		{
			m_win = false;
			for (int i = 0; i < 4; i++)
			{
				m_home[i].SetSize(0);
			}
			for (int i = 0; i < 4; i++)
			{
				m_home[i].SetSize(13);
			}
		}
	}
}
