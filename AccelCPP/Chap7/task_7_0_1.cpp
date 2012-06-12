// task_7_0_1.cpp : Defines the entry point for the console application.
//
// Original source from chap 7, src#1 (count words)

#include "stdafx.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string s;
	map<string, size_t> counters;

	while (cin >> s) ++counters[s];

	for (map<string, size_t>::const_iterator it = counters.begin(); it != counters.end(); ++it)
		cout << it->first << "\t" << it->second << endl << endl;

	// task 7.1. Modify program to output words occurrences in ascending order.

	size_t maxval = 0;
	for (map<string, size_t>::const_iterator it = counters.begin(); it != counters.end(); ++it)
		maxval = max(maxval, it->second);

	for(size_t i = 1; i <= maxval; ++i)
		for (map<string, size_t>::const_iterator it = counters.begin(); it != counters.end(); ++it)
			if (it->second == i)
				cout << it->first << "\t" << it->second << endl;
	
	return 0;
}

