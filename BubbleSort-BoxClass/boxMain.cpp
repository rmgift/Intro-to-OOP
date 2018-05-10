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

// Function Prototype
void boxSort(Box array[], int size);

int main()
{
	const int SIZE = 3;
	Box arrayB[SIZE] = { Box(), Box(2.4, 7.1, 5.0), Box(2.0, 5.0, 3.0) };
	cout << "Box Volumes Before Sort:" << endl;
	for (int count = 0; count < SIZE; count++)
	{
		cout << "Volume of Box " << count + 1 << " ";
		cout << arrayB[count].getVolume() << endl;
	}
	cout << endl;
	// call sort on array of Box objects
	boxSort(arrayB, SIZE);
	cout << "Box Volumes After Sort:" << endl;
	for (int count = 0; count < SIZE; count++)
	{
		cout << "Volume of Box " << count + 1 << " ";
		cout << arrayB[count].getVolume() << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}