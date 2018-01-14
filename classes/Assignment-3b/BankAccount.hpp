/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: BankAccount.hpp is the BankAccount class 
 declaration file. This class defines member variables and
 member functions used in the BankAccount.cpp file.
***********************************************************/
#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPPP
#include <iostream>
using std::string;

// BankAccount class declaration
class BankAccount
{
	// private member variables or attributes
	private:
		string customerName;		// Name of customer
		string customerID;			// ID of customer
		double customerBalance;		// Balance of customer account
	// public member functions or methods
	public:
		BankAccount(string, string, double);
		string getCustomerName();
		string getCustomerID();
		double getCustomerBalance();
		double withdraw(double amount);
		double deposit(double amount);
};
#endif