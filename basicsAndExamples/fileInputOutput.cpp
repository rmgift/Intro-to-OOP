/***********************************************************
Author: Ryan Gift
Date: 01/18/2017
Description: This program prompts the user to open a file
 that already exists. If the file opens successfully it 
 reads the values and sums them up. Next, it creates and 
 opens a sum.txt file where it outputs the amount and then 
 closes both files. If the file did not open from the 
 beginning you are prompted with an error message.
***********************************************************/
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{
	// Ask the user for the name of a file
	string fileName;
	cout << "Please enter the name of the file ";
	cout << "you want to open(include.txt in name): " << endl;
	cin >> fileName;
	
	// Attempt to open input file
	ifstream inputFile;
	inputFile.open(fileName);

	// If it opens, process the file
	if (inputFile)
	{
		// Loop variables to evaluate total
		int value,
			numValues = 0,
			totalSum = 0;

		// Loop until the EOF and sum numbers
		while (inputFile >> value)
		{
			numValues++;
			totalSum += value;
		}

		// Create sum.txt file and write totalSum to it
		ofstream outputFile;
		outputFile.open("sum.txt");
		outputFile << totalSum;

		// Close both output and input files
		outputFile.close();
		inputFile.close();
	}
	else // The file could not be found and opened
	{
		cout << "Could not access file. Please run program again.\n";
	}

	return 0;
}