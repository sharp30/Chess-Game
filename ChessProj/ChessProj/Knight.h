#pragma once
#include <iostream>
#include <string>
#include "Piece.h"


using std::string;


class Knight : public Piece
{
public:
	Knight(string color, Position pos);
	~Knight();
	//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
	virtual bool isValidMove(const Piece* table[][TABLE_SIZE], Position dest) const;
};