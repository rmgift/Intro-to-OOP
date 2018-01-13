/*************************************************************************
Author: Ryan Gift
Date: 03/01/2017
Description: 
*************************************************************************/
#include <iostream>
#include "CustomerProject.hpp"
#include "RegularProject.hpp"
#include "PreferredProject.hpp"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	RegularProject RP1(5.0, 2.0, 1.0);
	RegularProject RP2(10.0, 4.0, 2.0);

	cout << "RegularProject1 Hours: " << RP1.getHours() << endl;
	cout << "RegularProject1 Materials: " << RP1.getMaterials() << endl;
	cout << "RegularProject1 Transportation: " << RP1.getTransportation() << endl;
	cout << "RegularProject1 billAmount: " << RP1.billAmount() << endl;
	cout << endl;

	cout << "RegularProject2 Hours: " << RP2.getHours() << endl;
	cout << "RegularProject2 Materials: " << RP2.getMaterials() << endl;
	cout << "RegularProject2 Transportation: " << RP2.getTransportation() << endl;
	cout << "RegularProject2 billAmount: " << RP2.billAmount() << endl;
	cout << endl;

	PreferredProject PP1(100.0, 50.0, 25.0);
	PreferredProject PP2(200.0, 100.0, 50.0);

	cout << "PreferredProject1 Hours: " << PP1.getHours() << endl;
	cout << "PreferredProject1 Materials: " << PP1.getMaterials() << endl;
	cout << "PreferredProject1 Transportation: " << PP1.getTransportation() << endl;
	cout << "PreferredProject1 billAmount: " << PP1.billAmount() << endl;
	cout << endl;

	cout << "PreferredProject2 Hours: " << PP2.getHours() << endl;
	cout << "PreferredProject2 Materials: " << PP2.getMaterials() << endl;
	cout << "PreferredProject2 Transportation: " << PP2.getTransportation() << endl;
	cout << "PreferredProject2 billAmount: " << PP2.billAmount() << endl;

	cin.get();
	return 0;
}