/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: Box.cpp is the function implementation file. 
 The functions in this file: initialize member variables,
 initialize variables values to 1, set the variables to
 values passed, and returns the calculated values of volume
 and surface area. This file should be combined into a 
 project with Box.hpp and another .cpp file containing main.
***********************************************************/
#include "Box.hpp"

// Member function implementation section

/*********************************************************
*                        Box::Box                        *
* This is the constructor. It initializes the height,    *
* width, and length class member variables.              *
*********************************************************/
Box::Box(double h, double w, double l)
{
	setHeight(h);
	setWidth(w);
	setLength(l);
}

/*********************************************************
*                        Box::Box                        *
* This is the default constructor. It initializes the    *
* set of member variables to 1.0                         *
*********************************************************/
Box::Box()
{
	height = 1.0;
	width = 1.0;
	length = 1.0;
}

/*********************************************************
*                     Box::setHeight                     *
* This function assigns the value passed to it to height *
* before calculating volume or surface area.             *
*********************************************************/
void Box::setHeight(double h)
{
	height = h;
}

/*********************************************************
*                     Box::setWidth                      *
* This function assigns the value passed to it to width  *
* before calculating volume or surface area.             *
*********************************************************/
void Box::setWidth(double w)
{
	width = w;
}
/*********************************************************
*                     Box::setLength                     *
* This function assigns the value passed to it to length *
* before calculating volume or surface area.             *
*********************************************************/
void Box::setLength(double l)
{
	length = l;
}

/*********************************************************
*                     Box::getVolume                     *
* This function calculates and returns the Box object's  *
* volume.                                                *
*********************************************************/
double Box::getVolume()
{
	return height * width * length;
}

/*********************************************************
*                  Box::getSurfaceArea                   *
* This function calculates and returns the Box object's  *
* surface area.                                          *
*********************************************************/
double Box::getSurfaceArea()
{
	return (2 * length * width) + (2 * length * height) + (2 * width * height);
}