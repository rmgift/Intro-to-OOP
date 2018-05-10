/***********************************************************
Author: Ryan Gift
Date: 01/25/2017
Description: Student.hpp is the Student class declaration
 file. This file defines member variables and member
 functions used in the Student.cpp file.
***********************************************************/
#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
using std::string;

// Student class declaration
class Student
{
	private:
		string name;
		double score;
	public:
		Student(string, double);
		void setName(string);
		void setScore(double);
		string getName();
		double getScore();
};
#endif