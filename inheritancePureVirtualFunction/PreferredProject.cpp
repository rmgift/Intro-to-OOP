/*************************************************************************
Author: Ryan Gift
Date: 03/01/2017
Description: The PreferredProject.cpp file is the function implementation
 file for the derived class. The function in this file overrides the
 billAmount function in the base class to computer the total cost. This
 file should be combined with the PreferredProject.hpp file, the base class
 files and a .cpp file that contains a main function.
*************************************************************************/
#include "PreferredProject.hpp"

/*************************************************************************
*                      PreferredProject::billAmount                      *
* This is the billAmount function. It is inherited from the              *
* CustomerProject class as a pure virtual function. It overrides the     *
* billAmount to return the sum of the materials costs at a 85% discount, *
* transportation costs at a 90%, and $80 times the number of hours with  *
* the maximum number of hours set at 100.                                *
*************************************************************************/
double PreferredProject::billAmount() const
{
	if (hours >= 100)
		return ((materials * 0.85) + (transportation * 0.9) + 8000);
	else
		return ((materials * 0.85) + (transportation * 0.9) + (80 * hours));
}