/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: This function takes as parameters the addresses
 of three int variables and sorts the ints at those
 addresses in to ascending order.
***********************************************************/
#include <iostream>
using namespace std;

// Function prototype
void smallSort2(int*, int*, int*);
/*********************************************************
*                       smallSort2                       *
* This functions is passed variables from main via the   *
* (&) address operator. The function accepts these       *
* variables as pointer variables to point to the values  *
* at those addresses. The function then evaluates values *
* of the variables and orders them lowest to highest.    *
*********************************************************/
void smallSort2(int *numOne, int *numTwo, int *numThree)
{
	// Evaluates 1st grouping of integers
	if (*numOne > *numTwo)
	{
		int temp = *numOne;		// If true the numbers are reassigned b, a
		*numOne = *numTwo;		// If false the are left as a, b
		*numTwo = temp;			// This pattern continues through the next two groups
	}
	// Evaluates 2nd grouping of integers
	if (*numTwo > *numThree)
	{
		int temp = *numTwo;
		*numTwo = *numThree;
		*numThree = temp;
	}
	// Evaluates 3rd grouping of integers
	if (*numOne > *numTwo)
	{
		int temp = *numOne;
		*numOne = *numTwo;
		*numTwo = temp;
	}
}


int main() 
{
	int a = 14;		// Parameter value
	int b = -90;	// Parameter value
	int c = 2;		// Parameter value

	// Call to function smallSort based on above integers
	smallSort2(&a, &b, &c);

	// Display output of integers reordered
	cout << a << ", " << b << ", " << c << endl;

	cin.get();
	
	return 0;
}
