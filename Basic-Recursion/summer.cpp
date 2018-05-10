/***********************************************************
Author: Ryan Gift
Date: 02/15/2017
Description: This program takes an array of doubles from 
 main then computes and returns the sum of the values using
 a recursive function and a helper function. 
***********************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Function prototypes
double summer(double arr[], int);
double summer(double arr[], int, int);

/***********************************************************
*                     summer function                      *
* This is the recursive function that evaluates that array *
* and returns the sum. The function is passed the array of *
* values, the size and the element position from the       *
* helper function below it.                                *
***********************************************************/
double summer(double arr[], int SIZE, int pos)
{
	if (SIZE == (pos + 1))	// Base case
	{
		return arr[pos];
	}
	if (pos < SIZE)
	{
		return (arr[pos] + (summer(arr, SIZE, pos+1)));
	}
}

// Recursive helper function to start at element 0
/***********************************************************
*                 summer helper function                   *
* This is the helper function for the recursive function.  *
* The function is passed the array and array size from     *
* main and returns both of these parameters and in addition*
* it to passes the element position of 0 to the recursive  *
* function above.                                          *
***********************************************************/
double summer(double arr[], int SIZE)
{
	return summer(arr, SIZE, 0);
}

/*
int main()
{
	//const int size = 1;
	//double array[size] = { 9.2 };
	
	// Below array is equal to 39.7
	const int size = 8;
	double array[size] = { 8.3, 2.7, 6.4, 5.5, 3.1, 4.9, 7.0, 1.8 };

	// Below array is equal to 36.0
	// double array[size] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };

	cout << summer(array, size);

	cin.get();
	return 0;
}*/