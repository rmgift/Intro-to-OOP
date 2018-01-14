/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: 
***********************************************************/
#include <iostream>
#include "Box.hpp"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Box box1(2.4, 7.1, 5.0);
	Box box2;
	double volume1 = box1.getVolume();
	double surfaceArea1 = box1.getSurfaceArea();
	double volume2 = box2.getVolume();
	double surfaceArea2 = box2.getSurfaceArea();

	cout << "Volume of 2.4 x 7.1 x 5.0: " << volume1 << endl;
	cout << endl;
	cout << "Surface Area of 2.4 x 7.1 x 5.0: " << surfaceArea1 << endl;
	cout << endl;
	cout << "Volume of 1.0 x 1.0 x 1.0: " << volume2 << endl;
	cout << endl;
	cout << "Surface Area of 1.0 x 1.0 x 1.0: " << surfaceArea2 << endl;

	cin.get();

	return 0;
}