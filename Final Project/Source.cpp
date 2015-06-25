#include <iostream>
#include <windows.h>  
#include<stdio.h>
#include "Chess.h"
#include <conio.h>
#include <cstdlib>


using namespace std;    
int main()
{

	
	bool player1;
	bool move;
	char exit = 'n';
	char history;
	int x1,y1,x2,y2;

	cout << "                               INSTRUCTIONS" << endl;
	cout << "To enter the position of the piece you want to move, first enter the number of" << endl;
	cout << "the row, press 'Enter' then enter the number of the column and press 'Enter'"<< endl;
	cout << "again." << endl;
	
	Chess c;  
	c.setup(); //set up the board
	c.chessboard(); //view the board
	
	while (exit == 'n')  //player1 is always black and always starts first
	{
		player1 = true;
		move = false;
		while (player1 != false)
		{
			cout << "Player 1: enter the row and column of the piece you want to move ";
			cin >> x1 >> y1;
			c.legalPlayer1(player1, x1 - 1, y1 - 1);
		}
		
		while (move != true)
		{
			cout << "Player1: enter the row and column of the position you want to move to";
			cin >> x2 >> y2;
			c.legalMove(move, x1-1, y1-1, x2-1, y2-1);
			
			if (move == true)
			{
				c.emptyPath(move, x1 - 1, y1 - 1, x2 - 1, y2 - 1);
			}
			if (move == true)
			{
				c.kill(x1 - 1, y1 - 1, x2 - 1, y2 - 1);
			}
			
		}
		
		system("CLS");
		c.move(x1-1, y1-1, x2-1, y2-1); 
		c.chessboard();
		
		while (player1 != true)
		{
			cout << "Player 2: enter the row and column of the piece you want to move ";
			cin >> x1 >> y1;
			c.legalPlayer2(player1, x1 - 1, y1 - 1);
		}
		move = false;
		while (move !=true)
		{
			cout << "Player2: enter the row and column of the position you want to move to";
			cin >> x2 >> y2;
			c.legalMove(move, x1-1, y1-1, x2-1, y2-1);
			if (move == true)
			{
				c.emptyPath(move, x1 - 1, y1 - 1, x2 - 1, y2 - 1);
			}
			if (move == true)
			{
				c.kill(x1 - 1, y1 - 1, x2 - 1, y2 - 1);
			}
		}
		system("CLS");
		c.move(x1-1, y1-1, x2-1, y2-1);
		c.chessboard();
		c.history();

		cout << "Exit Game? y/n ";
		cin >> exit;
		if (exit == 'y')
		{
			cout << "Would you like to view history? y/n ";
			cin >> history;
			if (history == 'y')
			{
				c.viewHistory();
			}
		}
	}
	
	c.deleteHistory(); 
	

	return 0;
}