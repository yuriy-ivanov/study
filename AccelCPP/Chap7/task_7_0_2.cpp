// task_7_0_2.cpp : Defines the entry point for the console application.
//
// Original source from chap 7, src#2 (xref)

// +task 7.3. Modify program to output single line number for a multiple word occurrence at same line.
// +task 7.4. Modify program to output long strings with several lines.
// +task 7.7. Modify program to cout "appears in line:" for single occurrance.
//            And "appears in lines:" for multiple occurrances.
// +task 7.8. Modify program to find and output URLs and line numbers where URLs found.

#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "..\functions.h"

using namespace std;

int main()
{
	map<string, vector<size_t> > ret = xref(cin);

	for(map<string, vector<size_t> >::const_iterator it = ret.begin(); it != ret.end(); ++it)
	{
		cout << it->first << " appears in line(s): ";
		vector<size_t>::const_iterator line_it = it->second.begin();
		cout << *line_it;
		++line_it;

		while(line_it != it->second.end())
		{
			cout << ", " << *line_it;
			++line_it;
		}
		cout << endl;
	}

	// task 7.3. (description in top)
	for(map<string, vector<size_t> >::iterator it = ret.begin(); it != ret.end(); ++it)
	{
		cout << it->first << " appears in line(s): ";
		vector<size_t>::iterator line_it = it->second.begin();
		
		// Removes the duplicate consecutive elements from the range [first,last)
		line_it = unique(it->second.begin(), it->second.end());
		it->second.resize(line_it - it->second.begin());
		
		line_it = it->second.begin();

		cout << *line_it;
		++line_it;

		while(line_it != it->second.end())
		{
			cout << ", " << *line_it;
			++line_it;

			// task 7.4. Modify program to output long strings with several lines.
			if (distance(it->second.begin(), line_it) % 20 == 0) cout << endl;
			
		}
		cout << endl;
	}

	//task 7.7. Modify program to cout "appears in line:" for single occurrance.
	//And "appears in lines:" for multiple occurrances.
	
	for(map<string, vector<size_t> >::iterator it = ret.begin(); it != ret.end(); ++it)
	{
		vector<size_t>::iterator line_it = it->second.begin();
		
		// Removes the duplicate consecutive elements from the range [first,last)
		line_it = unique(it->second.begin(), it->second.end());
		it->second.resize(line_it - it->second.begin());
		
		cout << it->first << (it->second.size() > 1) ? cout << " appears in lines: " : cout << it->first << " appears in line: ";
		
		line_it = it->second.begin();

		cout << *line_it;
		++line_it;

		while(line_it != it->second.end())
		{
			cout << ", " << *line_it;
			++line_it;

			// task 7.4. Modify program to output long strings with several lines.
			if (distance(it->second.begin(), line_it) % 20 == 0) cout << endl;
			
		}
		cout << endl;
	}
	
	//task 7.8. Modify program to find and output URLs and line numbers where URLs found.
	map<string, vector<size_t> > ret2 = xref(cin, find_urls); //calling find_urls() to find URLs within a line.

	for(map<string, vector<size_t> >::const_iterator it = ret2.begin(); it != ret2.end(); ++it)
	{
		cout << it->first << " appears in line(s): ";
		vector<size_t>::const_iterator line_it = it->second.begin();
		cout << *line_it;
		++line_it;

		while(line_it != it->second.end())
		{
			cout << ", " << *line_it;
			++line_it;
		}
		cout << endl;
	}


	return 0;
}

