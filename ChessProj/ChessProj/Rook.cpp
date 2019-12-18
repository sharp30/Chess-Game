#pragma once
#include "Rook.h"

Rook::Rook(string color) :Piece(color,"Rook")
{
	
}

Rook::~Rook()
{

}
/*
This function adds to moveOptions all the places Rook piece can get move to (before checks about mate)
Input:board -> the board of the game
Output:None
*/
void Rook::buildMoveOptions(const Piece* board[][TABLE_SIZE])
{
	int change = 1;
	bool condPlus = (this.pos.GetCol() + change) < TABLE_SIZE;
	bool condMinus = (this.pos.GetCol() - change) >= 0;
	Piece* tmp = nullptr;
	while (condPlus || condMinus)
	{
		tmp = board[this->pos.GetRow()][this->pos.GetCol() + change];
		if (condPlus && (!tmp || tmp.GetColor != this->_color))
		{
			this->_moveOptions.push_back(new Position(tmp.GetPos());
		}
		tmp = board[this->pos.GetRow()][this->pos.GetCol() - change];
		if (condMinus && (!tmp || tmp.GetColor != this->_color))
		{
			this->_moveOptions.push_back(new Position(tmp.GetPos());
		}
		condPlus = condPlus && ((this.pos.GetCol() + change) < TABLE_SIZE) && tmp;
		condPlus = condPlus && ((this.pos.GetCol() - change) < TABLE_SIZE) && tmp;
	}	
	change = 1;
	condPlus = (this.pos.GetRow() + change) < TABLE_SIZE;
    condMinus = (this.pos.GetRow() - change) >= 0;
	while (condPlus || condMinus)
	{
		tmp = board[this->pos.GetRow() + change][this->pos.GetCol()];
		if (condPlus && (!tmp || tmp.GetColor != this->_color))
		{
			this->_moveOptions.push_back(new Position(tmp.GetPos());
		}
		tmp = board[this->pos.GetRow() - change][this->pos.GetCol()];
		if (condMinus && (!tmp || tmp.GetColor != this->_color))
		{
			this->_moveOptions.push_back(new Position(tmp.GetPos());
		}
		condPlus = condPlus && ((this.pos.GetCol() + change) < TABLE_SIZE) && tmp;
		condPlus = condPlus && ((this.pos.GetCol() - change) < TABLE_SIZE) && tmp;
	}
}
