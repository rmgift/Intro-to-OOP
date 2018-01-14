/***********************************************************
Author: Ryan Gift
Date: 01/18/2017
Description: This program takes three parameters assigned in
 the main function and calls the smallSort function. This
 function then evaluates and reassigns the integers lowest
 to highest based on their values. It then returns to the
 main function and displays the reordered integers.
***********************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Function prototype
void smallSort(int &numOne, int &numTwo, int &numThree);

/*************************************************
*                    main                        *
*************************************************/
int main()
{
	int a = 14;		// Parameter value
	int b = -90;	// Parameter value
	int c = 2;		// Parameter value

	// Call to function smallSort based on above integers
	smallSort(a, b, c);

	// Display output of integers reordered
	cout << a << ", " << b << ", " << c << endl;

	return 0;
}


/*************************************************
*                 smallSort                      *
* This functions parameters are reference        *
* variables. The integers from the main function *
* are evaluated based on this functions if       *
* statements and restored lowest to highest.     * 
*************************************************/
void smallSort(int &numOne, int &numTwo, int &numThree)
{
	// Evaluates 1st grouping of integers
	if (numOne > numTwo)		
	{
		int temp = numOne;		// If true the numbers are reassigned b, a
		numOne = numTwo;		// If false the are left as a, b
		numTwo = temp;			// This pattern continues through the next two groups
	}
	// Evaluates 2nd grouping of integers
	if (numTwo > numThree)
	{
		int temp = numTwo;
		numTwo = numThree;
		numThree = temp;
	}
	// Evaluates 3rd grouping of integers
	if (numOne > numTwo)
	{
		int temp = numOne;
		numOne = numTwo;
		numTwo = temp;
	}
}