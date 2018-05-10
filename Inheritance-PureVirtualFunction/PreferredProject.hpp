/*************************************************************************
Author: Ryan Gift
Date: 03/01/2017
Description: The PreferredProject.hpp file is the PreferredProject derived
 class declaration file. This class inherits all member variables and
 functions. The two functions defined in this file are the constructor
 and the pure virtual billAmount function.
*************************************************************************/
#ifndef PREFERREDPROJECT_HPP
#define PREFERREDPROJECT_HPP
#include "CustomerProject.hpp"

// PreferredProject derived class declaration
class PreferredProject : public CustomerProject
{
	public:
		// constructor takes three doubles and passes them to the base class constructor
		PreferredProject(double hrs, double mtrls, double trans) : CustomerProject(hrs, mtrls, trans) {}
	
		virtual double billAmount() const;
};

#endif