#pragma once
#include <iostream>
#include <string>
#include "Piece.h"

using std::string;

class Bishop : public Piece
{
protected:
	bool _isMoved;
public:

	Bishop(string color, Position pos);
	~Bishop();
	//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
	virtual const bool isValidMove(const Piece* table[][TABLE_SIZE], Position dest);
};