/***********************************************************
Author: Ryan Gift
Date: 02/22/2017
Description:
***********************************************************/
#include <iostream>
#include "MyInteger.hpp"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	MyInteger obj1(17);
	MyInteger obj2 = obj1;	// calls copy constructor
	cout << obj1.getMyInt() << endl;
	cout << obj2.getMyInt() << endl;

	obj2.setMyInt(9);
	cout << obj1.getMyInt() << endl;
	cout << obj2.getMyInt() << endl;

	MyInteger obj3(42);
	obj2 = obj3;			// calls copy constructor
	cout << obj2.getMyInt() << endl;
	cout << obj3.getMyInt() << endl;

	obj3.setMyInt(1);
	cout << obj2.getMyInt() << endl;
	cout << obj3.getMyInt() << endl;
	
	MyInteger obj4(5);
	obj3 = obj4;			// calls copy constructor
	cout << obj3.getMyInt() << endl;
	cout << obj4.getMyInt() << endl;

	obj4.setMyInt(8);
	cout << obj3.getMyInt() << endl;
	cout << obj4.getMyInt() << endl;
	
	system("pause");
	return 0;
}