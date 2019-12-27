#include "Game.h"


Game::Game(string initBoard)
{
	this->charsTable = initBoard;
	this->isChess = false;
	this->isMate = false; 
	this->turn = false;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			this->table[i][j] = nullptr;
		}
	}
}

Game:: ~Game() = default;

void Game::manageGame()
{
}

