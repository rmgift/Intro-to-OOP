/**************************************************************
Author: Ryan Gift
Date: 02/22/2017
Description: MyInteger.cpp is the function implementation 
 file. The functions in this file: initialize member variables,
 sets the variable to values passed, uses a copy constructor
 to allocate a new variable and copy in to it the value from
 the other objects, and overloads the assignment operator.
**************************************************************/
#include "MyInteger.hpp"
#include <cstddef>

// Member function implementation section

/*********************************************************
*                  MyInteger::MyInteger                  *
* This constructor initializes the variable to null.       *
*********************************************************/
MyInteger::MyInteger()
{
	pInteger = nullptr;
}

/*********************************************************
*                  MyInteger::MyInteger                  *
* This is the copy constructor. 
*********************************************************/
MyInteger::MyInteger(const MyInteger &value)
{
	pInteger = value.pInteger;
}

/*********************************************************
*                  MyInteger::MyInteger                  *
* This is the constructor with parameters. It assigns the*
* address of value to pInteger and the calls the set     *
* function.                                              *
*********************************************************/
MyInteger::MyInteger(int value)
{
	pInteger = &value;
	setMyInt(value);
}

/*********************************************************
*                  MyInteger::setMyInt                   *
* This function assigns the value passed to it to the DAM*
* created in the constructor to pInteger.                *
*********************************************************/
void MyInteger::setMyInt(int value)
{
	pInteger = new int;
	*pInteger = value;
}

/*********************************************************
*                  MyInteger::getMyInt                   *
* This function returns the pInteger object's value.     *
*********************************************************/
int MyInteger::getMyInt()
{
	return *pInteger;
}

/*********************************************************
*                  MyInteger::operator=                  *
* This function overloads the operator for assignment.   *
*********************************************************/
MyInteger& MyInteger::operator=(const MyInteger &RHS)
{
	this->pInteger = RHS.pInteger;
	return *this;
}

/*********************************************************
*                 MyInteger::~MyInteger                  *
* This is the destructor. It destroys memory on the heap *
* that has been allocated for a pInteger value and then  *
* sets pInteger to null.                                 *
*********************************************************/
MyInteger::~MyInteger()
{
	delete pInteger;
	pInteger = nullptr;
}