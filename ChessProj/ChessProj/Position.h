#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

enum StrToPos {A, B, C, D, E, F, G, H};

class Position {
protected:
	unsigned int _row;
	unsigned int _col;

public:
	Position(unsigned int row, int col);
	Position(Position& pos); //copy c'tor

	static void castStrToPos(Position& src, Position& dest, string path);
	const unsigned int getRow();
	const unsigned int const getCol();
	void setRow(unsigned int row);
	void setCol(unsigned int col);
	bool operator ==(Position other);
	bool operator !=(Position other);

};