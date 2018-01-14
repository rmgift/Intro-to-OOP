/***********************************************************
Author: Ryan Gift
Date: 01/18/2017
Description: This program asks the user to tell us how many 
 integers they would like to input. Then based on that 
 grouping of integers the program determines the max and
 min numbers.
***********************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int maxNum,			// maximum number input
		minNum,			// minimum number input
		finalCount;		// defines integers to enter and enables user controlled loop

	// Get number of integers user will enter
	cout << "How many integers would you like to enter?" << endl;
	cin >> finalCount;

	// Get each integer from user
	cout << "Please enter " << finalCount << " integers." << endl;
	for (int loopCount = 1; loopCount <= finalCount; loopCount++)
	{
		int numInput;	// numInput is defined for user input
		cin >> numInput;

		// set the first value input equal to both min and max
		if (loopCount == 1)
		{
			minNum = numInput;
			maxNum = numInput;
		}
		// after the first value is set, compare every input after to min and max 
		else
		{
			// if input is greater than current value, assign it max
			if (numInput > maxNum)
			{
				maxNum = numInput;
			}
			// if input is less than current value, assign it min
			else if (numInput < minNum)
			{
				minNum = numInput;
			}
		}
	}
	
	cout << "min: " << minNum << endl;		// This line displays the min value
	cout << "max: " << maxNum << endl;		// This line displays the max value

	return 0;
}