#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Position {
protected:
	unsigned int _row;
	unsigned int _col;

public:
	Position(unsigned int row, int col);
	//default distructor
	static void castStrToPos(Position& src, Position& dest, string path);
	const unsigned int getRow();
	const unsigned int const getCol();
	void setRow(unsigned int row);
	void setCol(unsigned int col);
};