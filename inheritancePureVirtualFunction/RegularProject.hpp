/*************************************************************************
Author: Ryan Gift
Date: 03/01/2017
Description: The RegularProject.hpp file is the RegularProject derived
 class declaration file. This class inherits all member variables and
 functions. The two functions defined in this file are the constructor
 and the pure virtual billAmount function.
*************************************************************************/
#ifndef REGULARPROJECT_HPP
#define REGULARPROJECT_HPP
#include "CustomerProject.hpp"

// RegularProject derived class declaration
class RegularProject : public CustomerProject
{
	public:
		// constructor takes three doubles and passes them to the base class constructor
		RegularProject(double hrs, double mtrls, double trans) : CustomerProject(hrs, mtrls, trans) {}
	
		virtual double billAmount() const;
};

#endif