#include "King.h"
#include <cmath>

//constractor of Pawn
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



	return isValid;
}