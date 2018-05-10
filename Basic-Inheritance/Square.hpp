/***********************************************************
Author: Ryan Gift
Date: 02/22/2017
Description: Square.hpp is the Square class declaration file
 that has an inheritance from the base class Rectangle. The
 member functions are defined here.
***********************************************************/
#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "Rectangle.hpp"

// Square class declaration
class Square : public Rectangle
{
	// public member functions or methods
	public:
		Square(double side) : Rectangle(side, side) {}
		double area();
		double perimeter();
};
#endif