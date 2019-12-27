#include "King.h"
#include <cmath>

//constractor of King
King::King(string color, Position pos) :Piece(color, "King", pos)
{
	_isMoved = false;
}
King::~King() = default;


/*
This function checks if the object can execute the move --- according to King's moving rules only!!!
Input:table -> the board of the game ::Piece*[][TABLE_SIZE]
	  dest -> the destination to move to :: Position
Output:Is the move valid? ::bool
*/
const bool King::isValidMove(const Piece * table[][TABLE_SIZE], Position dest)
{
	bool isValid = true;

	if (!this->_pos.isAround(dest))
	{
		isValid = false;
	}

	return isValid;
}

/*
This function moves the piece from his previous location and changes the _isMoved value
Input:dest -> The new position of the piece
Output:None
*/
void King::movePosition(Position dest)
{
	this->_pos = dest;
	this->_isMoved = true;
}