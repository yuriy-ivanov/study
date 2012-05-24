// task_5_0.cpp : Defines the entry point for the console application.
//
// original source from book (strings splitting, framing and output)

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include "..\..\functions.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string s;

	//while (getline(cin, s)) vector<string> input = split(s);

	while (getline(cin, s)){ 
		vector<string> splitted = split(s);
		vector<string> framed = frame(splitted);

		cout << endl << "Split output by spaces: " << endl;
		output(cout, splitted);
		cout << endl << "Framed output: " << endl;
		output(cout, framed);
		cout << endl << "Horizontal concatenation: " << endl;
		output(cout, hcat(splitted, framed));
		cout << endl << "Vertical concatenation: " << endl;
		output(cout, vcat(splitted, framed));
	}
	return 0;
}

