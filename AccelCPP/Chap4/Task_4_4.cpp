// Task_4_4.cpp : Defines the entry point for the console application.
//
// Squares of 'doubles' range [0, 1000) and column-style output.

#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
	double val = 0.0;
	
	
	cout.setf(ios::dec, ios::showpoint);
	cout.setf(ios::fixed);
	cout.setf(ios::right);
	cout.precision(2);
	for(; val < 1000; val+=0.5)
	{
		cout << setw(6) << val << ' ';
		cout << setw(12) << val*val << endl;
	
	}
	
	return 0;
}

