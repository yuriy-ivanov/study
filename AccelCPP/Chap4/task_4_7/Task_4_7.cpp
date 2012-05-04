// Task_4_7.cpp : Defines the entry point for the console application.
//
// Calculate arithmetic average of vector<double>


#include "stdafx.h"
#include <vector>
#include <iostream>
#include "average.h"
#include "input.h"
#include <stdexcept>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Enter values, terminate with Crtl+Z: ";
	vector<double> val;
	input(cin, val);
	cout << endl << "Average is ";
	try {	
		cout << average(val) << endl;
	}
	catch (domain_error e) {
		cout << e.what();
	}
	return 0;
}

