#include "Knight.h"
#include <cmath>
// --------------- constractor ---------------------------------
Knight::Knight(string color, Position pos):Piece(color,"Knight",pos)
{
}
//-------------- distractor -----------------------------------
Knight::~Knight() = default;

/*
This function checks if the object can execute the move --- according to Knight's moving rules 
Input:table -> the board of the game :: Piece* [][TABLE_SIZE]
	  dest -> the destination to move to :: Position
Output:Is the move valid? :: bool
*/
bool Knight::isValidMove(const Piece* const table[][TABLE_SIZE], Position dest) const
{
	int disRow = abs((int)(this->_pos.getRow() - dest.getRow()));
	int disCol = abs((int)(this->_pos.getCol() - dest.getCol()));
	return disRow > 0 && disCol > 0 && (disRow + disCol) == 3;
 }