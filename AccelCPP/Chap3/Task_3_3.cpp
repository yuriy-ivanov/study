// Task_3_3.cpp : Defines the entry point for the console application.
//
// Output shortest and longest string from input.

#include "stdafx.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::setprecision;
using std::sort; using std::streamsize; using std::string; using std::vector;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Input (terminate with EOF): ";
	vector<string> input;
	string x;
	while (cin >> x) input.push_back(x); // Crtl + D for EOF in win.

	typedef vector<string>::size_type vec_sz;
	vec_sz size = input.size();

	if (size == 0) {
		cout << endl << "No input given. Try again." << endl;
		return 1;
	}

	cout << endl;
	
	string longest;
	string shortest = longest = input[0];
	unsigned int shortest_val = shortest.length();
	unsigned int longest_val = longest.length();
		
	for (unsigned int i = 0; i < input.size(); ++i) {
		string temp = input[i];
		if (temp.length() > longest_val) { longest = temp; longest_val = temp.length(); }
		if (temp.length() < shortest_val){ shortest = temp; shortest_val = temp.length(); }
	}

	cout << "Shortest = " << shortest << endl << "Longest = " << longest << endl;

	string console;
	cin.clear();
	cin >> console; //pause console
		
	return 0;
}

