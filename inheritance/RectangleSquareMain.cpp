/***********************************************************
Author: Ryan Gift
Date: 02/22/2017
Description: 
***********************************************************/
#include <iostream>
#include "Rectangle.hpp"
#include "Square.hpp"
using std::cout;
using std::cin;
using std::endl;


int main()
{
	Rectangle r(5, 2.5);
	Square q(10);
	
	cout << "Area of shape r: " << r.area() << endl;
	cout << "Perimeter of shape r: " << r.perimeter() << endl;
	
	cout << "Area of shape q: " << q.area() << endl;
	cout << "Perimeter of shape q: " << q.perimeter() << endl;

	Square q2(15);
	cout << "Area of shape q: " << q2.area() << endl;
	cout << "Perimeter of shape q: " << q2.perimeter() << endl;

	cin.get();
	return 0;
}