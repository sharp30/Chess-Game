#pragma once
#include <iostream>
#include <string>
#include "Piece.h"

using std::string;

class Queen : public Piece
{
public:

	Queen(string color);
	~Queen();
	//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
	virtual const bool isValidMove(const Piece* table[][TABLE_SIZE], Position dest);


};