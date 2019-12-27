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
input: the path of the piece movement (4 chars - "e2e4" for example)
output: none
*/
void Game::movePiece(string path)
{
	
}

/*
This function checks if the object can execute the move --- after all tests!!!
input: the path of the piece movement
output: none
*/
bool Game::checkMove(Position src, Position dest) const
{
	bool isValid = true;

	if (!this->_table[src.getRow()][src.getCol()]->isValidMove(this->_table, dest))
	{
		isValid = false;
	}
	//else if ()

	return isValid;
}

void Game::checkChess()
{
}

void Game::checkMate()
{
}