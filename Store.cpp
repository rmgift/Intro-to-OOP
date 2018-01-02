/*************************************************************************
Author: Ryan Gift
Date: 03/16/17
Description: The Store.cpp file is the Store class implementation file. 
 The file contains methods for adding products to store inventory, adding
 customers to members, getting product and member ID's, searching for a
 specific product, adding a product to a members cart, and checking out a
 member. A Store object represents a store, which has some number of 
 products in its inventory and some number of customers as members. This
 file should be combined with the Store.hpp file as well as both Product
 and Customer files, and a file that contains main.
*************************************************************************/
#include "Store.hpp"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::find;
using std::string;
using std::vector;

/*************************************************************************
*                           Store::addProduct                            *
* The addProduct method takes a pointer to a product and adds it to the  *
* stores inventory.                                                      *
*************************************************************************/
void Store::addProduct(Product* p)
{
	// p is the address of the product, push p into our inventory
	inventory.push_back(p);
}

/*************************************************************************
*                            Store::addMember                            *
* The addMember method takes a pointer to a customer and adds them to    *
* the stores current members.                                            *
*************************************************************************/
void Store::addMember(Customer* c)
{
	// c is the address of our customer, push c into our members
	members.push_back(c);
}

/*************************************************************************
*                        Store::getProductFromID                         *
* The getProductFromID method takes a string as a parameter and returns  *
* a pointer to product with matching ID, if not found returns nullptr.   *
*************************************************************************/
Product* Store::getProductFromID(string prodStr)
{
	// iterate through our inventory looking for prodStr passed
	for (int indexP = 0; indexP < inventory.size(); indexP++)
	{
		// if prodStr found in our inventory
		if (prodStr.compare(inventory[indexP]->getIdCode()) == 0)
		{
			// return inventory pointer
			return inventory[indexP];
		}
	}
	// product not found, return nullptr
	return NULL;
}

/*************************************************************************
*                         Store::getMemberFromID                         *
* The getMemberFromID method takes a string as a parameter and returns a *
* pointer to customer with matching ID, if not found returns nullptr.    *
*************************************************************************/
Customer* Store::getMemberFromID(string memStr)
{
	// iterate through our members looking for memStr passed
	for (int indexC = 0; indexC < members.size(); indexC++)
	{
		// if memStr found in members
		if (memStr.compare(members.at(indexC)->getAccountID()) == 0)
		{
			// return member pointer
			return members[indexC];
		}
	}
	// member not found, return nullptr
	return NULL;
}

/*************************************************************************
*                          Store::productSearch                          *
* The productSearch method takes a string as a parameter and uses this   *
* string to search through the current store inventory. If the string is *
* found in the title or description the method prints out the product's  *
* title, ID code, price and description.                                 *
*************************************************************************/
void Store::productSearch(string str)
{
	// str will be product description or product title
	// iterate through all product titles and descriptions
	// if found in either title or description, print title, code, price, descr
	for (int indexP = 0; indexP < inventory.size(); indexP++)
	{
		// first compare string to product titles
		// search through inventory titles with find, until very end
		if ((inventory[indexP]->getTitle().find(str) != string::npos))
		{
			cout << inventory[indexP]->getTitle() << endl;
			cout << "Id code: " << inventory[indexP]->getIdCode() << endl;
			cout << "Price: $" << inventory[indexP]->getPrice() << endl;
			cout << inventory[indexP]->getDescription() << endl;
		}
		// if not in product titles, search through product descriptions
		// search through inventory descriptions with find, until the very end
		else if((inventory[indexP]->getDescription().find(str) != string::npos))
		{
			cout << inventory[indexP]->getTitle() << endl;
			cout << "Id code: " << inventory[indexP]->getIdCode() << endl;
			cout << "Price: $" << inventory[indexP]->getPrice() << endl;
			cout << inventory[indexP]->getDescription() << endl;
		}
	}
}

/*************************************************************************
*                     Store::addProductToMemberCart                      *
* The addProductToMemberCart method takes two string parameters, the     *
* product ID and the member ID. It then searches through the inventory   *
* and if found it then searches through members. If both product/member  *
* are found, the method adds the product to the memberscart if the       *
* quantity available is greater than zero.                               *
*************************************************************************/
void Store::addProductToMemberCart(string pID, string mID)
{
	int pFlag = 0;	// Product flag
	int mFlag = 0;	// Member flag

	// iterate through inventory looking for pID, Product
	for (int i = 0; i < inventory.size(); i++)
	{
		// if product found set pFlag to 1
		if (pID.compare(inventory[i]->getIdCode()) == 0)
		{
			pFlag = 1;
			// iterate through members looking for mID
			for (int j = 0; j < members.size(); j++)
			{
				// if member found, set mFlag to 1
				if (mID.compare(members.at(j)->getAccountID()) == 0)
				{
					mFlag = 1;
					// both product and member found, get quantity available
					if (inventory[i]->getQuantityAvailable() > 0)
					{
						// if quantity available is greater than 0, add to member cart
						members.at(j)->addProductToCart(pID);
					}
					else
					// quantity is 0, product not available
					{
						cout << "Sorry, product #[" << inventory[i]->getIdCode();
						cout << "] is currently out of stock." << endl;
					}
				}
			}
			// product found but customer is not a member
			if (mFlag == 0)
			{
				cout << "Member #[" << mID << "] not found." << endl;
			}
		}
	}
	// product is not in our inventory
	if (pFlag == 0)
	{
		cout << "Product #[" << pID << "] not found." << endl;
	}
}

/*************************************************************************
*                          Store::checkOutMember                         *
* The checkOutMember method takes a string parameter of the customers    *
* parameter. It finds the member, creates a temp cart for checkout,      *
* verifies whether or not the cart is empty, checks inventory & quantity *
* available, adds product to cart if both checkout, decreases quantity   *
* available once added, and finally calculates the subtotal, shipping,   *
* and grand total for the customer. The final step is the customer cart  *
* is emptied once the calculations are done.                             *
*************************************************************************/
void Store::checkOutMember(string mID)
{
	//int index = 0;
	int mFlag = 0;  // Member flag
	double subTotal = 0;

	// iterate through members searching for mID
	for (int index = 0; index < members.size(); index++)
	{
		// if member is found, set member flag to 1
		if (mID.compare(members.at(index)->getAccountID()) == 0)
		{
			mFlag = 1;
			// create checkout cart for member checkout
			vector<string> tempCt = members.at(index)->getCart();
			
			// if cart is empty, display message and return
			if (tempCt.empty())
			{
				cout << "There are no items in the cart." << endl;
				return;
			}

			// cart is not empty, set flag and continue
			int pFlag = 0;	// Product flag

			// iterate through cart and inventory
			for (int i = 0; i < tempCt.size(); i++)
			{
				pFlag = 0;
				// iterate through inventory making sure product ID matches 
				for (int j = 0; j < inventory.size(); j++)
				{
					// if ID matches cart, make sure its still availabile, set pFlag to 1
					if (inventory[j]->getIdCode().compare(tempCt[i]) == 0)
					{
						pFlag = 1;
						// if quantity available is greater than or equal to 1, add to cart
						if (inventory[j]->getQuantityAvailable() >= 1)
						{
							subTotal += inventory[j]->getPrice();
							inventory[j]->decreaseQuantity();
							cout << inventory[j]->getTitle();
							cout << " - $" << inventory[j]->getPrice() << endl;
						}
						// product is no longer available at checkout, do not add
						else
						{
							cout << "Sorry product #[" << inventory[j]->getIdCode();
							cout << "], " << inventory[j]->getTitle() << ", ";
							cout << "is no longer available." << endl;
						}
					}
				// get next item in cart and compare to inventory
				}
			}
			// all available items available added to cart, print subtotal
			cout << "Subtotal: $" << subTotal << endl;
			// calculate shipping cost
			int shipCost = 0;
			// if premium member, free shipping
			if (members[index]->isPremiumMember())
			{
				shipCost = 0;
			}
			// not premium member, 7% shipping charge
			else
			{
				shipCost = 0.07 * subTotal;
			}
			// print shipping cost and total cost
			cout << "Shipping Cost: $" << shipCost << endl;
			cout << "Total: $" << (shipCost + subTotal) << endl;
			// empty cart after calculation
			members.at(index)->emptyCart();
		}
	}
	// iterated through members, customer is not a member of Store
	if (mFlag == 0)
	{
		cout << "Member #[" << mID << "] not found." << endl;
	}
}