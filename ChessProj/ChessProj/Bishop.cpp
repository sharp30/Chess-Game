#include "Bishop.h"

Bishop::Bishop(string color, Position pos) : Piece(color, "Bishop", pos) 
{
}
Bishop::~Bishop() = default;
const bool Bishop::isValidMove(const Piece * table[][TABLE_SIZE], Position dest)
{
	//check is dest is diagonal to the current position
	if (abs((double)(dest.getCol() - this->_pos.getCol()) / (dest.getRow() - this->_pos.getRow())) != 1)
	{
		return false;
	}

	Position comp(dest);
}
//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
