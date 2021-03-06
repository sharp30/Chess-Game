#include "Queen.h"

//using std::string;

// ----------------------constractor --------------------
Queen::Queen(string color, Position pos) : Piece(color,"Queen",pos){}

// ----------------------distractor --------------------
Queen::~Queen() = default;

//virtual void buildMoveOptions(const Piece*  board[][TABLE_SIZE]);

/*
This function checks if the object can execute the move --- according to Queen's moving rules + if the path to dest is empty
Input:table -> the board of the game :: Piece* [][TABLE_SIZE]
	  dest -> the destination to move to :: Position
Output:Is the move valid? :: bool
*/
bool Queen::isValidMove(Piece* const table[][TABLE_SIZE], Position dest) const
{
	bool isValid = true;
	Position comp(dest);

	if (this->_pos.getCol() == dest.getCol() && this->_pos.getRow() == dest.getRow()) // destination is the current position 
	{
		isValid = false;
	}
	else if (abs((int)(this->_pos.getRow() - dest.getRow())) == abs((int)(this->_pos.getCol() - dest.getCol()))) // moving in diagonal
	{
		if (this->_pos.getRow() < dest.getRow()) // optional directions- UP_RIGHT / UP_LEFT
		{
			if (this->_pos.getCol() < dest.getCol()) // direction - UP_RIGHT
			{
				while (this->_pos != comp && isValid)
				{
					if (comp != dest && table[comp.getRow()][comp.getCol()] != nullptr)
					{
						isValid = false;
					}
					else
					{
						comp.setRow(comp.getRow() - 1);
						comp.setCol(comp.getCol() - 1);
					}
				}
			}
			else // direction - UP_LEFT
			{
				while (this->_pos != comp && isValid)
				{
					if (comp != dest && table[comp.getRow()][comp.getCol()] != nullptr) // not empty
					{
						isValid = false;
					}
					else
					{
						comp.setRow(comp.getRow() - 1);
						comp.setCol(comp.getCol() + 1);
					}
				}
			}
		}
		else // optional directions- DOWN_RIGHT / DOWN_LEFT
		{
			if (this->_pos.getCol() > dest.getCol()) // direction - DOWN_LEFT
			{
				while (this->_pos != comp && isValid)
				{
					if (comp != dest && table[comp.getRow()][comp.getCol()] != nullptr) // not empty
					{
						isValid = false;
					}
					else
					{
						comp.setRow(comp.getRow() + 1);
						comp.setCol(comp.getCol() + 1);
					}
				}
			}
			else // direction - DOWN_RIGHT
			{
				while (this->_pos != comp && isValid)
				{
					if (comp != dest && table[comp.getRow()][comp.getCol()] != nullptr) // not empty
					{
						isValid = false;
					}
					else
					{
						comp.setRow(comp.getRow() + 1);
						comp.setCol(comp.getCol() - 1);
					}
				}
			}
		}
	}
	else if (this->_pos.getCol() == dest.getCol()) // moving up or down in the same column
	{
		if (this->_pos.getRow() < dest.getRow()) // piece moving up
		{
			while (this->_pos != comp && isValid)
			{
				if (comp != dest && table[comp.getRow()][comp.getCol()] != nullptr) // not empty
				{
					isValid = false;
				}
				else
				{
					comp.setRow(comp.getRow() - 1);
				}
			}
		}
		else // piece moving down
		{
			while (this->_pos != comp && isValid)
			{
				if (comp != dest && table[comp.getRow()][comp.getCol()] != nullptr) // not empty
				{
					isValid = false;
				}
				else
				{
					comp.setRow(comp.getRow() + 1);
				}
			}
		}
	}
	else if (this->_pos.getRow() == dest.getRow()) // moving right or left in the same row
	{
		if (this->_pos.getCol() < dest.getCol()) // piece moving right
		{
			while (this->_pos != comp && isValid)
			{
				if (comp != dest && table[comp.getRow()][comp.getCol()] != nullptr) // not empty
				{
					isValid = false;
				}
				else
				{
					comp.setCol(comp.getCol() - 1);
				}
			}
		}
		else // piece moving Left
		{
			while (this->_pos != comp && isValid)
			{
				if (comp != dest && table[comp.getRow()][comp.getCol()] != nullptr) // not empty
				{
					isValid = false;
				}
				else
				{
					comp.setCol(comp.getCol() + 1);
				}
			}
		}
	}
	else
	{
		isValid = false;
	}

	return isValid;
}



//check queen
//int main()
//{
//	Position p(0, 0);
//
//	Queen q("White", p);
//
//	return 0;
//}