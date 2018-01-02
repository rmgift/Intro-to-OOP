/*************************************************************************
Author: Ryan Gift
Date: 
Description:
*************************************************************************/
#include <iostream>
#include "Store.hpp"
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	// store object for inventory call
	//Store invent;

	// product objects created
	//Product p1("123", "red blender", "great blender for making smoothies", 21.99, 20);
	//Product p2("234", "green robot", "build your very own robot, comes in red or green", 52.38, 10);
	//Product p3("345", "alloy wheels", "blend of aluminum and steel - hold air tight seal", 100.29, 50);
	//Product p4("456", "knife set", "sturdy and great for cutting wheels of cheese", 15.67, 87);
	//Product p5("567", "hot air balloon", "fly into the sky in your own balloon", 15.00, 2);

	// call addProduct in Store to add product to inventory
	//invent.addProduct(&p1);
	//invent.addProduct(&p2);
	//invent.addProduct(&p3);
	//invent.addProduct(&p4);
	//invent.addProduct(&p5);

	// customer objects created
	//Customer c1("Doug", "9876", false);
	//Customer c2("Harold", "8765", true);
	//Customer c3("Ryan", "7654", true);
	//Customer c4("Bart", "6543", false);

	// call addMember in Store to add member to list
	//invent.addMember(&c1);
	//invent.addMember(&c2);
	//mem.addMember(&c3);
	//mem.addMember(&c4);

	//invent.addProductToMemberCart("123", "8765");
	//invent.addProductToMemberCart("234", "8765");
	//invent.productSearch("green");
	//invent.checkOutMember("8765");

	Customer c1("Arlen", "1", true);
	Customer c2("Tom", "2", false);

	Product p1("123", "red blender", "Sturdy blender", 350, 4);
	Product p2("345", "hot air balloon", "Fly into the sky in your own balloon", 750, 4);

	Store s;

	s.addProduct(&p1);
	s.addProduct(&p2);

	s.addMember(&c1);
	s.addMember(&c2);

	s.addProductToMemberCart("123", "1");
	s.addProductToMemberCart("345", "1");
	s.productSearch("red");

	s.checkOutMember("1");

	s.addProductToMemberCart("345", "2");

	s.checkOutMember("1");

	s.checkOutMember("2");

	system("pause");
	return 0;
}