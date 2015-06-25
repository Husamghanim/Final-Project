#ifndef CHESS_H
#define CHESS_H
#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include "Pieces.h"

using namespace std;


class Chess
{
public:
	
	Chess();
	Pieces A[8][8];
	void chessboard();
	string letters(int, int);
	void pieces(int, int);
	void move(int, int, int, int);
	void legalPlayer1(bool&, int, int);
	void legalPlayer2(bool&, int, int);
	void legalMove(bool&, int, int, int , int);
	void emptyPath(bool&, int,int,int,int);
	void kill(int, int, int, int);
	void setup();
	void history();
	void viewHistory();
	void deleteHistory();
private:
	bool twoStepPawnPlayer1;
	bool twoStepPawnPlayer2;
	vector<string> player1dead;
	vector<string> player2dead;
	ofstream fout;
	ifstream fin;
	string readName;
	int readColor;
	int readI;
	int readJ;
	

};

#endif