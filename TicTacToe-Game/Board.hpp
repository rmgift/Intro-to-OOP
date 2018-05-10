/*************************************************************************
Author: Ryan Gift
Date: 03/16/17
Description: The Board.hpp file is the Board class declaration file. This
 class contains an enumerated data type for the current state of the game
 as well as the member variable for the board and member functions that
 print the Tic Tac Toe board and place the moves of the players on the
 board. This file should be combined with the Board.cpp file and both
 TicTacToe class files.
*************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

enum Result { x, o, draw, progress};

class Board
{
protected:
	char gameBoardArr[3][3];
	Result stateOfGame;
public:
	Board();
	bool makeMove(int, int, char);
	Result gameState();
	void print();
};

#endif