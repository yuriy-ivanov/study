// Task_2_5.cpp : Defines the entry point for the console application.
//
// Program for '*' output shaping: triangle, rectangle and square.

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int _tmain(int argc, _TCHAR* argv[])
{
	
	string name;

//*************************************************	
	cout << "Here goes square:" << endl;

	const int square_size = 10; //Square size

	for (int r = 0; r != square_size; ++r) {

		string::size_type c = 0;

		while (c != square_size) {

			if (r == 0 || r == square_size - 1 || c == 0 || c == square_size - 1)	
				cout << "*";
			else 
				cout << " ";
			++c;
		}
		
		cout << endl;
	}

//*************************************************
	cout << "Rectangle:" << endl;

	//rectangle width and height
	const int width = 23;
	const int height = 4;
					
	for (int r = 0; r != height; ++r) {

		string::size_type c = 0;

		while (c != width) {
			if (r == 0 || r == height - 1 || c == 0 || c == width - 1)	
				cout << "*";
			else 
				cout << " ";
			++c;
			}

		cout << endl;
		}
		
	
//*************************************************
	cout << "Triangle:" << endl;

	const int triangle_width = 15;
	const int triangle_height = 10;

	//TODO: implement triangle output

	cin >> name; //pause console
	
	return 0;
}

