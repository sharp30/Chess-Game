#pragma once
#include "Rook.h"
// ------------------------ constractor --------------------------
Rook::Rook(string color, Position pos) : Piece(color,"Rook",pos)
{
	_isMoved = false;
}
 
// ------------------destractor --------------------------------
Rook::~Rook() = default;

/*
This function moves the piece from his previous location and changes the _isMoved value
Input:dest -> The new position of the piece
Output:None
*/
void Rook::movePosition(Position dest)
{
	this->_pos = dest;
	this->_isMoved = true;
}


/*
This function checks if the object can execute the move --- according to rook moving rules only!!!
Input:table -> the board of the game ::Piece*[][TABLE_SIZE]
	  dest -> the destination to move to :: Position\
Output:Is the move valid? ::bool
*/
bool Rook::isValidMove( Piece* const table[][TABLE_SIZE], Position dest) const
{
	bool row = this->_pos.getRow() == dest.getRow();
	bool col = this->_pos.getCol() == dest.getCol();
	bool isAbove = false;

	Position comp(dest);
	
	if (!row && !col)
	{
		return false;
	}
	isAbove = dest.getRow() > this->_pos.getRow() || dest.getCol() > this->_pos.getCol();

	//check if the next positions in the way to destination are empty or not
	while (this->_pos != comp)
	{
		if (table[comp.getRow()][comp.getCol()] != nullptr && comp != dest )
		{
			/*
			for castling that will be added in the near future ASAP
			Piece x = table[comp.getRow][comp.getCol()].getColor();
			if(!(_isMoved == false && x.getColor() == this->getColor && x.getType("king)))
			*/
			return false;
		}
		if (col)
		{
			comp.setRow(isAbove ? comp.getRow() - 1 : comp.getRow() + 1);
		}
		else
		{
			comp.setCol(isAbove ? comp.getCol() - 1 : comp.getCol() + 1);
		}
	}	
	return true;
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