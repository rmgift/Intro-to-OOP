/***********************************************************
Author: Ryan Gift
Date: 02/08/2017
Description: boxSort.cpp is a function that takes parameters
 of a Box class array and the size of the array. It the 
 uses the bubble sort algorithm to then sort the volume of
 each box in the array from greatest volume to least volume.
 This file should be combined into a project with Box.hpp 
 Box.cpp and another .cpp file containing main.
***********************************************************/
#include "Box.hpp"

/**********************************************************
*                        boxSort                          *
* This function takes parameters of a Box class array and *
* the size of the array. It then gets the volume for each *
* box and sorts them greatest volume to least volume      *
* using the bubble sort algorithm.                        *
**********************************************************/
void boxSort(Box array[], int size)
{
	Box temp; // temp object to make swaps
	bool madeAswap; // flag to indicate a swap was made

	do
	{
		// sets a flag variable to false
		madeAswap = false;									
		for (int count = 0; count < (size - 1); count++)
		{
			array[count].getVolume();
			// inner loop swaps two values
			if (array[count].getVolume() < array[count + 1].getVolume())	
			{																
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				// sets flag variable to true
				madeAswap = true;
			}
		}

	} while (madeAswap);
}