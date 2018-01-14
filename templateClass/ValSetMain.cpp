/***********************************************************
Author: Ryan Gift
Date: 03/01/2017
Description:
***********************************************************/
#include <iostream>
#include "ValSet.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	ValSet<int> obj1;
	ValSet<int> obj2 = obj1;	// invokes copy constructor
	obj1 = obj2;				// invokes assignment operator
	cout << "obj1<int> size 0: " << obj1.size() << endl;
	obj1.getAsVector();
	cout << "obj1<int> empty: " << obj1.isEmpty() << endl;
	cout << "obj1<int> contains 2: " << obj1.contains(2) << endl;
	cout << "obj1<int> contains 0: " << obj1.contains(0) << endl;

	obj1.add(1);

	ValSet<char> obj3;
	cout << "obj3<char> size 0: " << obj3.size() << endl;
	cout << "obj3<char> contains 0: " << obj1.contains(0) << endl;
	cout << "obj3<char> contains A: " << obj1.contains('A') << endl;

	ValSet<string> obj4;
	cout << "obj4<string> size 0: " << obj4.size() << endl;
	
	obj1.add(3);
	obj1.add(9);
	obj4.add("Test");
	obj4.add("New");
	obj4.add("Oops");
	obj1.print();
	cout << "obj4<string> size 3: " << obj4.size() << endl;
	obj1.add(5);
	cout << "obj1<int> contains 2: " << obj1.contains(2) << endl;
	obj1.add(7);
	obj1.add(2);
	cout << "obj1<int> size 6: " << obj1.size() << endl;
	cout << "obj1<int> empty: " << obj1.isEmpty() << endl;
	
	obj1.add(8);
	obj1.add(4);
	obj1.add(6);
	cout << "obj1<int> size 9: " << obj1.size() << endl;
	obj1.print();

	obj3.add('?');
	obj3.print();
	obj3.add('L');
	obj3.add('@');
	obj3.add('!');
	obj3.print();

	obj1.add(15);
	obj1.add(10);
	obj1.add(11);
	obj1.add(14);
	
	obj1.print();
	cout << "size 13: " << obj1.size() << endl;

	obj1.remove(5);
	cout << "size 12: " << obj1.size() << endl;
	obj1.print();

	obj1.remove(1);
	obj1.remove(6);
	obj1.remove(14);
	obj1.print();
	cout << "obj1<int> size 6: " << obj1.size() << endl;

	obj3.remove('@');
	obj3.print();
	cout << "obj1<int> size 3: " << obj3.size() << endl;
	
	// teacher examples given:
	/*
	ValSet<char> mySet;
	mySet.add('A');
	mySet.add('j');
	mySet.add('&');
	mySet.remove('j');
	mySet.add('#');
	int size = mySet.size();
	ValSet<char> mySet2 = mySet;
	bool check1 = mySet2.contains('&');
	bool check2 = mySet2.contains('j');
	*/

	system("pause");

	return 0;
}