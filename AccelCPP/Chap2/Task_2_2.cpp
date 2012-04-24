// Task_2_2.cpp : Defines the entry point for the console application.
//
// Mod: changing vertical and horizontal padding

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

	//Adding padding value for rows
	//Adding padding valur for columns
	const int pad_r = 5;
	const int pad_c = 9;

	const int rows = pad_r * 2 + 3;

	const string::size_type cols = greeting.size() + pad_c * 2 + 2;

	cout << endl;

	for (int r = 0; r != rows; ++r) {

		string::size_type c = 0;

		while (c != cols) {

			if (r == pad_r + 1 && c == pad_c + 1) {
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

