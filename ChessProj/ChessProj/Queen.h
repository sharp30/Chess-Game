#pragma once
#include <iostream>
#include <string>
#include "Piece.h"


using std::string;
enum directions { UP_RIGHT, UP_LEFT, DOWN_LEFT, DOWN_RIGHT };


class Queen : public Piece
{
public:
	Queen(string color, Position pos);
	~Queen();
	//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
	virtual bool isValidMove( Piece* const table[][TABLE_SIZE], Position dest) const;
};