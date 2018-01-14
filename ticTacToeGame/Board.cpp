/*************************************************************************
Author: Ryan Gift
Date: 03/16/17
Description: The Board.cpp file is the method implementation file for the
 Board class. The member functions in this file initialize the multi-
 dimensional array for the board, place the player moves on the board,
 determine the current state of the game, and also print the board to the
 screen. This file should be combined with the Board.hpp file and both
 TicTacToe class files.
*************************************************************************/
#include "Board.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*************************************************************************
*                              Board::Board                              *
* This is the default constructor that initializes the 3x3 array to have *
* periods in each location.                                              *
*************************************************************************/
Board::Board()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			gameBoardArr[i][j] = '.';
}

/*************************************************************************
*                            Board::makeMove                             *
* The makeMove method takes as parameters the x and y coordinates of the *
* move that the player would like to place their symbol. It also takes a *
* parameter as to which player is attempting the move. If that location  *
* is unoccupied we record the move and return true. If that location is  *
* already occupied, we do nothing and return false.                      *
*************************************************************************/
bool Board::makeMove(int x, int y, char cp)
{
	// if position is already filled
	if (gameBoardArr[x][y] >= (cp + 23))
	{
		return false;
	}
	// position not occupied
	else
	{
		gameBoardArr[x][y] = (cp + 32);
		return true;
	}
}

/*************************************************************************
*                            Board::gameState                            *
* The gameState method takes no parameter and returns a value indicating *
* one of the four possibilities:  'x' has won, 'o' has won, the game is  *
* still in progress, or the game is a draw.                              *
*************************************************************************/
Result Board::gameState()
{
	// check all rows for win
	for (int i = 0; i < 3; i++)
	{
		if ((gameBoardArr[i][0] == 'x') && 
			(gameBoardArr[i][0] == gameBoardArr[i][1]) && 
			(gameBoardArr[i][1] == gameBoardArr[i][2]))
		{
			return x;
		}
		else if ((gameBoardArr[i][0] == 'o') && 
			(gameBoardArr[i][0] == gameBoardArr[i][1]) && 
			(gameBoardArr[i][1] == gameBoardArr[i][2]))
		{
			return o;
		}
	}

	// check all columns for win
	for (int i = 0; i < 3; i++)
	{
		if ((gameBoardArr[0][i] == 'x') && 
			(gameBoardArr[0][i] == gameBoardArr[1][i]) && 
			(gameBoardArr[1][i] == gameBoardArr[2][i]))
		{
			return x;
		}
		else if ((gameBoardArr[0][i] == 'o') && 
			(gameBoardArr[0][i] == gameBoardArr[1][i]) && 
			(gameBoardArr[1][i] == gameBoardArr[2][i]))
		{
			return o;
		}
	}

	// check diagonal top left to bottom right
	if ((gameBoardArr[0][0] == 'x') && 
		(gameBoardArr[0][0] == gameBoardArr[1][1]) && 
		(gameBoardArr[1][1] == gameBoardArr[2][2]))
		return x;

	if ((gameBoardArr[0][0] == 'o') && 
		(gameBoardArr[0][0] == gameBoardArr[1][1]) && 
		(gameBoardArr[1][1] == gameBoardArr[2][2]))
		return o;

	// check diagonal bottom left to top right
	if ((gameBoardArr[0][2] == 'x') && 
		(gameBoardArr[0][2] == gameBoardArr[1][1]) && 
		(gameBoardArr[1][1] == gameBoardArr[2][0]))
		return x;
	
	if ((gameBoardArr[0][2] == 'o') && 
		(gameBoardArr[0][2] == gameBoardArr[1][1]) && 
		(gameBoardArr[1][1] == gameBoardArr[2][0]))
		return o;

	// no winner found, return
	return progress;
}

/*************************************************************************
*                              Board::print                              *
* The print method simply prints out the current board to the screen.    *
*************************************************************************/
void Board::print()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << gameBoardArr[i][j];
		cout << endl;
	}
}