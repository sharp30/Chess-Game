#include "Position.h"

Position::Position(unsigned int row, int col)
{
	this->setCol(col);
	this->setRow(row);
}


/*
finish this function- unfinished!!
*/
void Position::castStrToPos(Position& src, Position& dest, string path)
{	
	char ch = path[0];
	
	switch (ch)
	{
	case 'a':
		src.setRow(A);
		break;
	case 'b':
		break;
	case 'c':
		break;
	case 'd':
		break;
	case 'e':
		break;
	case 'f':
		break;
	case 'g':
		break;
	}

	src.setRow(atoi(path.c_str()));
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
