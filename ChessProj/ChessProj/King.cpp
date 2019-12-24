#include "King.h"

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

