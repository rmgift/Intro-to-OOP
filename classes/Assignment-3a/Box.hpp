/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: The Box.hpp is the Box class declaration file.
 The class defines the member variables used in Box.cpp
 and defines the member functions used in Box.cpp.
***********************************************************/
#ifndef BOX_HPP
#define BOX_HPP

// Box class declaration
class Box
{
	// private member variables or attributes
	private:
		double height;
		double width;
		double length;
	// public member functions or methods
	public:
		Box();
		Box(double, double, double);
		void setHeight(double);
		void setWidth(double);
		void setLength(double);
		double getVolume();
		double getSurfaceArea();
};
#endif