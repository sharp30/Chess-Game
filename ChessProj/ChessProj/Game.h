#pragma once

#include "Piece.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "King.h"
#include "Pipe.h"
#include <iostream>
#include <thread>
#include <vector>
#include <string>

using std::vector;
using std::string;
class Game
{
protected:
	string charsTable;
	Piece* table[TABLE_SIZE][TABLE_SIZE];

	
	bool turn; //0- white, 1- blue //maybe using enums???
	bool isChess;
	bool isMate;
	vector<Piece*> white;
	vector<Piece*> black;
	
	void movePiece(string path); // path- the string from the frontend (example - "e2e4")
	bool checkMove(string path) const; // path- the string from the frontend (example - "e2e4")  
	//void movePiece(Position src, Position dest);
	//void checkMove(Position src, Position dest);
	void checkChess();
	void checkMate();

public:
	Game(string initBoard);
	~Game();
	void manageGame();
};
