#pragma once
#include <iostream>
#include <string>
#include "Piece.h"

const int TABLE_SIZE = 8;
using std::string;

class Rook
{
	protected:
		bool _isMoved;
	public:
		Rook(string color, string type);
		~Rook();
		virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);


};