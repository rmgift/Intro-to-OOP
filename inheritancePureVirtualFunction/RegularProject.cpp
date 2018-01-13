/*************************************************************************
Author: Ryan Gift
Date: 03/01/2017
Description: The RegularProject.cpp file is the function implementation
 file for the derived class. The function in this file overrides the
 billAmount function in the base class to computer the total cost. This
 file should be combined with the RegularProject.hpp file, the base class
 files and a .cpp file that contains a main function.
*************************************************************************/
#include "RegularProject.hpp"

/*************************************************************************
*                       RegularProject::billAmount                       *
* This is the billAmount function. It is inherited from the              *
* CustomerProject class as a pure virtual function. It overrides the     *
* billAmount to return the sum of the materials costs, transportation    *
* costs, and $80 times the number of hours.                              *
*************************************************************************/
double RegularProject::billAmount() const
{
	return (materials + transportation + (80 * hours));
}