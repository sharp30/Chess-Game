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
	switch (path[0])
	{
	case 'a':
		src.setCol(A);
		break;
	case 'b':
		src.setCol(B);
		break;
	case 'c':
		src.setCol(C);
		break;
	case 'd':
		src.setCol(D);
		break;
	case 'e':
		src.setCol(E);
		break;
	case 'f':
		src.setCol(F);
		break;
	case 'g':
		src.setCol(G);
		break;
	case 'h':
		src.setCol(H);
		break;
	}

	//second element
	src.setRow(((int)path[1] - '0'));


	//third element
	switch (path[2])
	{
	case 'a':
		dest.setCol(A);
		break;
	case 'b':
		dest.setCol(B);
		break;
	case 'c':
		dest.setCol(C);
		break;
	case 'd':
		dest.setCol(D);
		break;
	case 'e':
		dest.setCol(E);
		break;
	case 'f':
		dest.setCol(F);
		break;
	case 'g':
		dest.setCol(G);
		break;
	case 'h':
		dest.setCol(H);
		break;
	}

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