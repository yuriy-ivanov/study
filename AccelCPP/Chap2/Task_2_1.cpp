// Task_2_1.cpp : Defines the entry point for the console application.
//
// Changing padding to zero (no space between frame and greeting)

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int _tmain(int argc, _TCHAR* argv[])
{
	
	cout << "Enter your name: ";
	
	string name;
	cin >> name;

	const string greeting = "Hello, " + name + "!";

	const int pad = 0; // Changed to zero.

	const int rows = pad * 2 + 3;

	const string::size_type cols = greeting.size() + pad * 2 + 2;

	cout << endl;

	for (int r = 0; r != rows; ++r) {

		string::size_type c = 0;

		while (c != cols) {

			if (r == pad + 1 && c == pad + 1) {
				cout << greeting;
				c += greeting.size();
			} else {

				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
	
	cin >> name; //pause console
	
	return 0;
}

