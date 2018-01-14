/***********************************************************
Author: Ryan Gift
Date: 02/22/2017
Description: The MyInteger.hpp file is the MyInteger class
 declaration file. The class defines the pointer member
 variable use in MyInteger.cpp and defines the member 
 functions used in MyInteger.cpp. This file should be 
 combined with the MyInteger.cpp file and a file with the
 main function.
***********************************************************/
#ifndef MYINTEGER_HPP
#define MYINTEGER_HPP

// MyInteger class declaration
class MyInteger
{
	// private member variable
	private:
		int *pInteger;
	// public member functions
	public:
		MyInteger();
		MyInteger(const MyInteger &value);
		MyInteger(int value);
		void setMyInt(int value);
		int getMyInt();
		MyInteger& operator=(const MyInteger &RHS);
		~MyInteger();
};
#endif