/*************************************************************************
Author: Ryan Gift
Date: 03/01/2017
Description: The CustomerProject.hpp file is the CustomerProject base
 class declaration file. The class defines the member variables used in
 the CustomerProject.cpp file, additionally these variables are inherited
 by the RegularProject and PreferredProject classes. Also, this file
 defines the member functions in the CustomerProject.cpp file and these
 functions are also inherited by the RegularProject and PreferredProject 
 classes. This file should be combined with the CustomerProject.cpp file,
 a file that contains the main function, and the 4 additonal files of the
 derived classes.
*************************************************************************/
#ifndef CUSTOMERPROJECT_HPP
#define CUSTOMERPROJECT_HPP

// CustomerProject base class declaration

class CustomerProject
{
protected:
	double hours;			// the number of hours the project took
	double materials;		// the cost of materials
	double transportation;	// transportation costs
public:
	CustomerProject();
	CustomerProject(double hrs, double mtrls, double trans);
	void setHours(double hrs);
	void setMaterials(double mtrls);
	void setTransportation(double trans);
	double getHours();
	double getMaterials();
	double getTransportation();
	virtual double billAmount() const = 0;	// pure virtual function and returns a double
};
#endif