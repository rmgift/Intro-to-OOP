/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: LineSegment.cpp is the function implementation
 file for LineSegment.hpp. The functions in this file:
 initialize points for the endpoints, sets variable values
 based on Point object, gets variable values based on Point
 object, and returns 1 value based on Point object and
 calculates a return value for slope. This file should be
 combined with Point.hpp, Point.cpp, LineSegment.hpp and
 another .cpp file containing main.
***********************************************************/
#include "LineSegment.hpp"

// Member function implementation section to LineSegment

/*********************************************************
*                LineSegment::LineSegment                *
* This is the constructor. It initializes the point1 and *
* point2 class member variables.                         *
*********************************************************/
LineSegment::LineSegment(Point pt1, Point pt2)
{
	setEnd1(pt1);
	setEnd2(pt2);
}

/*********************************************************
*                  LineSegment::setEnd1                  *
* This function assigns the values passed to point1      *
* before calculating length and slope.                   *
*********************************************************/
void LineSegment::setEnd1(Point pt1)
{
	ptEnd1 = pt1;
}

/*********************************************************
*                  LineSegment::setEnd2                  *
* This function assigns the values passed to point2      *
* before calculating length and slope.                   *
*********************************************************/
void LineSegment::setEnd2(Point pt2)
{
	ptEnd2 = pt2;
}

/*********************************************************
*                 LineSegment::getEnd1                   *
* This function retrieves and returns value for point1.  *
*********************************************************/
Point LineSegment::getEnd1()
{
	return ptEnd1;
}

/*********************************************************
*                 LineSegment::getEnd2                   *
* This function retrives and returns value for point2.   *
*********************************************************/
Point LineSegment::getEnd2()
{
	return ptEnd2;
}

/*********************************************************
*                 LineSegment::length                    *
* This function returns the length of the line by using  *
* the distanceTo method from the Point Object.           *
*********************************************************/
double LineSegment::length()
{
	return ptEnd1.distanceTo(ptEnd2);
}

/*********************************************************
*                  LineSegment::slope                    *
* The slope of a line comes from the equation y = mx + b *
* where slope is m. From algebra we can state that for   *
* two points, m = (y2 - y1) / (x2 - x1). This function   *
* retrieves our set values and returns the slope.        * 
*********************************************************/
double LineSegment::slope()
{
	return (ptEnd2.getYCoord() - ptEnd1.getYCoord()) / (ptEnd2.getXCoord() - ptEnd1.getXCoord());
}