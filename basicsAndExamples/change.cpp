/*
* Author: Ryan Gift
* Date: 01/10/17
* Description: Homework assignment 1 - calculating the amount of quarters, dimes,
nickels and pennies from the amount entered less than a dollar
* */
#include <iostream>

int main()
{
	int cents, quarters, dimes, nickels, pennies;

	std::cout << "Please enter an amount in cents less than a dollar. " << std::endl;
	std::cin >> cents;
	
	std::cout << "Your change will be: " << std::endl;	// This is the statement output line
	quarters = cents / 25;								// This line calculates number of quarters
	std::cout << "Q: " << quarters << std::endl;
	dimes = (cents % 25);								// This line caclulates number of dimes
	std::cout << "D: " << dimes / 10 << std::endl;
	nickels = (dimes % 10);								// This line calculates number of nickels
	std::cout << "N: " << nickels / 5 << std::endl;
	pennies = (nickels % 5);							// This line calculates number of pennies
	std::cout << "P: " << pennies / 1 << std::endl;

	return 0;
}