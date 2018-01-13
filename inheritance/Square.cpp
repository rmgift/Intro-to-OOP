/***********************************************************
Author: Ryan Gift
Date: 02/22/2017
Description: Square.cpp is the function implementation file
 for the derived class file Square.hpp. The functions in
 this file: calculate the area and the perimeter of a square
 by use of the base class functions declared in the 
 Rectangle.cpp file.
***********************************************************/
#include "Square.hpp"

/*********************************************************
*                      Square::area                      *
* This function returns the calculation of the area of a *
* square by using the base class, rectangle's function.  *
*********************************************************/
double Square::area()
{
	return Rectangle::area();
}

/*********************************************************
*                    Square::perimeter                   *
* This function returns the calculation of the perimeter *
* of a square by using the base classes function.        *
*********************************************************/
double Square::perimeter()
{
	return Rectangle::perimeter();
}