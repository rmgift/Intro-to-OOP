/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: Student.cpp is the function implementation file
 for Student.hpp. The functions in this file: initialize
 member variables and get values. This file should be
 combined with Student.hpp, stdDev.cpp, and another file
 containing main.
***********************************************************/
#include "Student.hpp"

/******************************************************
*                  Student::Student                   *
* This is the constructor. It initializes the name    *
* and score member variables.                         *
******************************************************/
Student::Student(string n, double s)
{
	setName(n);
	setScore(s);
}

/******************************************************
*                  Student::setName                   *
* It initializes the name for the Student Object      *
******************************************************/
void Student::setName(string n)
{
	name = n;
}

/******************************************************
*                  Student::setScore                  *
* It initializes the score for the Student Object     *
******************************************************/
void Student::setScore(double s)
{
	score = s;
}

/******************************************************
*                  Student::getName                   *
* This function retrieves and returns the value for   *
* the variable name.                                  * 
******************************************************/
string Student::getName()
{
	return name;
}

/******************************************************
*                  Student::getScore                  *
* This function retrieves and returns the value for   *
* the variable score.                                 *
******************************************************/
double Student::getScore()
{
	return score;
}