// task_9_3.cpp : Defines the entry point for the console application.
//
// Task 9.3.a. Write program that will use grade() without catching exception.
// Task 9.3.b. Write program that will use grade() with catching exception.

#include "..\functions.h"
#include <iostream>
#include <exception>

using namespace std;

int main()
{
	//double grade(double midterm, double final, const vector<double>& hw)

	try {
		grade(0, 0, vector<double>(0));	// Task 9.3.b.
	} catch (domain_error& e) {
		cout << e.what();
	}

	grade(0, 0, vector<double>(0));	// Task 9.3.a.
	
	return 0;
}

