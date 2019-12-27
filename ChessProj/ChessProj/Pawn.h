#pragma once
#include <iostream>
#include <string>
#include "Piece.h"

using std::string;

class Pawn : public Piece
{
protected:
	bool _isMoved;
public:

	Pawn(string color, Position pos);
	~Pawn();
	virtual void movePosition(Position dest);
	//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
	virtual bool isValidMove(const Piece* const table[][TABLE_SIZE], Position dest) const;
};