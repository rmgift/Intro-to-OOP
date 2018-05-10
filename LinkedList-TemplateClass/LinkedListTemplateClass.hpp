/*************************************************************************
 This header file shows how a linkedlist works by removing, adding, and
 displaying its items
*************************************************************************/
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>
using std::cout;

// LinkedList class declaration
template <typename T>

class LinkedList
{
protected:
	// Declare a class for the list node
	struct ListNode
	{
		T value;
		ListNode *next;
		ListNode(T value1, ListNode *next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};
	ListNode *head;
public:
	LinkedList()
	{
		head = nullptr;
	}
	~LinkedList();
	void add(T value);
	void remove(T value);
	void displayList() const;
};

/*************************************************************************
* adds a new element to the end of the list                              *
*************************************************************************/
template <typename T>
void LinkedList<T>::add(T value)
{
	if (head == nullptr)
		head = new ListNode(value);
	else
	{
		// The list is not empty, use nodePtr to traverse the list
		ListNode *nodePtr = head;
		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}
		// nodePtr->next is nullptr so nodePtr points to last node
		// Create a new node and put it after the last node
		nodePtr->next = new ListNode(value);
	}
}

/*************************************************************************
* removes a number from the list, the function does not assume that the  *
* list is sorted.                                                        *
*************************************************************************/
template <typename T>
void LinkedList<T>::remove(T value)
{
	ListNode *nodePtr;
	ListNode *previousNodePtr = nullptr;

	// If the list is empty do nothing
	if (!head)
	{
		return;
	}

	// Determine if the first node is the one to delete
	if (head->value == value)
	{
		nodePtr = head;
		head = head->next;
		delete nodePtr;
	}
	else
	{
		// Initialize nodePtr to the head of the list
		nodePtr = head;

		// Skip nodes whose value memeber is not num
		while (nodePtr != nullptr && nodePtr->value != value)
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr->next;
		}

		// Link the previous node to the node after
		// nodePtr, then delete nodePtr
		if (nodePtr)
		{
			previousNodePtr->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

/*************************************************************************
* displayList outputs a sequence of all values currently stored in the   *
* list                                                                   *
*************************************************************************/
template <typename T>
void LinkedList<T>::displayList() const
{
	// start at the head of list
	ListNode *nodePtr = head;

	while (nodePtr)
	{
		// Print the value in the current node
		cout << nodePtr->value << "  ";
		
		// Move on to the next node
		nodePtr = nodePtr->next;
	}
}

/*************************************************************************
* destructor deallocates the memory used by the list                     *
*************************************************************************/
template <typename T>
LinkedList<T>::~LinkedList()
{
	// start at the head of the list
	ListNode *nodePtr = head;

	while (nodePtr != nullptr)
	{
		// garbage keeps track of node to be deleted
		ListNode *garbage = nodePtr;

		// move on to the next node, if any
		nodePtr = nodePtr->next;

		// delete the "garbage" node
		delete garbage;
	}
}

#endif