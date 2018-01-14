/***********************************************************
Author: Ryan Gift
Date: 01/18/2017
Description: This program generates a random number and then
 asks the player to guess that number. It shows statements 
 for guesses too high and too low. Additionally, it tracks 
 the number of guesses it takes for the right answer. 
***********************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int seed,		// Random generator
		num,		// Random number
		guess,		// Player inputed guess
		x;			// Counter and indicator of player guesses

	// Use time function to get a "seed value" for srand
	srand(time(NULL));
	num = rand();

	// Displays our random number to be guessed and asks player to begin guessing
	cout << "Enter the number for the player to guess." << endl;
	cout << num << endl;
	cout << "Enter your guess: " << endl;

	// Loop that tracks the number of guesses and 
	// supplies statements for incorrect guesses
	for (x = 1; x >= 0; x++)
	{
		cin >> guess;

		if (guess < num)			// Evaluates and indicates if guess is too low
		{
			cout << "Too low - try again." << endl;
		}
		else if (guess > num)		// Evaluates and indicates if guess is too high
		{	
			cout << "Too high - try again." << endl;
		}
		else if (guess == num)		// Evaluates guess and number equality
		{
			break;					// Exits loop if guess equals number
		}
	}
	
	// Indicates the number of guesses it took to supply the correct answer
	cout << "You guessed it in " << x << " tries.";

	return 0;
}