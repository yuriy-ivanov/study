// Task_2_7.cpp : Defines the entry point for the console application.
//
// Program to count from 10 to -5.

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;


int main()
{
	std::string name;

	for (int i = 10; i >= -5; --i) cout << "i = " << i << endl;

	cin >> name; //pause console
	
	return 0;
}

