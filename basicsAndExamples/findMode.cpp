/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: I could not figure out how to send the mode
 back from the function with a vector and I could not figure 
 out how to properly calculate the mode 
***********************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define DEBUG 0

// Function prototype
vector<int> findMode(int array[], int);

void displayArr(int A[], int s)
{
	cout << "Display Array Values: " << endl;
	for (int i = 0; i < s; i++)
		cout << A[i] << " ";
	cout << endl;
}

/*********************************************************
*                        findMode                        *
* This function takes an array of int and the size of    *
* the array as its parameters and returns a vector       *
* containing the mode from the array.                    *
*********************************************************/
vector<int> findMode(int arr[], int size)
{
	int index;
	// sort the array using the built in sort function
	sort(arr, arr + size);
	displayArr(arr, size);
	int newS = arr[size - 1];
	// create an array to hold the count of each value
	int *a = new int[newS];
	// initialize all the counts to 0
	for (index = 1; index <= newS; index++)
	{
		a[index] = 0;
	}
	// count the number of times a value appears
	for (index = 0; index < size; index++)
	{
		int temp = arr[index];
		a[temp] += 1;
	}

	if (DEBUG)
	{
		for (index = 1; index <= newS; index++)
			cout << a[index] << " ";
		cout << endl;
	}
	// assign the frequency variable to the number of times a number appears
	int freq = 0;
	for (index = 1; index <= newS; index++)
	{
		if (a[index] >= freq)
			freq = a[index];
	}

	if (DEBUG)
	{
		cout << "Frequency: " << freq << endl;
	}
	// if frequency is greater than 0 we have at least 1 mode
	vector<int> result;
	if (freq > 0)
	{
		// iterate the array again looking for values that match the frequency
		for (index = 1; index <= newS; index++)
		{
			if (a[index] == freq)
				result.push_back(index);
		}
	}
	return result;
}


int main()
{
	int arr[8] = { 6, 5, 10, 1, 9, 6, 9, 7 };
	vector<int> solution = findMode(arr, 8);

	if (solution.size() > 0)
	{
		cout << "The modes of the array are as follows:" << endl;
		for (std::vector<int>::iterator it = solution.begin(); it != solution.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	else
	{
		cout << "There's no mode in the array" << endl;
	}

	int arr2[8] = { 6, 5, 10, 1, 8, 3, 9, 7 };
	vector<int> solution2 = findMode(arr2, 8);
	if (solution2.size() > 0)
	{
		cout << "The modes of the array are as follows:" << endl;
		for (std::vector<int>::iterator it = solution2.begin(); it != solution2.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	else
	{
		cout << "There's no mode in the array" << endl;
	}

	system("pause");
	return 0;
}