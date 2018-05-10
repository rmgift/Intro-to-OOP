/*************************************************************************
Author: Ryan Gift
Date: 03/16/17
Description: The TicTacToe.cpp file is the method implementation file for
 the TicTacToe class and it also contains the main method. The main method
 asks the user which symbol they would like to be and then proceeds to
 start the game. The methods in this initialize member variables from user
 input, create a Board object, and start the game. This file should be
 combined with the TicTacToe.hpp file and both Board class files.
*************************************************************************/
#include <iostream>
#include "TicTacToe.hpp"
using std::cin;
using std::cout;
using std::endl;

/*************************************************************************
*                          TicTacToe::TicTacToe                          *
* This is the constructor that takes a char parameter that specifies     *
* whether 'x' or 'o' should have the first move.                         *
*************************************************************************/
TicTacToe::TicTacToe(char first)
{
	// set passed player to first
	player1 = first;

	// set first player to current player
	currentPlayer = player1;

	// set player2 to oppositve of player1
	if (player1 == 'X')
		player2 = 'O';
	else
		player2 = 'X';

	// create tictactoe board
	Board currentBoard;

	// start the game
	play();
}

/*************************************************************************
*                            TicTacToe::play                             *
* The play method starts the game. The method continues looping, asking  *
* the correct player for their move and sending it to the board until    *
* someone has won or it's a draw, and then declare what the outcome was. *
* Input validation: If someone tries to take an occupied square, we tell *
* them that square is already occupied and ask for a different move.     *
*************************************************************************/
void TicTacToe::play()
{
	int xCoord, yCoord;
	bool pMove;
	int currentResult;

	for (int i = 0; i < 9; i++)
	{
		pMove = false;
		// while position is not already taken, flag variable
		while (pMove != true)
		{
			// ask current player for their move
			cout << "Player " << currentPlayer << ": please enter your move." << endl;
			cin >> xCoord >> yCoord;

			pMove = currentBoard.makeMove(xCoord, yCoord, currentPlayer);
			// if result is false
			if (pMove == false)
			{
				cout << "That square is already taken." << endl;
				//currentBoard.print();
			}
			// ask player to make move again
		}

		// print currentBoard after move
		currentBoard.print();
		
		// check to see if there is a winner
		currentResult = currentBoard.gameState();

		// if no winner on last loop, set to enum draw
		if ((currentResult == 3) && (i == 8))
		{
			currentResult = 2;
		}

		// switch enum value for statement
		switch (currentResult)
		{
		case x: cout << "X has won." << endl;
			return;
		case o: cout << "O has won." << endl;
			return;
		case draw: cout << "The game is a draw." << endl;
			return;
		}

		// if current player is player1
		if (currentPlayer == player1)
			// current player becomes player2
			currentPlayer = player2;

		// else if current player is player2
		else if (currentPlayer == player2)
			// current player becomes player1
			currentPlayer = player1;
	}
}

/*************************************************************************
*                                  main                                  *
* The main method asks the user which player should go first and starts  *
* the game.                                                              *
*************************************************************************/
int main()
{
	char firstPlay;
	
	cout << "Which player should go first? x or o? ";
	cin >> firstPlay;

	if (firstPlay == 'x' || firstPlay == 'X')
		TicTacToe('X');
	else if (firstPlay == 'o' || firstPlay == 'O')
		TicTacToe('O');
	else
		cout << "valid choice not entered, program quitting." << endl;

	system("pause");
	return 0;
}