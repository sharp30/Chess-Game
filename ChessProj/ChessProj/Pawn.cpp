#include "Pawn.h"
#include <cmath>

//constractor of Pawn
Pawn::Pawn(string color, Position pos) :Piece(color,"Pawn",pos)
{
	_isMoved = false;
}
Pawn::~Pawn() = default;


/*
This function moves the piece from his previous location and changes the _isMoved value;
Input:dest -> The new position of the piece
Output:None
*/
void Pawn::movePosition(Position dest)
{
	this->_pos = dest;
	this->_isMoved = true;
}


/*
This function checks if the object can execute the move --- according to Pawn moving rules only!!!
Input:table -> the board of the game ::Piece*[][TABLE_SIZE]
	  dest -> the destination to move to :: Position
Output:Is the move valid? ::bool
*/
bool Pawn::isValidMove( Piece* const table[][TABLE_SIZE], Position dest) const
{
	bool color = this->_color.compare("white") == 0;
	if (dest.getRow() <= this->_pos.getRow() && color||
		dest.getRow() >= this->_pos.getRow() && !color)// pawn can't move backwards
	{
		return false;
	}
	if (this->_pos.getCol() == dest.getCol())// regular move 
	{
		int maxSteps = this->_isMoved ? 1: 2;
		bool isEmpty = true;
		//check if the way to the destination is Empty
		if (abs((int)this->_pos.getRow() - (int)dest.getRow()) == 2)
		{
			isEmpty = table[color? (int)dest.getRow() - 1 : (int)dest.getRow() +1][dest.getCol()] == nullptr;
		}
		if (color)
		{
			return isEmpty && this->_pos.getRow() + maxSteps >= dest.getRow() && !table[dest.getRow()][dest.getCol()];
		}
		else
		{
			return isEmpty && this->_pos.getRow() - maxSteps <= dest.getRow() && !table[dest.getRow()][dest.getCol()];
		}
		
	}
	else if(abs((int)(this->_pos.getRow() - dest.getRow())) == 1 && abs((int)(this->_pos.getCol() - dest.getCol())) == 1) //eating enemy piece in diagonal
	{
		return table[dest.getRow()][dest.getCol()] != nullptr;
		//because the checking about the piece color is happening in the Main checking function 
	}
	//#TODO: check about en passment
	return false;
}