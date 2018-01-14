/*************************************************************************
Author: Ryan Gift
Date: 03/09/2017
Description: The StringList.cpp file is the method implementation file for
 the StringList class. The member functions in this file are the 
 constructor, destructor, copy constructor, getAsVector function, 
 setNodeVal method, positionOf method, and add method. This file should
 be combined with the StringList.hpp file and another .cpp file that 
 contains main.
*************************************************************************/
#include "stringLinkedList.hpp"
#include <iostream> // testing
using std::cout;	// testing

/*************************************************************************
*                         StringList::StringList                         *
* The default constructor initializes a new empty StringList object.     *
*************************************************************************/
StringList::StringList()
{
	head = nullptr;
}

/*************************************************************************
*                        StringList::~StringList                         *
* The destructor deletes any memory that was dynamically allocated by    *
* the StringList object.                                                 *
*************************************************************************/
StringList::~StringList()
{
	// Start at head of list
	ListNode *nodePtr = head;

	while (nodePtr != nullptr)
	{
		// garbage keeps track of node to be deleted
		ListNode *garbage = nodePtr;

		// move on to the next node, if any
		nodePtr = nodePtr->next;

		delete garbage;
	}
}

/*************************************************************************
*                         StringList::StringList                         *
* The copy constructor creates a completely separate duplicate of the    *
* StringList object (a deep copy).                                       *
*************************************************************************/
StringList::StringList(const StringList &obj)
{
	// if nothing in list set new head to nullptr
	if (obj.head == nullptr)
	{
		head = nullptr;
	}
	else
	{
		// New head gets a copy of first string
		head = new ListNode(obj.head->str);
		
		// create temp pointer to new head
		ListNode *temp = head;
		
		// create objHead pointer to copy of original object head
		ListNode *objHead = obj.head;
		
		// create tempObject pointer copy objHead
		ListNode *tempObject = objHead;
		
		while (tempObject->next != nullptr)
		{
			temp->next = new ListNode(tempObject->next->str);
			tempObject = tempObject->next;
			temp = temp->next;
		}
	}
}

/*************************************************************************
*                        StringList::getAsVector                         *
* The getAsVector method returns a vector with the same size, values and *
* order as the StringList Linked List.                                   *
*************************************************************************/
std::vector<std::string>StringList::getAsVector()
{
	// start at head of list
	ListNode *secPtr = head;
	int SIZE = 0;

	// get size of list
	while (secPtr != nullptr)
	{
		SIZE += 1;
		secPtr = secPtr->next;
	}

	// convert my list in to a vector
	std::vector<std::string> vect(SIZE);
	ListNode *nodePtr = head;

	for (int i = 0; i < SIZE; i++)
	{
		if (nodePtr != nullptr)
		{
			vect[i] = nodePtr->str;
			nodePtr = nodePtr->next;
		}
	}
	
	return vect;
}

/*************************************************************************
*                         StringList::setNodeVal                         *
* The setNodeVal method takes two parameters. The first parameter        *
* represents a (zero-based) position in the list. The method sets the    *
* value of the node at that position to the value of the string          *
* parameter. If the position passed is >= the # of nodes in the list the *
* operation cannot be carried out and returns false.                     *
*************************************************************************/
bool StringList::setNodeVal(int pos, std::string strPass)
{
	ListNode *nodePtr = head;
	ListNode *secPtr = head;
	int SIZE = 0;
	int travP = 0;
	
	// If the list is empty, return false
	if (!nodePtr)
		return false;

	// Size of list
	while (nodePtr != nullptr)
	{
		SIZE += 1;
		nodePtr = nodePtr->next;
	}

	// If position passed is greater than size, false
	if (pos >= SIZE)
		return false;

	// traverse list to the position and replace with string passed
	while (secPtr != nullptr)
	{
		if (pos == travP)
		{
			secPtr->str = strPass;
			travP++;
		}
		else
		{
			secPtr = secPtr->next;
			travP++;
		}
	}

	return true;
}

/*************************************************************************
*                         StringList::positionOf                         *
* The positionOf method returns the (zero-based) position in the list    *
* for the first occurrence of the parameter in the list, or -1 if that   *
* value is not in the list.                                              *
*************************************************************************/
int StringList::positionOf(std::string str)
{
	// If the list is empty, do nothing
	if (head == nullptr)
		return (-1);

	// Determine if str is in list
	int count = 0;
	ListNode *nodePtr = head;

	while (nodePtr != nullptr)
	{
		if (nodePtr->str == str)
		{
			return count;
		}
		nodePtr = nodePtr->next;
		count++;
	}
	delete nodePtr;
	return (-1);
}

/*************************************************************************
*                            StringList::add                             *
* The add method inserts a new node containing the value of the          *
* parameter to the end of the list.                                      *
*************************************************************************/
void StringList::add(std::string addStr)
{
	if (head == nullptr)
	{
		head = new ListNode(addStr);
	}
	else
	{
		// The list isn't empty so traverse the list with nodePtr
		ListNode *nodePtr = head;
		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}

		// nodePtr->next is nullptr so nodePtr points to last node
		// create a new node and put it after the last node
		nodePtr->next = new ListNode(addStr);
	}
}

// Testing purposes
void StringList::displayList() const
{
	ListNode *nodePtr = head;	// start at head of list
	while (nodePtr)
	{
		cout << nodePtr->str << " ";
		nodePtr = nodePtr->next;
	}
	delete nodePtr;
}