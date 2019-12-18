#include "Position.h"

Position::Position(unsigned int row, int col)
{
	this->setCol(col);
	this->setRow(row);
}

void Position::castStrToPos(Position& src, Position& dest, string path)
{

}

const unsigned int Position::getRow()
{
	return this->_row;
}

const unsigned int Position::getCol()
{
	return this->_col;
}

void Position::setRow(unsigned int row)
{
	this->_row = row;
}

void Position::setCol(unsigned int col)
{
	this->_col = col;
}
