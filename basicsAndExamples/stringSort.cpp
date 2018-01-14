/***********************************************************
Author: Ryan Gift
Date: 02/08/2017
Description: This function takes as parameters an array of
 strings and the size of the array. It then sorts this array
 alphabetically, case-insensitive, using the selection sort
 algorithm.
***********************************************************/
#include <iostream>
#include <string>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Function prototype
void stringSort(string array[], int size);
void strComp(string, int, int, string arr[], int newS);

/************************************************************
*                       selectionSort                       *
* This function is passed an array of strings and the size  *
* of the array. It then sorts the strings in the array by   *
* looping through the array and making a call to the        *
* strComp function that sorts each element case-insensitive.*
*************************************************************/
void stringSort(string array[], int size)
{
	int startScan;		// startScan holds subscript of array element to smallest value
	int minIndex;		// minIndex is set to subscript of startScan before each pass,
						// if minValue finds lower number minIndex gets the numbers subscript
	
	string minValue;	// minValue gets set to value currently in startScan position on each pass

	// below starts the selection sort function
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];

		// below is the function call to sort the array element case-insensitive
		strComp(minValue, startScan, minIndex, array, size);
	}
}

/************************************************************
*                          strComp                          *
* This function is passed a string, three integers and the  *
* array of strings from the selectionsort function. It then *
* uses these values to evaluate the current array element   *
* against all of the other elements to find the smallest    *
* value case-insensitive.                                   *
*************************************************************/
void strComp(string s1, int num1, int num2, string arr[], int newS)
{
	for (int index = num1 + 1; index < newS; index++)
	{
		// current array element set to all uppercase
		string temp = arr[index];
		for (int i = 0; i < temp.length(); i++)
			temp[i] = toupper(temp[i]);

		// current element from startScan set to all uppercase
		string temp2 = s1;
		for (int r = 0; r < temp2.length(); r++)
			temp2[r] = toupper(temp2[r]);

		// compare array element value to startScan value, all uppercase
		if (temp < temp2)
		{
			s1 = arr[index];
			num2 = index;
		}
	}
	arr[num2] = arr[num1];	// old position in startScan swaps to new position
	arr[num1] = s1;			// new value gets new lhs position
}

/******************************************************************
int main()
{
	const int SIZE = 8;
	string name[SIZE] = { "Zebra", "alligator", "Giraffe", "moose", "bear", "Beach", "PAROTt", "ZEppelin" };
	
	string newName[SIZE];
	stringSort(name, SIZE);
	
	cout << "Back in main: " << endl;
	for (int index = 0; index < SIZE; index++)
		cout << name[index] << " ";

	cin.get();
	return 0;
}
******************************************************************/