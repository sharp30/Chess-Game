#pragma once
#include <iostream>
#include <string>
#include "Piece.h"

const int TABLE_SIZE = 8;
using std::string;

class Rook : public Piece
{
	protected:
		bool _isMoved;
	public:

		Rook(string color);
		~Rook();
		//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
		virtual const bool isValidMove(const Piece* table, Position dest);


};