/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description:
***********************************************************/
#include "BankAccount.hpp"
using std::cout;
using std::endl;
using std::cin;

int main()
{
	double finalBalance;
	BankAccount account1("Harold Smith", "K4637", 8032.78);
	finalBalance = account1.getCustomerBalance();
	cout << "Account created with balance of $8032.78, verify: " << finalBalance << endl << endl;

	account1.withdraw(244.0);
	finalBalance = account1.getCustomerBalance();
	cout << "Withdraw made of 244.00, balance remaining: " << finalBalance << endl << endl;

	account1.withdraw(3012.58);
	finalBalance = account1.getCustomerBalance();
	cout << "Withdraw made of 3012.58, balance remaining:" << finalBalance << endl << endl;

	account1.deposit(37.54);
	finalBalance = account1.getCustomerBalance();
	cout << "Deposit made of 37.54, balance remaining:" << finalBalance << endl << endl;

	account1.withdraw(1807.12);
	finalBalance = account1.getCustomerBalance();
	cout << "Withdraw made of 1807.12, balance remaining:" << finalBalance << endl << endl;
	
	account1.deposit(500.00);
	finalBalance = account1.getCustomerBalance();
	cout << "Deposit made of 500.00, balance remaining:" << finalBalance << endl << endl;

	account1.withdraw(4000.00);
	finalBalance = account1.getCustomerBalance();
	cout << "Withdraw made of 4000.00, balance remaining:" << finalBalance << endl;

	cin.get();

	return 0;
}