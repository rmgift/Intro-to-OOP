/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: BankAccount.cpp is the function implementation
 file. The functions in this file: initialize member 
 variables and return values passed to them or calculate
 and return values passed to them. This file should be 
 combined into a project with BankAccount.hpp and another
 .cpp file containing main.
***********************************************************/
#include "BankAccount.hpp"

// BankAccount member function implementation section

/***********************************************************
*                 BankAccount::BankAccount                 *
* This is the constructor. It initializes the member       * 
* variables customerName, CustomerID and CustomerBalance.  *
***********************************************************/
BankAccount::BankAccount(string name, string ID, double balance)
{
	customerName = name;
	customerID = ID;
	customerBalance = balance;
}

/***********************************************************
*                     getCustomerName                      *
* This function returns the value in the member variable   *
* customerName.                                            *
***********************************************************/
string BankAccount::getCustomerName()
{
	return customerName;
}
/***********************************************************
*                      getCustomerID                       *
* This function returns the value in the member variable   *
* customerID.                                              *
***********************************************************/
string BankAccount::getCustomerID()
{
	return customerID;
}

/***********************************************************
*                    getCustomerBalance                    *
* This function returns the value in the member variable   *
* customerBalance.                                         *
***********************************************************/
double BankAccount::getCustomerBalance()
{
	return customerBalance;
}

/***********************************************************
*                  BankAccount::withdraw                   *
* This function accepts a value passed and then calculates *
* the account balance by subtracting the withdraw amount   *
* from the current balance and then returning the updated  *
* balance.                                                 *
***********************************************************/
double BankAccount::withdraw(double amount)
{
	customerBalance -= amount;
	return customerBalance;
}

/***********************************************************
*                   BankAccount::deposit                   *
* This function accepts a value passed and then calculates *
* the account balance by adding the deposited amount to    *
* current balance and then returns the updated balance.    *
***********************************************************/
double BankAccount::deposit(double amount)
{
	customerBalance += amount;
	return customerBalance;
}