/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: stdDev.cpp is the function file for solving for
 the standard deviation of two parameters, an array of
 pointers and the size of the array. The function returns
 the standard deviation of the scores from the array.
***********************************************************/
#include "Student.hpp"
#include <cmath>

double stdDev(Student *array[], int size)
{
	// loop to calculate the mean of all scores
	double total = 0;
	double totalMean = 0;
	for (int index = 0; index < size; index++)
	{
		total += array[index]->getScore();
	}
	totalMean = total / size;

	// This for loop does the following two tasks:
	// Subtract the totalMean from each score and square that calculation
	// Then keep a running total of those values for the next calculation
	double num2 = 0;
	double total2 = 0;
	double mean2 = 0;
	for (int j = 0; j < size; j++)
	{
		num2 = pow((array[j]->getScore() - totalMean), 2);
		total2 += num2;
	}
	// calculate the mean again for the running total above
	mean2 = total2 / size;

	// take the square root of mean2 to get your standard deviation
	double standDev;
	return standDev = sqrt(mean2);
}