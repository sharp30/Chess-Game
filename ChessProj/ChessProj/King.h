#pragma once
#include <iostream>
#include <string>
#include "Piece.h"

using std::string;

class King : public Piece
{
protected:
	bool _isMoved;
public:

	King(string color, Position pos);
	~King();
	//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
	virtual void movePosition(Position dest);
	virtual bool isValidMove(const Piece* const table[][TABLE_SIZE], Position dest) const;
};
