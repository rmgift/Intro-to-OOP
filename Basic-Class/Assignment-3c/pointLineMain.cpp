/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description:
***********************************************************/
#include <iostream>
#include "Point.hpp"
#include "LineSegment.hpp"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Point p1(4.3, 7.52);
	Point p2(-17.0, 1.5);

	LineSegment ls1(p1, p2);

	double length = ls1.length();
	double slope = ls1.slope();

	cout << "In Main:" << endl;
	cout << "Point1: 4.3 and 7.52" << endl;
	cout << "Point2: -17.0 and 1.5" << endl;
	cout << "Length: " << length << endl;
	cout << "Slope: " << slope << endl;
	cout << endl;

	Point p3(-1.5, 0.0);
	Point p4(1.5, 4.0);

	double dist = p3.distanceTo(p4);
	cout << dist << endl;

	LineSegment ls2(p3, p4);

	length = ls2.length();
	slope = ls2.slope();

	cout << "Point3: -1.5 and 0.0" << endl;
	cout << "Point4: 1.5 and 4.0" << endl;
	cout << "Length: " << length << endl;
	cout << "Slope: " << slope << endl;

	cin.get();
	return 0;
}