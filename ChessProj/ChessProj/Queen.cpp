#include "Queen.h"

//using std::string;

// ----------------------constractor --------------------
Queen::Queen(string color, Position pos) : Piece(color,"Queen",pos)
{
}
Queen::~Queen() = default;
//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
const bool Queen::isValidMove(const Piece* table[][TABLE_SIZE], Position dest)
{
	return true;
}