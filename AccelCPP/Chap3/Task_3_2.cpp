// Task_3_2.cpp : Defines the entry point for the console application.
//
// Program to count unique data instances within input.

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::setprecision;
using std::sort; using std::streamsize; using std::string; using std::vector;

int main()
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

	cout << endl << "Format: \"Data value\", [Count]\n";
				 	
	while (!input.empty()) {

		int counter = 0;
		string temp = input.back();
		input.pop_back();
		++counter;

		int i = input.size() - 1;
		while (i >= 0) {
			if (input[i] == temp) {
				input.erase(input.begin() + i);
				++counter;
			}
			--i;
		}

		cout << "\"" << temp << "\", [" << counter << "]" << endl;
	}
	
	string console;
	cin.clear();
	cin >> console; //pause console
		
	return 0;
}

