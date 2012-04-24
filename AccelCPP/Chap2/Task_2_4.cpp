// Task_2_4.cpp : Defines the entry point for the console application.
//
// Mod: space paddings output for rows without greeting is done in one statement

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


	cout << "Enter padding value: ";
	int pad_value;
	cin >> pad_value;

	//Adding padding value for rows
	//Adding padding valur for columns
	const int pad_r = pad_value;
	const int pad_c = pad_value;

	const int rows = pad_r * 2 + 3;

	const string::size_type cols = greeting.size() + pad_c * 2 + 2;

	cout << endl;

	for (int r = 0; r != rows; ++r) {

		string::size_type c = 0;

		while (c != cols) {

			if (r == pad_r + 1 && c == pad_c + 1) { //cout greeting if location = '*' + padding (vertical and horizontal)
				cout << greeting;
				c += greeting.size();
			} else {

				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)	{cout << "*"; ++c;} //cout '*' if margins reached
				else 
					if (r != pad_r + 1) { //If row without greeting - prepare string with spaces and cout it.
						int spaces_count = cols - 2;
						c += spaces_count;
						string spaces = "";
						for (;spaces_count != 0; --spaces_count) spaces.append(" ");
						cout << spaces;
						}
					else {cout << " "; ++c;} //will cout spaces for row with greeting.
			}
		}
		cout << endl;
	}
	
	cin >> name; //pause console
	
	return 0;
}

