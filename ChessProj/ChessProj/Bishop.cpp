#include "Bishop.h"

Bishop::Bishop(string color, Position pos) : Piece(color, "Bishop", pos) 
{
}
Bishop::~Bishop() = default;
const bool Bishop::isValidMove(const Piece * table[][TABLE_SIZE], Position dest)
{
	return true; // need to be done
}
//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
 const bool isValidMove(const Piece* table[][TABLE_SIZE], Position dest);
