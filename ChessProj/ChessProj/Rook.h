#pragma once
#include <iostream>
#include <string>
#include "Piece.h"

using std::string;

class Rook : public Piece
{
	protected:
		bool _isMoved;                          
	public:

		Rook(string color,Position pos);
		~Rook();
		//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);
		virtual const bool isValidMove(const Piece* table[][TABLE_SIZE], Position dest);


};