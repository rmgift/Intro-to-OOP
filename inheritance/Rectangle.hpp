/***********************************************************
Author: Ryan Gift
Date: 02/22/2017
Description: The Rectangle.hpp file is the Rectangle base
 class declaration file. The class defines member variables
 used in Rectangle.cpp and defines member functions used in
 Rectangle.cpp. Some of the functions in this file are 
 overridden by calls in the Square.cpp file.
***********************************************************/
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

// Rectangle base class declaration
class Rectangle
{
	// protected member variables
	protected:
		double length;
		double width;
	// public member functions or methods
	public:
		Rectangle();
		Rectangle(double, double);
		void setLength(double);
		void setWidth(double);
		double area();
		double perimeter();
};
#endif