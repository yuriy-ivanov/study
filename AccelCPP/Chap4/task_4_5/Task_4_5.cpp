// Task_4_5.cpp : Defines the entry point for the console application.
//
// 1. Function to read words from input and save into vector.
// 2. Program uses this function (#1) for: total words entered; count unique word instances from input.

#include "cread.h"

using namespace std;

int main()
{
	cout << "Input (terminate with EOF): ";
	vector<string> input;
	aux::cread(cin, input);
	
	typedef vector<string>::size_type vec_sz;
	vec_sz size = input.size();

	if (size == 0) {
		cout << endl << "No input given. Try again." << endl;
		return 1;
	}

	cout << endl << "Total words entered: " << size << endl;
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
	return 0;
}

