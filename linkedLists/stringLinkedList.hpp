/*************************************************************************
Author: Ryan Gift
Date: 03/09/2017
Description: The StringList.hpp file is the StringList declaration file.
 This class contains protected member varibles, a protected member struct,
 and class member functions. The members in this file allow for the use of
 a linked list object and the file should be combined with the 
 StringList.cpp file and a file that contains main. 
*************************************************************************/
#ifndef STRINGLINKEDLIST_HPP
#define STRINGLINKEDLIST_HPP
#include <vector>
#include <string>
#include <list>

// StringList class declaration

class StringList
{
protected:
	// Declare a class for the list node
	struct ListNode
	{
		std::string str;
		ListNode *next;
		// Constructor
		ListNode(std::string str1, ListNode *next1 = nullptr)
		{
			str = str1;
			next = next1;
		}
	};
	// List head pointer
	ListNode *head;
public:
	StringList();
	~StringList();
	StringList(const StringList &original);
	std::vector<std::string>getAsVector();
	bool setNodeVal(int, std::string);
	int positionOf(std::string);
	void add(std::string);
	void displayList() const;	// testing purposes
};
#endif