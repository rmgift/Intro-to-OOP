/*************************************************************************
Author: Ryan Gift
Date: 03/01/2017
Description: The ValSet.cpp file is the method implementation file for the
ValSet class. The functions in this file initialize member variables,
copies objects as their created, deallocates memory, returns the size of
the ValSet obj, returns bool variables if the ValSet is empty or contains
a value passed, adds values to the ValSet, removes values from the
Valset, and returns a vector copy of the ValSet. This file should be
combined with the ValSet.hpp file and another .cpp file that contains
main.
*************************************************************************/
#include "ValSet.hpp"
#include <algorithm>
#include <array>
#include <string>
#include <iostream>
using std::cout;
using std::endl;

/*************************************************************************
*                             ValSet::ValSet                             *
* This method is the default constructor initializes pointer data member *
* to point to an array of size 10, initializes the variable that stores  *
* the size of the array to 10, and initializes the variable that stores  *
* the number of values in the set to zero.                               *
* pg. 727 in book
*************************************************************************/
template <typename T>
ValSet<T>::ValSet()
{
	arraySize = 10;	// initializes the variable that stores the size of the array to 10
	numOfVals = 0;	// initializes the variable that stores the number of values in the set to zero
	ptr = new T[arraySize];
}

/*************************************************************************
*                             ValSet::ValSet                             *
* This method is the copy construct that initializes the pointer data    *
* member to point to an array of the same size as the one being copied,  *
* copies over the array values, and also copies the values for the size  *
* of the array and the number of values in the set.                      *
* pg. 727 in book
*************************************************************************/
template <typename T>
ValSet<T>::ValSet(const ValSet &obj)
{
	arraySize = obj.arraySize;
	numOfVals = obj.numOfVals;
	ptr = new T[arraySize];

	this->copyArray(obj.ptr);
}

/*************************************************************************
*                           ValSet::operator=                            *
* This method is the overloaded assignment operator that initializes the *
* pointer data member to point to an array of the same size as the one   *
* being copied, copies over the array values, copies the values for the  *
* size of the array and the number of values in the set, and returns the *
* object pointed to by the this pointer.                                 *
* pg. 734 in book
*************************************************************************/
template <typename T>
ValSet<T>& ValSet<T>::operator=(const ValSet &right)
{
	// add the if statement
	if (this == &right) {
		return *this;
	}

	arraySize = right.arraySize;
	numOfVals = right.numOfVals;

	// always check and see if u need to first delete before allocating
	if (this->ptr != nullptr) {
		delete[] this->ptr;  // deletes everything :(
	}
	this->ptr = new T[arraySize];

	this->copyArray(right.ptr);

	return *this;
  // ValSet<T> obj2 = obj1; this invokes copy constructor
  // obj1 = obj2; invokes the assignment operator
  // so the for loop arraySize needs change to numOfVals
  // question of why we need new? since its already defined?
  // thats just allocating the amount of sapace for the array now adjusted
}

/*************************************************************************
*                            ValSet::~ValSet                             *
* The destructor deallocates the dynamically allocated array.            *
*************************************************************************/
template <typename T>
ValSet<T>::~ValSet()
{
	delete[] ptr;
	ptr = nullptr;
}

/*************************************************************************
*                              ValSet::size                              *
* This method returns the number of values currently in the ValSet.      *
*************************************************************************/
template <typename T>
int ValSet<T>::size()
{
	return numOfVals;
}

/*************************************************************************
*                            ValSet::isEmpty                             *
* This is the isEmpty() method and returns true if the ValSet contains   *
* no values, and returns false otherwise.                                *
*************************************************************************/
template <typename T>
bool ValSet<T>::isEmpty()
{
	// if (numOfVals == 0)
	// 	return true;
	// else
	// 	return false;

	// exactly the same as above code
	return numOfVals == 0;
}

/*************************************************************************
*                            ValSet::contains                            *
* This is the contains method that takes a parameter of type T and it    *
* returns true if value is in the ValSet and returns false otherwise.    *
*************************************************************************/
template <typename T>
bool ValSet<T>::contains(T val)
{
	// loop through every value in the array
	for (int i = 0; i < numOfVals; i++) {
		// if the current value equals the val we are checking
		if (ptr[i] == val) {
			return true;
		}
	}
	// after checking all the values, since we didn't find it we return not found
	return false;
}

/*************************************************************************
*                              ValSet::add                               *
* This is the add() method that takes a parameter of type T and adds     *
* that value to the ValSet, if that value is not already in the ValSet.  *
* If the array is currently full, then we make the array twice as large  *
* by allocating a new array, copy its contents over to the new array,    *
* redirect the data member pointer to the new array, and deallocate.     *
*************************************************************************/
template <typename T>
void ValSet<T>::add(T value)
{
	// if array doesn't contain value
	if (contains(value) == 0)
	{
		// check if ValSet is full, if full double size
		if (numOfVals >= arraySize)
		{
			// double size
			int t = arraySize;
			arraySize *= 2;

			// create temp pointer to double array
			T *temp = new T[arraySize];

			// copy in values to temp array
			for (int i = 0; i < numOfVals; i++)
			{
				temp[i] = ptr[i];
			}

			// deallocate old ptr
			delete[] ptr;

			// set ptr to new temp 
			ptr = temp;
		}

		ptr[numOfVals] = value;

		// incrememnt count
		numOfVals++;
	}
}

/*************************************************************************
*                             ValSet::remove                             *
* This is the remove() method, that takes a parameter of type T for some *
* value. If the value is in ValSet it removes the value by shifting over *
* all of the subsequent elements of the array and excludes the value.    *
*************************************************************************/
template <typename T>
void ValSet<T>::remove(T value)
{
	// contains value, if not do nothing
	if (contains(value) == true)
	{
		int i = 0;
		while (ptr[i] != value)
		{
			i++;
		}
		ptr[i] = ptr[numOfVals - 1];
		--numOfVals;
	}
}

/*************************************************************************
*                          ValSet::getAsVector                           *
* This is the getAsVector method, that returns a vector (of type T) and  *
* contains all of the values in the ValSet and only those values.        *
*************************************************************************/
template <typename T>
vector<T> ValSet<T>::getAsVector()
{
	vector<T> vect(numOfVals);

	// now we need to copy values in to vector
	for (int i = 0; i < numOfVals; i++)
		vect.at(i) = ptr[i];

	return vect;
}

template <typename T>
void ValSet<T>::copyArray(T* that) const 
{
	for (int i = 0; i < numOfVals; i++)
	{
		this->ptr[i] = that[i];
	}
}

template <typename T>
void ValSet<T>::print()
{
	cout << "New values: ";
	for (int i = 0; i < arraySize; i++)
		cout << ptr[i] << " ";
	cout << endl;
}

template class ValSet<int>;
template class ValSet<char>;
template class ValSet<std::string>;