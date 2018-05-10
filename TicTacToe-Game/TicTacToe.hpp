/*************************************************************************
Author: Ryan Gift
Date: 03/16/17
Description: The TicTacTop.hpp file is the TicTacToe class declaration
 file. This class contains protected member variables, one including an
 instance of the Board class, and member functions that allow the user
 to play a game of Tic Tac Toe. This file should be combined with the
 TicTacToe.cpp file and both Board class files.
*************************************************************************/
#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include "Board.hpp"

class TicTacToe
{
protected:
	char player1;
	char player2;
	char currentPlayer;
	Board currentBoard;
public:
	TicTacToe(char);
	void play();
};

#endif