#include "Piece.h"


//----------------constractors------------------------

Piece::Piece(string color, string type) : _pos(0, 0)
{
	this->_color = color;
	this->_type = type;
}

Piece::Piece(string color, string type, Position pos) : _pos(pos)
{
	this->_color = color;
	this->_type = type;
}

//----------------------------------------------------
/*
This function moves the piece from his previous location
Input:dest -> The new position of the piece
Output:None
*/
void Piece::movePosition(Position dest)
{
	this->_pos = dest;
}

string Piece::getType() const
{
	return this->_type;
}

string Piece::getColor() const
{
	return this->_color;
}

Position Piece::getPos() 
{
	return this->_pos;
}
