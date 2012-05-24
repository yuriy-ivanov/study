// task_5_11.cpp : Defines the entry point for the console application.
//
// Program to find if target word has any ascenders or descenders letters.
// [add] Find max lenght word from input / vocab that has no any ascenders or descenders letters.

#include "stdafx.h"
#include "..\..\functions.h"
#include <string>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> values;
	cread(cin, values);

	string::size_type maxlen = 0;
	string maxlenword;

	cout << "Following words have ascenders or descenders: " << endl;
	for (vector<string>::const_iterator i = values.begin(); i != values.end(); ++i) {
		if (has_asc_desc(*i)) cout << (*i) << endl;
		else if ((*i).length() > maxlen) {
			maxlen = (*i).length();
			maxlenword = (*i);
		}
	}
	
	cout << endl << "Most longest word without ascenders or descenders: " << maxlenword;

	return 0;
}

