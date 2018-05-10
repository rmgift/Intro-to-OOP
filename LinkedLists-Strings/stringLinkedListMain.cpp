/*************************************************************************
Author: Ryan Gift
Date: 03/09/2017
Description: This file was not submitted with assignment as teacher tested
*************************************************************************/
#include <iostream>
#include "stringLinkedList.hpp"
using std::cout;
using std::cin;
using std::endl;
#define TESTING 1

int main()
{
	StringList list;

	
	cout << "Is Dude in list?: " << list.positionOf("Dude") << endl;
	cout << "should return false (-1): " << endl;
	cout << endl;

	StringList list2 = list;// invokes copy constructor 
	// list2 = list; would invoke assignment operator

	cout << "list2 setNode 1 and Billy: " << list2.setNodeVal(1, "Billy") << endl;
	cout << "should return false (0): " << endl;
	cout << endl;

	// Build a list
	list.add("Barry");
	list.add("Lisa");
	list.add("Michael");
	list.add("Ryan");
	
	list2.add("Alexander");
	
	list.add("Vincent");
	list.add("Walter");

	if (TESTING)
	{
		cout << "Strings in list: ";
		list.displayList();
		cout << endl;
		cout << endl;
		cout << "Strings in list2: ";
		list2.displayList();
		cout << endl;
	}

	list2.add("Chris");
	list2.add("George");
	list2.add("Melvin");

	if (TESTING)
	{
		cout << "Strings in list2: ";
		list2.displayList();
		cout << endl;
		cout << endl;
	}

	cout << "List as a vector: ";
	std::vector<std::string> myVect;
	myVect = list.getAsVector();
	for (int i = 0; i < myVect.size(); i++)
		cout << myVect[i] << " ";
	cout << endl;

	StringList list3 = list2;

	if (TESTING)
	{
		cout << "Strings in list3: ";
		list3.add("Noah");
		list3.displayList();
		cout << endl;
		cout << endl;
	}

	cout << "Is Ryan in list: " << list.positionOf("Ryan") << endl;
	cout << "Is Lisa in list: " << list.positionOf("Lisa") << endl;
	cout << "Is Walter in list: " << list.positionOf("Walter") << endl;
	cout << "Is Cindy in list: " << list.positionOf("Cindy") << endl;
	cout << endl;

	cout << "List2 as a vector: ";
	std::vector<std::string> myVect1;
	myVect1 = list2.getAsVector();
	for (int i = 0; i < myVect1.size(); i++)
		cout << myVect1[i] << " ";

	cout << endl;
	cout << endl;
	cout << "TRUE: list setNodeVal position 2 (Michael) and replace with Billy: " << list.setNodeVal(2, "Billy") << endl;

	if (TESTING)
	{
		cout << "Strings now in List: ";
		list.displayList();
		cout << endl;
		cout << endl;
	}

	cout << "FALSE: list2 setNodeVal position 6 and replace with Henry: " << list2.setNodeVal(6, "Henry") << endl;
	cout << endl;

	cout << "TRUE: list2 setNodeVal position 3 (Melvin) and replace with Henry: " << list2.setNodeVal(3, "Henry") << endl;
	
	if (TESTING)
	{
		list2.displayList();
		cout << endl;
		cout << endl;
	}

	list3.add("Tyler");
	list3.add("Amanda");
	list3.add("Franklin");
	list3.add("Willie");
	list3.add("Gary");
	list3.add("Sullivan");
	list3.add("Jared");

	if (TESTING)
	{
		cout << "Strings in list3: ";
		list3.displayList();
		cout << endl;
		cout << endl;
	}

	cout << "TRUE: list3 setNodeVal position 0 (Alexander) and replace with Alex: " << list3.setNodeVal(0, "Alex") << endl;
	cout << endl;

	if (TESTING)
	{
		cout << "Strings in list3: ";
		list3.displayList();
		cout << endl;
		cout << endl;
	}

	cin.get();
	return 0;
}