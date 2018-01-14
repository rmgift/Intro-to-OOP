/*************************************************************************
Author: Ryan Gift
Date: 03/01/2017
Description: The ValSet.hpp file is the ValSet class declaration file. The
 class defines the member variables and the member methods that are used
 in the ValSet.cpp file. This file should be combined with the ValSet.cpp
 file and another .cpp file that contains main.
*************************************************************************/
#ifndef VALSET_HPP
#define	VALSET_HPP
#include <vector>
#include <string>
using std::vector;

template <typename T>

class ValSet
{
	private:
		T *ptr;
		int arraySize;
		int numOfVals;
		// add a prototype helper function
		void copyArray(T*) const;
	public:
		ValSet();
		ValSet(const ValSet &obj);
		// change return type here 
		ValSet<T>& operator=(const ValSet &right);
		~ValSet();
		int size();
		bool isEmpty();
		bool contains(T);
		void add(T value);
		void remove(T value);
		vector<T> getAsVector();
		void print();	// testing purposes
};
#endif