#include "Position.h"


Position::Position(unsigned int row, int col)
{
	this->setCol(col);
	this->setRow(row);
}

Position::Position(const Position& pos)
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

unsigned int Position::getRow() const
{
	return this->_row;
}

unsigned int Position::getCol() const
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

/*
the function will check if a position is around another position (like the king's rules of movment):
EXAMPLE:
1  2  3
4  -  5
6  7  8
# all of the numbers are around the '-' signs
*/
bool Position::isAround(Position p) const
{
	bool isAround = false;
	if ((this->_row + 1 == p._row && this->_col == p._col) || (this->_row - 1 == p._row && this->_col == p._col))
		isAround = true; // moving directions are 2 or 7 (in the example at the description)
	else if ((this->_col + 1 == p._col && this->_row == p._row) || (this->_col - 1 == p._col && this->_row == p._row))
		isAround = true; // moving directions are 4 or 5 (in the example at the description) 
	else if ((this->_col - 1 == p._col && this->_row - 1 == p._row) || (this->_col + 1 == p._col && this->_row + 1 == p._row))
		isAround = true; // moving directions are 3 or 6 (in the example at the description)
	else if ((this->_col - 1 == p._col && this->_row + 1 == p._row) || (this->_col + 1 == p._col && this->_row - 1 == p._row))
		isAround = true; // moving directions are 1 or 8 (in the example at the description)
	
	return isAround;
}


bool Position::operator == (Position other) const
{
	return this->_row == other._row && this->_col == other._col;
}


bool Position::operator != (Position other) const
{
	return !(*this == other);
}

// operator will substract position other from this position
// #WARNING- might lead to negative position values which are not exist on the game board, use carefully 
void Position::operator -= (const Position other)
{
	this->_row -= other._row;
	this->_col -= other._col;
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