#include "Bishop.h"

Bishop::Bishop(string color, Position pos) : Piece(color, "Bishop", pos) 
{
}

Bishop::~Bishop() = default;
/*
This function checks if the object can execute the move --- according to Bishop moving rules only!!!
Input:table -> the board of the game ::Piece*[][TABLE_SIZE]
	  dest -> the destination to move to :: Position
Output:Is the move valid? ::bool
*/
bool Bishop::isValidMove( Piece* const table[][TABLE_SIZE], Position dest) const
{
	//check is dest is diagonal to the current position
	double y = (signed)dest.getCol() - (signed)this->_pos.getCol();
	double x = (signed)dest.getRow() - (signed)this->_pos.getRow();
	double m = abs((double)(y / x));
	if (this->_pos.getRow() == dest.getRow() || m != 1.0)
	{
		return false;
	}
	bool rowBigger = dest.getRow() > this->_pos.getRow();
	bool colBigger = dest.getCol() > this->_pos.getCol();

	Position comp(dest);

	while (this->_pos != comp)
	{
		if (table[comp.getRow()][comp.getCol()] != nullptr && comp != dest)
		{
			return false;
		}
		comp.setRow(comp.getRow() + (rowBigger ? -1 : 1));
		comp.setCol(comp.getCol() + (colBigger ? -1 : 1));
	}
	return true;
}
//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
