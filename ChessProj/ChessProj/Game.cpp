#include "Game.h"

Game::Game(string initBoard)
{
	this->_charsTable = initBoard;
	this->_isChess = false;
	this->_isMate = false; 
	this->_turn = false;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
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
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		// YOUR CODE
		strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation


		//////--Example of a Code msg building
		//////--structure - 'char- code number', 'null'
		////int r = rand() % 10; // just for debugging......
		////msgToGraphics[0] = (char)(1 + '0');
		////msgToGraphics[1] = 0;//null
		

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

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
	if (added->isValidMove(this->_table,this->_teams[!this->_turn][0]->getPos()))
	{
		this->_isChess = true;
		checkMate;
	}
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
	//#TODO change inner destination
	if (this->checkChess())
	{
		movementCode = FUTURE_CHESS_DANGER;
	}
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