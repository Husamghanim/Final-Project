#include "Pieces.h"
#include <Windows.h>
Pieces::Pieces()
{

}
Pieces::Pieces(string name, int c) //each object has a name and a color, including spaces. 
{
	piece = name;
	color = c;
}

void Pieces::printPiece() //prints the name of the piece with its relative color 
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (color == 1)
	{
		SetConsoleTextAttribute(h, 16); // black text and blue background
	}
	else 
	{
		SetConsoleTextAttribute(h, 31); // white text and blue background
	}
	cout << piece;
	
}
int Pieces::getColor()
{
	return color;
}
string Pieces::getName()
{
	return piece;
}
void Pieces::setName(string name)
{
	piece = name;
}
void Pieces::setColor(int hue)
{
	color = hue;
}