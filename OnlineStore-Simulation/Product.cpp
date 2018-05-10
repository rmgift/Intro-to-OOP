/*************************************************************************
Author: Ryan Gift
Date: 03/16/17
Description: The Product.cpp file is the Product class implementation file.
 The file initializes member variables, contains methods that return 
 Product data, and decreases the quantity available for a product. 
 A Product object represents a product with an ID code, title,
 description, price and quantity available. This file should be combined
 with the Product.hpp file as well as both Customer and Store files, and
 a file that contains main.
*************************************************************************/
#include "Product.hpp"

/*************************************************************************
*                            Product::Product                            *
* The Product constructor takes as parameters five values with which to  *
* initialize the Product's member variables idCode, title, description,  *
* price, and quantity available.                                         *
*************************************************************************/
Product::Product(std::string id, std::string t, std::string d, double p, int qa)
{
	idCode = id;
	title = t;
	description = d;
	price = p;
	quantityAvailable = qa;
}

/*************************************************************************
*                           Product::getIdCode                           *
* The getIdCode method return the value of the corresponding data member.*
*************************************************************************/
std::string Product::getIdCode()
{
	return idCode;
}

/*************************************************************************
*                           Product::getTitle                            *
* The getTitle method returns the value of the corresponding data member.*
*************************************************************************/
std::string Product::getTitle()
{
	return title;
}

/*************************************************************************
*                        Product::getDescription                         *
* The getDescription method returns the value of the corresponding data  *
* member.                                                                *
*************************************************************************/
std::string Product::getDescription()
{
	return description;
}

/*************************************************************************
*                           Product::getPrice                            *
* The getPrice method returns the value of the corresponding data member.*
*************************************************************************/
double Product::getPrice()
{
	return price;
}

/*************************************************************************
*                     Product::getQuantityAvailable                      *
* The getQuantityAvailable method returns the value of the corresponding *
* data member.                                                           *
*************************************************************************/
int Product::getQuantityAvailable()
{
	return quantityAvailable;
}

/*************************************************************************
*                       Product::decreaseQuantity                        *
* The decreaseQuantity method decreases the quantity available by one.   *
*************************************************************************/
void Product::decreaseQuantity()
{
	if (quantityAvailable == 0)
		quantityAvailable = 0;
	else
		--quantityAvailable;
}