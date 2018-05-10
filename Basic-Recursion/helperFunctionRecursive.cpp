/*********************************************************
* This example computes the length of a c-string. The 1st
* function is the recursive function that checks for null
* terminator (base case) & recursive case that adds 1. The
* helper function exists because someone shouldn't have to
* pass a parameter for character position (0). These kind
* of details should be hidden for implementation. The main
* function only calls with a string parameter, helper sets
* 0 and passes both string 0 to recursive function.
*********************************************************/
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

// recursive function
int stringLength(char str[], int pos)
{
	if (str[pos] == '\0')	// base case
		return 0;

	return stringLength(str, pos + 1) + 1;  // recursive case
}

//helper function
int stringLength(char str[])
{
	return stringLength(str, 0);	// sets parameter of 0
}

int main()
{
	char word[] = "elephant";
	cout << stringLength(word) << endl;

	cin.get();
	return 0;
}