// task_5_9.cpp : Defines the entry point for the console application.
//
// Program to print input words in CAPITALS then in lowercase.

#include "..\functions.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> values;
	cread(cin, values);
	for (vector<string>::iterator it = values.begin(); it != values.end(); ++it)
		for (string::iterator i = (*it).begin(); i != (*it).end(); ++i)
			(*i) = toupper(*i);

	output(cout, values);

	for (vector<string>::iterator it = values.begin(); it != values.end(); ++it)
		for (string::iterator i = (*it).begin(); i != (*it).end(); ++i)
			(*i) = tolower(*i);

	output(cout, values);

	return 0;
}

