#include "Pawn.h"
#include <cmath>

//constractor of Pawn
Pawn::Pawn(string color, Position pos) :Piece(color,"Pawn",pos)
{
	_isMoved = false;
}
Pawn::~Pawn() = default;


/*
This function checks if the object can execute the move --- according to Pawn moving rules only!!!
Input:table -> the board of the game ::Piece*[][TABLE_SIZE]
	  dest -> the destination to move to :: Position
Output:Is the move valid? ::bool
*/
const bool Pawn::isValidMove(const Piece* table[][TABLE_SIZE], Position dest)
{
	if (dest.getRow() <= this->_pos.getRow())
	{
		return false;
	}
	if (this->_pos.getCol() == dest.getCol())
	{
		int maxSteps = this->_isMoved ? 1: 2;
		return this->_pos.getRow() + maxSteps >= dest.getRow() && !table[dest.getRow()][dest.getCol()];
		//#TODO: add a checking if all the positions in the way to the destination are empty
	}
	else if(abs((int)(this->_pos.getCol() -dest.getCol())) == 1)
	{
		return table[dest.getRow()][dest.getCol()] != nullptr;
		//because the checking about the piece color is happening in the Main checking function 
	}
	//check about en passment
	return false;
}