/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: LineSegment.hpp is the class declaration file.
 This file defines member variables and member functions
 that are used in the LineSegment.cpp file. Some functions
 and variables within this file contain instances from the
 Point.hpp file.
***********************************************************/
#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP
#include "Point.hpp"

// LineSegment class declaration
class LineSegment
{
	// private member variables or attributes
	private:
		Point ptEnd1;
		Point ptEnd2;
	// public member functions or methods
	public:
		LineSegment(Point, Point);
		void setEnd1(Point);
		void setEnd2(Point);
		Point getEnd1();
		Point getEnd2();
		double length();
		double slope();
};
#endif