#include "Game.h"

Game::Game(string initBoard)
{
	this->_charsTable = initBoard;
	this->_isChess = false;
	this->_isMate = false; 
	this->_turn = true;

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		for (int j = 0; j < TABLE_SIZE; j++)
		{
			this->_table[i][j] = nullptr;
		}
	}
}

Game:: ~Game() = default;

void Game::manageGame()
{	
	srand(time_t(NULL));
	system("Start chessGraphics.exe");
	Sleep(1000);

	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}

	char msgToGraphics[1024];
	strcpy_s(msgToGraphics, this->_charsTable.c_str());
	buildGameBoard(msgToGraphics);

	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE


	p.sendMessageToGraphics(msgToGraphics);   // send the board string


	//erase this line- just for debugging!:
	printBoard();


	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	Position src(TABLE_SIZE, TABLE_SIZE);
	Position dest(TABLE_SIZE, TABLE_SIZE);
	int resultMove = 0;
	while (msgFromGraphics != "quit")
	{
		Position::castStrToPos(src, dest, msgFromGraphics);
		resultMove = this->checkMove(src, dest);
		if (resultMove == VALID)
		{
			movePiece(src, dest);
			if (this->_isChess)
			{
				if (this->_isMate)
				{
					resultMove = VALID_CHECKMATE;
				}
				else
				{
					resultMove = VALID_MADE_CHESS;
				}

			}

			this->_turn = !this->_turn; //switch player in backend.
			//until the end of the while loop we shouldn't use the value of turn.
		}
		// should handle the string sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		// YOUR CODE
		strcpy_s(msgToGraphics,std::to_string(resultMove).c_str()); // msgToGraphics should contain the result of the operation

		
		//sends the error code to the graphics
		p.sendMessageToGraphics(msgToGraphics);

		//erase this line- just for debugging!:
		printBoard();

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}

/*
the function will move the piece to it's new position on the board
input: The source position of the piece, the Destination position of the piece
output: none
*/
void Game::movePiece(Position src,Position dest)
{
	bool canOtherTeamMove = true;
	Piece* removed = this->_table[dest.getRow()][dest.getCol()];
	Piece* added = this->_table[src.getRow()][src.getCol()];
	if (removed != nullptr)
	{
		//remove from vector
		this->_teams[!this->_turn].erase(std::find(this->_teams[!this->_turn].begin(), this->_teams[!this->_turn].end(), removed));
		delete removed;
	}
	added->movePosition(dest);
	this->_table[dest.getRow()][dest.getCol()] = added;
	this->_table[src.getRow()][src.getCol()] = nullptr;
	
	if (added != nullptr && added->isValidMove(this->_table,this->_teams[!this->_turn][0]->getPos())) 
		//check if the moving piece threatning the king
	{
		canOtherTeamMove = canMove(); //$$$
		this->_isChess = true;
		this->_isMate = !canOtherTeamMove;
	}
	/*else
	{
		_isPat = !canOtherTeamMove;
	}
	*/

}

/*
This function checks if the object can execute the move --- after all tests!!!
input: The source position of the piece, the Destination position of the piece
output: the movement code that will be sent to the frontend
*/
int Game::checkMove(Position src, Position dest) //const
{
	int movementCode = VALID;

	if (src == dest)
	{
		//src are the same spot as dest
		return SRC_EQUALS_DEST;
	}
	if (this->_table[src.getRow()][src.getCol()] != nullptr)
	{
		if (this->_table[src.getRow()][src.getCol()]->getColor().compare("white") == 0 && this->_turn ||
			this->_table[src.getRow()][src.getCol()]->getColor().compare("black") == 0 && !this->_turn)
		{
			//if white piece in src and it is black's turn or
			// black piece in src and it is white's turn 
			return BAD_PIECE_IN_SRC;
		}
	}
	else
	{
		//src position has nullptr in it
		return BAD_PIECE_IN_SRC;
	}

	if (this->_table[dest.getRow()][dest.getCol()] != nullptr)
	{
		if (this->_table[dest.getRow()][dest.getCol()]->getColor().compare("white") == 0 && !this->_turn ||
			this->_table[dest.getRow()][dest.getCol()]->getColor().compare("black") == 0 && this->_turn)
		{
			//if white piece in dest and it is white's turn or
			// black piece in dest and it is black's turn 
			return BAD_PIECE_IN_DEST;
		}
	}


	if (!this->_table[src.getRow()][src.getCol()]->isValidMove(this->_table, dest))
	{
		return INVALID_PIECE_MOVE;
	}
	//check if the move doesn't leads to chess
	
	Piece* tmp = this->_table[dest.getRow()][dest.getCol()];

	this->_table[dest.getRow()][dest.getCol()] = this->_table[src.getRow()][src.getCol()];
	this->_table[src.getRow()][src.getCol()] = nullptr;
	this->_table[dest.getRow()][dest.getCol()]->movePosition(dest);
	//#TODO vector of pieces according to the checking
	if (this->checkChess())
	{
		movementCode = FUTURE_CHESS_DANGER;
	}

	this->_table[dest.getRow()][dest.getCol()]->movePosition(src);
	this->_table[src.getRow()][src.getCol()] = this->_table[dest.getRow()][dest.getCol()];
	this->_table[dest.getRow()][dest.getCol()] = tmp;

	return movementCode;
}

// COPY TO a new board
//void Game::copyBoard(Piece* [][TABLE_SIZE])
//{
//
//}



/*
This function checks if the action that has recently permofed will cause a chess on the team
Input:None
Output:will a chess be performed :: bool
*/
bool Game::checkChess() const
{
	for (int i = 0; i <this->_teams[!this->_turn].size(); i++)
	{
		if (this->_teams[!this->_turn][i]->isValidMove(this->_table, this->_teams[this->_turn][0]->getPos()))
		{
			return true;
		}
	}
	return false;
}

void Game::checkMate()
{

}

/*
the function will check if any piece of the attacking team can make any movement
input: none
output: if any piece of the team that being attacked can make any movement
*/
bool Game::canMove()// const //TODO:AFTER changing checkMove const add here
{
	//run on all squares on 
	for (int i = 0; i < this->_teams[!this->_turn].size(); i++)
	{
		//run on all squares on table
		for (int row = 0; row < TABLE_SIZE; row++)
		{
			for (int col = 0; col < TABLE_SIZE; col++)
			{
				if (this->checkMove(this->_teams[!this->_turn][i]->getPos(), Position(row, col)))
				{
					return false;
				}
			}
		}
	}
	return true;
}

/*
the function will build the board of the backend
input: the way the board should be built
output: none
*/
void Game::buildGameBoard(char* gameBoardStr)
{
	string color = "";
	Piece* created = nullptr;
	Position pos(TABLE_SIZE, TABLE_SIZE);
	bool colorCond;
	char type = 'a';
	//buildBoard
	for (int i = 0; i < TABLE_SIZE * TABLE_SIZE; i++)
	{
		//std::cout << TABLE_SIZE - (i / TABLE_SIZE) - 1 << "," << i % TABLE_SIZE << std::endl;
		pos.setRow(TABLE_SIZE - (i / TABLE_SIZE) - 1);
		pos.setCol(i % TABLE_SIZE);
		if (gameBoardStr[i] != '#')
		{
			color = gameBoardStr[i] >= 'a' ? "black" : "white";

			type = tolower(gameBoardStr[i]);
			switch (type)
			{
			case 'r':
				created = new Rook(color, pos);
				break;
			case 'p':
				created = new Pawn(color, pos);
				break;
			case 'b':
				created = new Bishop(color, pos);
				break;
			case 'q':
				created = new Queen(color, pos);
				break;
			case 'k':
				created = new King(color, pos);
				break;
			case 'n':
				created = new Knight(color, pos);
				break;
			default:
				break;
			}
			this->_table[pos.getRow()][pos.getCol()] = created;
			colorCond = color._Equal("black");
			if (type == 'k')
			{
				this->_teams[colorCond].insert(this->_teams[colorCond].begin(), created);
			}
			else
			{
				this->_teams[colorCond].push_back(created);
			}
		}
		else
		{
			this->_table[pos.getRow()][pos.getCol()] = nullptr;
		}
	}
}


/*
the function will print the board in the command line
input: none
output: none
*/
void Game::printBoard() const
{
	int i = 0, j = 0;

	std::cout << std::endl;
	for (i = 0; i < TABLE_SIZE; i++)
	{
		std::cout << "-";
		for (j = 0; j < TABLE_SIZE; j++)
		{
			if (this->_table[i][j] != nullptr)
				std::cout << this->_table[i][j]->getType() << "-";
			else
				std::cout << "null" << "-";
		}
		std::cout << std::endl;
	}
}