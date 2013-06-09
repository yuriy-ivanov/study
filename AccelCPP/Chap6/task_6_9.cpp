// task_6_9.cpp : Defines the entry point for the console application.
//
// Using suitable library algo concatenate all elements of vector<string>

#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>
#include "..\functions.h"

using namespace std;

vector<string> source; // source vector 
string destination = "";

void appender(const string& s);

int main()
{
	typedef vector<string>::const_iterator iter;
	
	cread(cin, source);
	
	//Sol 1:
	for (iter it = source.begin(); it < source.end(); ++it)	destination += *it;

	//Sol 2:
	for (iter it = source.begin(); it < source.end(); ++it)	destination.append(*it);

	//Sol 3:
	for_each(source.begin(), source.end(), appender);

	cout << destination << endl;

	return 0;
}

void appender(const string& s)
{
	destination.append(s);
}

