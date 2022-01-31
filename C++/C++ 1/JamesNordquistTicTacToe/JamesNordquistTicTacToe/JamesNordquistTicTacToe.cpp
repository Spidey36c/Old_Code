/*************************************
* Tic Tac Toe
* James Nordquist
**************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

void DisplayBoard(char board[3][3]);
void ClearBoard(char board[3][3]);
void UserInput(char board[3][3], char player);
void ComputerInput(char board[3][3], char player);
bool GameOver(char board[3][3], char player);

int main()
{
	char board[3][3] = {' '};
	int selection = 0;
	char player = 'x';
	int playAgain = 1;

	printf("We are going to play Tic Tac Toe!\n");
	while (playAgain == 1)
	{
		ClearBoard(board);
		DisplayBoard(board);
		printf("Who do you want to play with?\n");
		printf("1) Me!\n");
		printf("2) A friend\n");
		printf("> ");
		scanf("%d", &selection);
		if (selection <= 0 || selection > 2)
		{
			printf("That's not a valid number! Try again!\n");
		}

		while (selection <= 0 || selection > 2)
		{
			printf("1) Me!\n");
			printf("2) A friend\n");
			printf("> ");
			scanf("%d", &selection);
			if (selection <= 0 || selection > 2)
			{
				printf("That's not a valid number! Try again!\n");
			}
		}
		player = 'x';
		if (selection == 1)
		{
			printf("Woohoo! Ok you go first as x, and I'll be o\n");
			while (GameOver(board, 'x') == false && GameOver(board, 'o') == false)
			{
				if (player == 'x')
				{
					UserInput(board, player);
					DisplayBoard(board);
				}
				if (player == 'x')
				{
					player = 'o';
				}
				else
				{
					ComputerInput(board, player);
					DisplayBoard(board);
					player = 'x';
				}
			}
			printf("\n");

		}

		if (selection == 2)
		{
			while (GameOver(board, 'x') == false && GameOver(board, 'o') == false)
			{
				UserInput(board, player);
				DisplayBoard(board);
				if (player == 'x')
				{
					player = 'o';
				}
				else
				{
					player = 'x';
				}

			}
			printf("\n");
		}

		printf("Want to play again?\n");
		printf("1) Yes\n");
		printf("2) Nope\n");
		printf(">");
		scanf("%d", &playAgain);
		while (playAgain <= 0 || playAgain > 2)
		{
			printf("That's not a valid number! Try again!\n");
			printf("Want to play again?\n");
			printf("1) Yes\n");
			printf("2) Nope\n");
			scanf("%d", &playAgain);
		}
		printf("\n");
	}
	printf("It was fun!\n");
	return 0;
}

void ComputerInput(char board[3][3], char player)
{
	int success = 0;
	int selector;
	selector = 1 + (rand() % 9);
	printf("Hmmmm\n");


	while (success == 0)
	{
		int row = (selector - 1) / 3;
		int col = (selector - 1) % 3;
		if (board[row][col] == ' ')
		{
			board[row][col] = player;
			success++;
		}
		else
		{
			selector = 1 + (rand() % 9);
		}
	}

	printf("I got it!\n");
}

void DisplayBoard(char board[3][3])
{
	printf("%c (1)|  %c (2)| %c (3)\n", board[0][0], board[0][1], board[0][2]);
	printf("____________________\n");
	printf("%c (4)|  %c (5)| %c (6)\n", board[1][0], board[1][1], board[1][2]);
	printf("____________________\n");
	printf("%c (7)|  %c (8)| %c (9)\n", board[2][0], board[2][1], board[2][2]);
}

void ClearBoard(char board[3][3])
{
	for (int ii = 0; ii < 3; ii++)
	{
		for (int jj = 0; jj < 3; jj++)
		{
			board[ii][jj] = ' ';
		}
	}
}

void UserInput(char board[3][3], char player)
{
	int selector;
	int success = 0;

	printf("What Space do you want to use %c? ",player);
	scanf("%d", &selector);
	while (success == 0)
	{
		while (selector < 1 || selector > 9)
		{
			printf("That's not a valid space, try again!\n");
			scanf("%d", &selector);
		}
		int row = (selector-1) / 3;
		int col = (selector-1) % 3;

		if (board[row][col] == ' ')
		{
			board[row][col] = player;
			success++;
		}
		else
		{
			printf("That space is already being used, try again!\n");
			printf("What Space do you want to use %c? ", player);
			scanf("%d", &selector);
		}
	}
}

bool GameOver(char board[3][3], char player)
{
	for (int ii = 0; ii < 3; ii++)
	{
		if (board[ii][0] == player && board[ii][1] == player && board[ii][2] == player)
		{
			printf("%c Wins!\n", player);
			return true;
		}
	}
	for (int ii = 0; ii < 3; ii++)
	{
		if (board[0][ii] == player && board[1][ii] == player && board[2][ii] == player)
		{
			printf("%c Wins!\n", player);
			return true;
		}
	}
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
	{
		printf("%c Wins!\n", player);
		return true;
	}
	else if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
	{
		printf("%c Wins!\n", player);
		return true;
	}
	else
	{
		for (int ii = 0; ii < 3; ii++)
		{
			for (int jj = 0; jj < 3; jj++)
			{
				if (board[ii][jj] == ' ')
				{
					return false;
				}
			}
		}
		printf("It's a tie!\n");
		return true;
	}
}