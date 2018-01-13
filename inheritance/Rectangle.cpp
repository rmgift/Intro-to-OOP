/***********************************************************
Author: Ryan Gift
Date: 02/22/2017
Description: Rectangle.cpp is the base class function
 implementation file. The functions in this file: initialize
 member variables, initialize values to 0, calculates the
 area and the perimeter of a rectangle.
***********************************************************/
#include "Rectangle.hpp"

/*********************************************************
*                  Rectangle::Rectangle                  *
* This is the default constructor. It initializes the    * 
* height and width class member variables to 0.          *
*********************************************************/
Rectangle::Rectangle()
{
	setLength(0.0);
	setWidth(0.0);
}

/*********************************************************
*                  Rectangle::Rectangle                  *
* This is the constructor. It initializes the height and *
* width class member variables.                          *
*********************************************************/
Rectangle::Rectangle(double len, double wid)
{
	setLength(len);
	setWidth(wid);
}

/*********************************************************
*                  Rectangle::setLength                  *
* This function initializes the length variable.         *
*********************************************************/
void Rectangle::setLength(double length)
{
	this->length = length;
}

/*********************************************************
*                  Rectangle::setWidth                   *
* This function initializes the width variable.          *
*********************************************************/
void Rectangle::setWidth(double width)
{
	this->width = width;
}

/*********************************************************
*                    Rectangle::area                     *
* This function calculates the area of a rectangle and   *
* returns the double value.                              *
*********************************************************/
double Rectangle::area()
{
	return (this->length * this->width);
}

/*********************************************************
*                  Rectangle::perimeter                  *
* This function calculates the perimeter of a rectangle  *
* and reutrns the double value.                          *
*********************************************************/
double Rectangle::perimeter()
{
	return ((this->length * 2) + (this->width * 2));
}