/*************************************************************************
* This program demonstrates the linkedlist template being used to create
* a linkedlist of strings, however since its a template you could use any
* data type that works with comparison operators. This file needs combined
* with the LinkedList.hpp file.
*************************************************************************/
#include <iostream>
#include <string>
#include "LinkedList.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	LinkedList<string> list;

	// Build a list
	list.add("Barry");
	list.add("Lisa");
	list.add("Michael");
	list.add("Ryan");
	list.add("Vincent");

	cout << "Here are the initial names: " << endl;
	list.displayList();
	cout << endl;
	cout << endl;

	cout << "Now removing Michael" << endl;
	list.remove("Michael");
	cout << endl;
	cout << "Here are the remaining elements: " << endl;
	list.displayList();
	cout << endl;

	cout << "Creating a new list of ints" << endl;
	LinkedList<int> list2;
	for (int i = 0; i < 10; i++)
		list2.add(i * 3);
	cout << "List of ints: " << endl;
	list2.displayList();

	cin.get();
	return 0;
}