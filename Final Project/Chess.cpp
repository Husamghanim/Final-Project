#include "Chess.h"
#include <Windows.h>
#include <stdio.h>

using namespace std;


Chess::Chess()
{
	twoStepPawnPlayer1 = false; // to restrict the player into having only one two-step movement for a pawn. It is used in the 'legalMove' function
	twoStepPawnPlayer2 = false;
	
}
void Chess::setup()  // this function assignes objects to the array of positions. The numbers represent colors.. 1 is black, 2 is white, 3 is space
{
	A[0][0] = Pieces("R1", 1);
	A[0][1] = Pieces("k1", 1);
	A[0][2] = Pieces("B1", 1);
	A[0][3] = Pieces("QN", 1);
	A[0][4] = Pieces("KG", 1);
	A[0][5] = Pieces("B2", 1);
	A[0][6] = Pieces("k2", 1);
	A[0][7] = Pieces("R2", 1);
	A[1][0] = Pieces("P1", 1);
	A[1][1] = Pieces("P2", 1);
	A[1][2] = Pieces("P3", 1);
	A[1][3] = Pieces("P4", 1);
	A[1][4] = Pieces("P5", 1);
	A[1][5] = Pieces("P6", 1);
	A[1][6] = Pieces("P7", 1);
	A[1][7] = Pieces("P8", 1);
	A[7][0] = Pieces("R1", 2);
	A[7][1] = Pieces("k1", 2);
	A[7][2] = Pieces("B1", 2);
	A[7][3] = Pieces("QN", 2);
	A[7][4] = Pieces("KG", 2);
	A[7][5] = Pieces("B2", 2);
	A[7][6] = Pieces("k2", 2);
	A[7][7] = Pieces("R2", 2);
	A[6][0] = Pieces("P1", 2);
	A[6][1] = Pieces("P2", 2);
	A[6][2] = Pieces("P3", 2);
	A[6][3] = Pieces("P4", 2);
	A[6][4] = Pieces("P5", 2);
	A[6][5] = Pieces("P6", 2);
	A[6][6] = Pieces("P7", 2);
	A[6][7] = Pieces("P8", 2);
	for (int i = 0; i < 8; i++)
	{
		A[2][i] = Pieces("  ", 3);
		A[3][i] = Pieces("  ", 3);
		A[4][i] = Pieces("  ", 3);
		A[5][i] = Pieces("  ", 3);
	}
}
void Chess::legalPlayer1(bool& player1, int i, int j) //this function restricts the player into playing only with his/her pieces
{
	
		if (A[i][j].getColor() != 1)
			cout << "Player 1 cannot move this piece. Please choose another piece to move." << endl;
		else
			player1 = false;
	
	
}
void Chess::legalPlayer2(bool& player2, int i, int j)
{
	
		if (A[i][j].getColor() != 2)
			cout << "Player 2 cannot move this piece. Please choose another piece to move." << endl;
		else
			player2 = true;
	
}
void Chess::legalMove(bool& move,int i1, int j1, int i2, int j2) // Checks if the move is legal or not. All the rules of chess are 
{																	// checked in this function
	
		switch (A[i1][j1].getName().at(0))
		{
		case 'R':
			if (abs(i2 - i1) != 0 && abs(j2 - j1) != 0 || A[i1][j1].getColor() == A[i2][j2].getColor())
				cout << "Illegal move for " << A[i1][j1].getName() << "." << endl;
			else
				move = true;
			break;
		case 'k':
			
			if (((abs(i2 - i1) == 2 && abs(j2 - j1) == 1) || (abs(i2 - i1) == 1 && abs(j2 - j1) == 2)) && A[i1][j1].getColor()!=A[i2][j2].getColor())
				move = true;
			else
				cout << "Illegal move for " << A[i1][j1].getName() << "." << endl;
			break;
		case 'B':
			if (abs(i2 - i1) != abs(j2 - j1) || A[i1][j1].getColor() == A[i2][j2].getColor())
				cout << "Illegal move for " << A[i1][j1].getName() << "." << endl;
			else
				move = true;
			break;
		case 'Q':
			if (abs(i2 - i1) == 2 || abs(j2 - j1) > 1 || A[i1][j1].getColor() == A[i2][j2].getColor())
			{
				cout << "Illegal move for " << A[i1][j1].getName() << "." << endl;
			}
			else
			{
				move = true;
			}
			break;
		case 'K':
			if ((abs(i2 - i1) > 1 && abs(i2 - i1) == abs(j2 - j1)) || (abs(j2 - j1) > 1 && abs(i2 - i1) == abs(j2 - j1)) || (abs(i2 - i1) > 1 && abs(j2 - j1) == 0) || (abs(j2 - j1) > 1 && abs(i2 - i1) == 0))
				move = true;
			else
				cout << "Illegal move for " << A[i1][j1].getName() << "." << endl;
			break;
				
		case 'P':
			if ((A[i1][j1].getColor() == A[i2][j2].getColor()) || abs(j2 - j1)>1 || abs(i2 - i1)>2 || (abs(j2 - j1) == 1 && A[i2][j2].getName() == "  ") || (abs(i2 - i1) <= 2 && abs(j2 - j1) == 0 && A[i2][j2].getName() != "  ") || (abs(j2 - j1) == 1 && A[i1][j1].getColor() == A[i2][j2].getColor()))
				cout << "Illegal move for " << A[i1][j1].getName() << "." << endl;
			else if (abs(i2 - i1) == 2 && A[i1][j1].getColor() == 1 && twoStepPawnPlayer2==false )
			{
				twoStepPawnPlayer1 = true;
				move = true;
			}
			else if (abs(i2 - i1) == 2 && A[i1][j1].getColor() == 2 && twoStepPawnPlayer2==false )
			{
				twoStepPawnPlayer2 = true;
				move = true;
			}
			else if (abs(i2 - i1) == 2 && A[i1][j1].getColor() == 1 && twoStepPawnPlayer1 == true)
				cout << "Illegal move for " << A[i1][j1].getName() << "." << endl;
			else if (abs(i2 - i1) == 2 && A[i1][j1].getColor() == 2 && twoStepPawnPlayer2 == true)
				cout << "Illegal move for " << A[i1][j1].getName() << "." << endl;
			else
				move = true;
			break;
		}
	
}

void Chess::emptyPath(bool& move, int i1, int j1, int i2, int j2) // this function checks if the path between the piece picked and the position the player
{																	//wants to place it is empty. The path is checked depending on the way
	bool empty = true;												// the piece moves
	move = false;
	switch (A[i1][j1].getName().at(0))
	{
	case 'R': 
		if (i1 == i2 && A[i1][j1+1].getName()=="  ")
		{
			for (int k = j1; k < j2 - 1; k++)
			{
				if (A[i1][k].getName() != "  ")
					empty = false;
			}
		}
		else if (j1 == j2)
		{
			if (abs(i2 - i1) > 1)
			{

				for (int k = i1; k < i2 - 1; k++)
				{
					if (A[k][j1].getName() != "  ")
						empty = false;
				}
			}
			else if (abs(i2 - i1) <= 1 && A[i2][j2].getName() != "  ")
				empty = false;
		}

		if (empty == false)
		{
			cout << "Illegal move for " << A[i1][j1].getName() << "." << endl;
			move = false;
		}
		else
			move = true;
		break;
	case 'B':
		for (int k = i1; k < i2 - 1; k++)
		{
			if (A[k][k].getName() != "  ")
				empty = false;
		}
		if (empty == false)
		{
			cout << "Illegal move for " << A[i1][j1].getName() << "." << endl;
			move = false;
		}
		else
			move = true;
		break;
	case 'K':
		if (i1 == i2 && j1<j2)
		{
			for (int k = j1; k < j2 - 1; k++)
			{
				if (A[i1][k].getName() != "  ")
					empty = false;
			}
		}
		else if (i1==i2 && j1>j2)
		{
			for (int k = j1; k < j2 + 1; k--)
			{
				if (A[i1][k].getName() != "  ")
					empty = false;
			}
		}
		else if (j1 == j2 && i1 > i2)
		{
			for (int k = i1; k < i2 + 1; k--)
			{
				if (A[i1][k].getName() != "  ")
					empty = false;
			}
		}
		else if (j1 == j2 && i1 < i2)
		{
			for (int k = 1; k < abs(i2-i1); k++)
			{
				if (A[i1 + k][j1].getName() != "  ")
				{
					empty = false;
				}
			}
		}
		else if (abs(i2-i1)==abs(j2-j1) && i1<i2 && j1<j2)
		{
			for (int k = 1; k < abs(i2-i1); k++)
			{
				if (A[i1+k][j1+k].getName() != "  ")
					empty = false;
			}
		}
		else if (abs(i2 - i1) == abs(j2 - j1) && i1 > i2 && j1 > j2)
		{
			for (int k = 1; k < abs(i2 - i1); k++)
			{
				if (A[i1 - k][j1 - k].getName() != "  ")
					empty = false;
			}
		}
		else if (abs(i2 - i1) == abs(j2 - j1) && i1 > i2 && j1 < j2)
		{
			for (int k = 1; k < abs(i2 - i1); k++)
			{
				if (A[i1 - k][j1 + k].getName() != "  ")
					empty = false;
			}
		}
		else if (abs(i2 - i1) == abs(j2 - j1) && i1<i2 && j1>j2)
		{
			for (int k = 1; k < abs(i2 - i1); k++)
			{
				if (A[i1 + k][j1 - k].getName() != "  ")
					empty = false;
			}
		}

		if (empty == false)
		{
			cout << "Illegal move for " << A[i1][j1].getName() << "." << endl;
			move = false;
		}
		else
			move = true;
		break;
	case 'P':
		if (i2 - i1 == 2)
		{
			if (A[i2 - 1][j2].getName() != "  ")
				empty = false;
		}
		if (empty == false)
		{
			cout << "Illegal move for " << A[i1][j1].getName() << "." << endl;
			move = false;
		}
		else
			move = true;
		break;
	
	}
}
void Chess::kill(int i1, int j1, int i2, int j2) //If the player chooses a position occupied by an opponent pience, the opponent piece will be removed from the board
{
	if (A[i1][j1].getColor() != A[i2][j2].getColor() && A[i2][j2].getName() != "  ")
	{
		if (A[i2][j2].getColor() == 1)
			player1dead.push_back(A[i2][j2].getName());
		else
			player2dead.push_back(A[i2][j2].getName());

		A[i2][j2].setName("  ");
	}
}
string Chess::letters(int i,int j) // previously used letters to denote rows but then changed it to numbers.
{									// this function draws numbers on the right side of each row to help the player pick the position of the piece 
	string c;
		switch (i)
		{
		case 1:
			c = "1";
			break;
		case 2:
			c = "2";
			break;
		case 3:
			c = "3";
			break;
		case 4:
			c = "4";
			break;
		case 5:
			c = "5";
			break;
		case 6:
			c = "6";
			break;
		case 7:
			c = "7";
			break;
		case 8:
			c = "8";
			break;
		default:
			c = "";
			break;
		}
	
	return c;
}
void Chess::pieces(int i, int j) //prints the name of the piece in the middle of each box.
{
	
	
		switch (j)
		{
		case 9:
			A[i-1][0].printPiece();
			break;
		case 10:
			A[i-1][1].printPiece();
			break;
		case 11:
			A[i - 1][2].printPiece();
			break;
		case 12:
		    A[i-1][3].printPiece();
			break;
		case 13:
			A[i-1][4].printPiece();
			break;
		case 14:
			A[i-1][5].printPiece();
			break;
		case 15:
			A[i-1][6].printPiece();
			break;
		case 16:
			A[i-1][7].printPiece();
			break;
		default:
			cout << "";
			break;

		}
	
		
	
}

void Chess::move(int i1, int j1, int i2, int j2) //switches objects in the array
{
	Pieces temp = A[i1][j1];
	A[i1][j1] = A[i2][j2];
	A[i2][j2] = temp;
}

void Chess::chessboard() // draws the chessboard with the pieces in thier positions
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (unsigned int i = 0; i < player1dead.size(); i++)  // lists the dead pieces of player 1 on top of the board
	{
		cout << " " << player1dead[i] << " ";
	}

	cout << endl;

	for (int i = 1; i < 9; i++)  //draws the chess board using two different color texts and background 
	{
		
			for (int j = 1; j < 25; j++) // every row on the chessboard consists of three lines of text
			{
				
				
				if ((j==1||j==3||j==5||j==7||j==9||j==11||j==13||j==15||j==17||j==19||j==21||j==23||j==25) && (i==1 ||i==3 ||i==5||i==7)) //for every other box use the same color background
				{
					SetConsoleTextAttribute(h, 31);
					if (j>8 && j <=16) // in the middle of the box put the name of the piece 
					{
						cout << " ";
						pieces(i, j);
						SetConsoleTextAttribute(h, 31);
						cout << " ";
					}
					else
					{
						cout << "    ";
					}

					if (j == 8||j==16||j==24)
					{
						SetConsoleTextAttribute(h, 7);
						if (j == 16)
							cout <<" "<< letters(i,j) << endl;
						else
							cout << endl;
						
					}

				}
				else if ((j == 2 || j == 4 || j == 6 || j == 8 || j == 10 || j == 12 || j == 14 || j == 16 || j == 18 || j == 20 || j == 22 || j == 24 ) && (i == 2 || i == 4 || i == 6 || i == 8))
				{
					SetConsoleTextAttribute(h, 31);
					if (j>8 && j <= 16)
					{
						cout << " ";
						pieces(i, j);
						SetConsoleTextAttribute(h, 31);
						cout << " ";
					}
					else
					{
						cout << "    ";
					}

					if (j == 8 || j == 16 || j == 24)
					{
						SetConsoleTextAttribute(h, 7);
						if (j == 16)
							cout <<" "<< letters(i,j) << endl;
						else
							cout << endl;
					}

				}
				else
				{
					SetConsoleTextAttribute(h, 67);
					if (j>8 && j <=16)
					{
						cout << " ";
						pieces(i, j);
						SetConsoleTextAttribute(h, 67);
						cout << " ";
					}
					else
					{
						cout << "    ";
					}

					if (j == 8 || j == 16 || j == 24)
					{
						SetConsoleTextAttribute(h, 7);
						if (j == 16)
							cout << " "<<letters(i,j) << endl;
						else
							cout << endl;
					}
				}
				
			}

	}
	SetConsoleTextAttribute(h, 7);
	cout << " 01  02  03  04  05  06  07  08" << endl;

	for (unsigned int i = 0; i < player2dead.size(); i++)
	{
		cout << " " << player2dead[i] << " ";
	}
	cout << endl;
}

void Chess::history() // creates a text file and stores the name, color and position of every piece on the board
{
	

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				fout.open("History.txt", ios::out | ios::app);
				if (fout.fail())
				{
					cout << "Problem opening file." << endl;
					exit(0);
				}
				if (A[i][j].getName() != "  ")
				{
					fout << A[i][j].getName() << " " << A[i][j].getColor() << " " << i << " " << j << endl;
					fout.close();
				}
				else
				{
					fout << "77" << " " << A[i][j].getColor() << " " << i << " " << j << endl;
					fout.close();
				}
			}
		}
		fout.open("History.txt", ios::out | ios::app);
		if (fout.fail())
		{
			cout << "Problem opening file." << endl;
			exit(0);
		}
		fout << "00" << " " << 0 << " " << 0 << " " << 0 << endl; // This code will help differentiate between moves when viewing history
		fout.close();

		
}
void Chess::viewHistory() //reads the name, color, and position from a text file and assigns them to the 2D array of objects A 
{
	int count = 0;
	fin.open("History.txt");
	if (fin.fail())
	{
		cout << "Problem reading file." << endl;
		exit(0);
	}

	while (!fin.eof())
	{
		fin >> readName >> readColor >> readI >> readJ;
		if (readName == "00")
		{
			cout << endl;
			chessboard();
		}
		else
		{
			A[readI][readJ].setName(readName);
			A[readI][readJ].setColor(readColor);

		}
	}
	fin.close();

}

void Chess::deleteHistory() // deletes the content of the text file
{
	fout.open("History.txt");
	fout.close();
}