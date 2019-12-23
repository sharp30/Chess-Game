#include "Queen.h"


Queen(string color);
~Queen();
//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
virtual const bool isValidMove(const Piece* table[][TABLE_SIZE], Position dest);