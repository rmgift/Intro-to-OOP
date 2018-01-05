/*************************************************************************
Author: Ryan Gift
Date: 03/16/17
Description: This file run some basic tests on the online store 
 assignment and the corresponding program files.
*************************************************************************/
#include <iostream>
#include "Store.hpp"
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void test1()
{
	Customer c1("Arlen", "1", true);
	Customer c2("Tom", "2", false);
	Product p1("123", "red blender", "Sturdy blender", 350.25, 4);
	Product p2("345", "hot air balloon", "Fly into the sky in your own balloon", 750.61, 4);
	Store s;
	// add products to inventory
	s.addProduct(&p1);
	s.addProduct(&p2);
	// add customers to members
	s.addMember(&c1);
	s.addMember(&c2);
	// add products to member carts
	s.addProductToMemberCart("123", "1");
	s.addProductToMemberCart("345", "1");
	// search for a product
	s.productSearch("red");
	// checkout a specified member
	s.checkOutMember("1");
	// add a product to member cart
	s.addProductToMemberCart("345", "2");
	// try to checkout member w/nothing in cart
	cout << endl << "Checking out Customer" << endl;
	s.checkOutMember("1");
	// checkout other member
	cout << endl << "Checking out Customer" << endl;
	s.checkOutMember("2");
}

void test2()
{
	// store object for inventory call
	Store invent;

	// product objects created
	Product p1("123", "red blender", "great blender for making smoothies", 21.99, 20);
	Product p2("234", "green robot", "build your very own robot, comes in red or green", 52.38, 10);
	Product p3("345", "alloy wheels", "blend of aluminum and steel - hold air tight seal", 100.29, 50);
	Product p4("456", "knife set", "sturdy and great for cutting wheels of cheese", 15.67, 87);
	Product p5("567", "hot air balloon", "fly into the sky in your own balloon", 15.00, 2);

	// call addProduct in Store to add product to inventory
	invent.addProduct(&p1);
	invent.addProduct(&p2);
	invent.addProduct(&p3);
	invent.addProduct(&p4);
	invent.addProduct(&p5);

	// customer objects created
	Customer c1("Doug", "9876", false);
	Customer c2("Harold", "8765", true);
	Customer c3("Ryan", "7654", true);
	Customer c4("Bart", "6543", false);

	// call addMember in Store to add member to list
	invent.addMember(&c1);
	invent.addMember(&c2);
	invent.addMember(&c3);
	invent.addMember(&c4);
	// add products to cart
	invent.addProductToMemberCart("123", "8765");
	invent.addProductToMemberCart("234", "8765");
	invent.addProductToMemberCart("567", "8765");
	// search for prodducts
	invent.productSearch("green");
	invent.productSearch("aluminum");
	// add products to cart
	invent.addProductToMemberCart("234", "9876");
	invent.addProductToMemberCart("456", "9876");
	invent.addProductToMemberCart("567", "9876");
	invent.addProductToMemberCart("345", "9876");
	invent.addProductToMemberCart("234", "7654");
	invent.addProductToMemberCart("345", "7654");
	invent.addProductToMemberCart("567", "7654");
	invent.addProductToMemberCart("456", "7654");
	// check out members
	cout << endl << "Checking out Customer" << endl;
	invent.checkOutMember("8765");
	cout << endl << "Checking out Customer" << endl;
	invent.checkOutMember("7654");
	cout << endl << "Checking out Customer" << endl;
	invent.checkOutMember("9876");
}

int main()
{
	test1();
	cout << endl << "Done Testing First Round" << endl << endl;

	test2();
	cout << endl << "Done Testing Second Round" << endl << endl;

	system("pause");
	return 0;
}