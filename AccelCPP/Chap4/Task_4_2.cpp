// Task_4_2.cpp : Defines the entry point for the console application.
//
// Program to calculate squares of range [0, 100), then table-styled output using "cout.width" / "setw" function.

#include <iostream>


using namespace std;

int main()
{
	unsigned int val = 0;
	
	for(; val < 100; ++val)
	{
		cout.width(2);
		cout << val << ' ';
		cout.width(4);
		cout << val*val << endl;
		cout.width();
	}
	
	return 0;
}

