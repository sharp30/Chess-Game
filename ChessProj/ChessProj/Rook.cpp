#pragma once
#include "Rook.h"

Rook::Rook(string color) : Piece(color,"Rook")
{
	
}

Rook::~Rook()
{

}
const bool Rook::isValidMove(const Piece* table[][TABLE_SIZE], Position dest)
{
	bool row = this->_pos.getRow() == dest.getRow();
	bool col = this->_pos.getCol() == dest.getCol();
	if (!row && !col)
	{
		return false;
	}
	Position check(dest);

}





/*
This function adds to moveOptions all the places Rook piece can get move to (before checks about mate)
Input:board -> the board of the game
Output:None
*
void Rook::buildMoveOptions(const Piece* board[][TABLE_SIZE])
{
	int change = 1;
	bool condPlus = (this->_pos.getCol() + change) < TABLE_SIZE;
	bool condMinus = (this->_pos.getCol() - change) >= 0;
	Piece* tmp = nullptr;
	while (condPlus || condMinus)
	{
		tmp = board[this->_pos.GetRow()][this->_pos.GetCol() + change];
		if (condPlus && (!tmp || tmp.GetColor != this->_color))
		{
			this->_moveOptions.push_back(new Position(tmp.GetPos());
		}
		tmp = board[this->pos.GetRow()][this->pos.GetCol() - change];
		if (condMinus && (!tmp || tmp.GetColor != this->_color))
		{
			this->_moveOptions.push_back(new Position(tmp.GetPos());
		}
		condPlus = condPlus && ((this._pos.GetCol() + change) < TABLE_SIZE) && tmp;
		condPlus = condPlus && ((this._pos.GetCol() - change) < TABLE_SIZE) && tmp;
	}	
	change = 1;
	condPlus = (this->_pos.getRow() + change) < TABLE_SIZE;
    condMinus = (this->_pos.getRow() - change) >= 0;
	while (condPlus || condMinus)
	{
		tmp = board[this->_pos.getRow() + change][this->_pos.getCol()];
		if (condPlus && (!tmp || tmp.getColor != this->_color))
		{
			this->_moveOptions.push_back(new Position(tmp.getPos());
		}
		tmp = board[this->pos.GetRow() - change][this->pos.GetCol()];
		if (condMinus && (!tmp || tmp.GetColor != this->_color))
		{
			this->_moveOptions.push_back(new Position(tmp.getPos());
		}
		condPlus = condPlus && ((this->_pos.getCol() + change) < TABLE_SIZE) && tmp;
		condPlus = condPlus && ((this->_pos.getCol() - change) < TABLE_SIZE) && tmp;
	}
}
*/