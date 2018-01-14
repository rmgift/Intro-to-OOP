/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: Point.hpp is the Point class declaration file.
 This file defines member variables and member functions
 used in the Point.cpp file. Member variables and functions
 from this class have instances in the LineSegment class.
***********************************************************/
#ifndef POINT_HPP
#define POINT_HPP

// Point class declaration
class Point
{
	// private member variables or attributes
	private:
		double X;
		double Y;
	// public member functions or methods
	public:
		Point(double, double);
		Point();
		void setXCoord(double);
		void setYCoord(double);
		double getXCoord() const;
		double getYCoord() const;
		double distanceTo(const Point&);
};
#endif