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

/*
EXPLANATION of movement errors:
0- Valid move
1- valid move: made chess on the enemy team
2- invalid move: there is no piece of the attacking team in the src position
3- invalid move: there is a piece of the attacking team in the destination position
4- invalid move: the move will cause chess on the attacking team
5- invalid move: the positions (src or dest) are invalid (not on board)
6- invalid move: invalid movem due to the piece's individual rules of movement
7- invalid move: src and dest are the same position
8- valid move: a checkmate, GAME OVER!
*/
enum movementErrors {VALID, VALID_MADE_CHESS, BAD_PIECE_IN_SRC, BAD_PIECE_IN_DEST, FUTURE_CHESS_DANGER,
	INVALID_INDEXES, INVALID_PIECE_MOVE, SRC_EQUALS_DEST, VALID_CHECKMATE};


class Game
{
protected:
	string _charsTable;
	Piece* _table[TABLE_SIZE][TABLE_SIZE];

	bool _turn; //0- white, 1- black //maybe using enums???
	bool _isChess;
	bool _isMate;
	int _movementCode; // number between 0 - 8, tells the frontend if the move is valid or not
	vector<Piece*> _teams[2];
	
	void movePiece(Position src,Position dest); 
	int checkMove(Position src, Position dest);//const; #TODO : fix this const problem (because of checkChess)

	//bool checkMove(string path) const; // path- the string from the frontend (example - "e2e4")  
	//void movePiece(Position src, Position dest);

	//void copyBoard(Piece* [][TABLE_SIZE]);
	bool checkChess() const;
	void checkMate();

public:
	Game(string initBoard);
	~Game();
	void manageGame();
};
