/*************************************************************************
Author: Ryan Gift
Date: 03/16/17
Description: The Customer.cpp file is the Customer class implementation
 file. The file initializes member variables, contains methods to return
 customer data, and empties the customer cart. A Customer object represents
 a customer with a name and their account ID. Customers must be members of
 the Store to make a purchase. Premium members get free shipping. This
 file should be combined with the Customer.hpp file as well as both Store
 and Product files, and a file that contains main.
*************************************************************************/
#include "Customer.hpp"

/*************************************************************************
*                           Customer::Customer                           *
* The Customer constructor takes as parameters three values with which   *
* to initialize the Customer's member variables name, account ID, and    *
* whether the customer is a premium member.                              *
*************************************************************************/
Customer::Customer(std::string n, std::string a, bool pm)
{
	name = n;
	accountID = a;
	premiumMember = pm;
}

/*************************************************************************
*                         Customer::getAccountID                         *
* The getAccountID method returns the value of the corresponding data    *
* member.                                                                *
*************************************************************************/
std::string Customer::getAccountID()
{
	return accountID;
}

/*************************************************************************
*                           Customer::getCart                            *
* The getCart method returns the value of the corresponding data member. *
*************************************************************************/
std::vector<std::string> Customer::getCart()
{
	return cart;
}

/*************************************************************************
*                       Customer::addProductToCart                       *
* The addProductToCart method adds the product ID code passed to the     *
* to the Customer's cart.                                                *
*************************************************************************/
void Customer::addProductToCart(std::string str)
{
	cart.push_back(str);
}

/*************************************************************************
*                       Customer::isPremiumMember                        *
* The isPremiumMember method returns whether the customer is a premium   *
* member, which if true means free shipping.                             *
*************************************************************************/
bool Customer::isPremiumMember()
{
	return premiumMember == true;
}

/*************************************************************************
*                          Customer::emptyCart                           *
* The emptyCart method empties the Customer's cart once they've checkout.*
*************************************************************************/
void Customer::emptyCart()
{
	cart.clear();
}