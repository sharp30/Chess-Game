#pragma once
#include <iostream>
#include <string>
#include "Piece.h"

using std::string;

class Bishop : public Piece
{
public:
	Bishop(string color, Position pos);
	~Bishop();
	//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
	virtual bool isValidMove(const Piece* const table[][TABLE_SIZE], Position dest) const;
};