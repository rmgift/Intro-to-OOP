/*************************************************************************
Author: Ryan Gift
Date: 03/01/2017
Description: The CustomerProject.cpp file is the function implementation
 file for the CustomerProject class. The functions in this file:
 initialize member variables, set the variables to values passed, and 
 return values passed to them. This file should be combined with the 
 CustomerProject.hpp file, a .cpp file that includes main, and the 4 
 additional files for the derived classes.
*************************************************************************/
#include "CustomerProject.hpp"

/*************************************************************************
*                    CustomerProject::CustomerProject                    *
* This is the default constructor. It does not take any parameters and   *
* is called when an object is not initialized.                           *
*************************************************************************/
CustomerProject::CustomerProject()
{
	setHours(0.0);
	setMaterials(0.0);
	setTransportation(0.0);
}

/*************************************************************************
*                    CustomerProject::CustomerProject                    *
* This is the constructor that takes parameters. It initializes the      *
* member variables by making calls to the set methods of each variable.  *
*************************************************************************/
CustomerProject::CustomerProject(double hrs, double mtrls, double trans)
{
	setHours(hrs);
	setMaterials(mtrls);
	setTransportation(trans);
}

/*************************************************************************
*                       CustomerProject::setHours                        *
* This function assigns the the member variable to the valued passed.    *
*************************************************************************/
void CustomerProject::setHours(double hrs)
{
	hours = hrs;
}

/*************************************************************************
*                     CustomerProject::setMaterials                      *
* This function assigns the the member variable to the valued passed.    *
*************************************************************************/
void CustomerProject::setMaterials(double mtrls)
{
	materials = mtrls;
}

/*************************************************************************
*                   CustomerProject::setTransportation                   *
* This function assigns the the member variable to the valued passed.    *
*************************************************************************/
void CustomerProject::setTransportation(double trans)
{
	transportation = trans;
}

/*************************************************************************
*                       CustomerProject::getHours                        *
* This function returns the value in the member variable hours.          *
*************************************************************************/
double CustomerProject::getHours()
{
	return hours;
}

/*************************************************************************
*                     CustomerProject::getMaterials                      *
* This function returns the value in the member variable materials.      *
*************************************************************************/
double CustomerProject::getMaterials()
{
	return materials;
}

/*************************************************************************
*                   CustomerProject::getTransportation                   *
* This function returns the value in the member variable transportation. *
*************************************************************************/
double CustomerProject::getTransportation()
{
	return transportation;
}