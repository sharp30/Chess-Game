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


const string Piece::getType()
{
	return this->_type;
}

const string Piece::getColor()
{
	return this->_color;
}
