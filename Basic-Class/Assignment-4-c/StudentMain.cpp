/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description:
***********************************************************/
#include <iostream>
#include <string>
#include <cmath>
#include "Student.hpp"
using namespace std;

// Function prototype
double stdDev(Student *array[], int size);


int main()
{
	double standardDeviation;
	// array of student objects created with names and scores
	const int numStudents = 3;
	Student students[numStudents] = { Student("Bob", 77.0), Student("John", 82.0), Student("Ryan", 65.0) };
	// array of pointers to student objects
	Student *ptrStudent[numStudents];
	// iterate array of student objects and assign address to array of pointers
	for (int i = 0; i < numStudents; i++)
	{
		ptrStudent[i] = &students[i];
	}
	// calculate the standard deviation of these students
	standardDeviation = stdDev(ptrStudent, 3);
	// print the calculated value
	cout << "The Standard Deviation is " << standardDeviation << endl;

	cin.get();
	return 0;
}