/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: Point.cpp is the function implementation file
 for Point.hpp. The functions in this file: initialize
 member variables, initialize the variables to 0.0, set the
 variables to the values passed, get the values passed and
 then calculate the distance between the two points based
 on a constant reference to one of the points. This file
 should be combined with Point.hpp and another .cpp file
 containing main.
***********************************************************/
#include "Point.hpp"
#include <cmath>

// Member function implementation section to Point

/*********************************************************
*                      Point::Point                      *
* This is the constructor. It initializes the X and Y    *
* class member variables.                                *
*********************************************************/
Point::Point(double x, double y)
{
	setXCoord(x);
	setYCoord(y);
}

/*********************************************************
*                      Point::Point                      *
* This is the default constructor. It initializes the    *
* member variables to 0.0                                *  
*********************************************************/
Point::Point()
{
	setXCoord(0.0);
	setYCoord(0.0);
}

/*********************************************************
*                    Point::setXCoord                    *
* This function assigns the value passed to X before     *
* calculating distanceTo.                                * 
*********************************************************/
void Point::setXCoord(double x)
{
	X = x;
}

/*********************************************************
*                    Point::setYCoord                    *
* This function assigns the value passed to Y before     *
* calculating distanceTo.                                * 
*********************************************************/
void Point::setYCoord(double y)
{
	Y = y;
}

/*********************************************************
*                    Point::getXCoord                    *
* This function retrieves and returns the value in X.    *
*********************************************************/
double Point::getXCoord() const
{
	return X;
}

/*********************************************************
*                    Point::getYCoord                    *
* This function retrives and returns the value in Y.     *
*********************************************************/
double Point::getYCoord() const
{
	return Y;
}

/*********************************************************
*                   Point::distanceTo                    *
* This function calculates the distance between the two  *
* points, one by a constant reference that was pass as a *
* parameter and the Point that we called the method of.  *
*********************************************************/
double Point::distanceTo(const Point& point2)
{
	double radicand = pow((point2.getXCoord() - X), 2) + pow((point2.getYCoord() - Y), 2);
	return sqrt(radicand);
}