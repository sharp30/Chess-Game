#include "Position.h"


Position::Position(unsigned int row, int col)
{
	this->setCol(col);
	this->setRow(row);
}

Position::Position(Position& pos)
{
	this->setCol(pos.getCol());
	this->setRow(pos.getRow());
}


/*
function will cast a string with 4 elements to source and destination positions
input: src to change, dest to change, a string that represents the path
output: none
*/
void Position::castStrToPos(Position& src, Position& dest, string path)
{	
	//Example of a string- "e2e4"

	//first element
	src.setCol(((int)path[0] - 'a'));

	//second element
	src.setRow(((int)path[1] - '0'));

	//third element
	dest.setCol(((int)path[2] - 'a'));

	//fourth element
	dest.setRow(((int)path[3] - '0'));
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

//main to check class Position
/*
void main()
{
	Position src(0, 0);
	Position dest(0, 0);


	Position::castStrToPos(src, dest, "e2e4");

	system("pause");


}
*/