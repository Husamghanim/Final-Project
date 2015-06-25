#ifndef PIECES_H
#define PIECES_H
#include <iostream>
#include <string>

using namespace std;
class Pieces
{
public:
	Pieces();
	Pieces(string, int);
	void printPiece();
	int getColor();
	string getName();
	void setName(string);
	void setColor(int);
private:
	string piece;
	int color;

	
};

#endif
