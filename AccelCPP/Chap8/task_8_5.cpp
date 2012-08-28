// task_8_5.cpp : Defines the entry point for the console application.
//
// Reimplement functions (chap7) "gen_sentence" and "xref" to use output iterators.
// Test these functions:
// 1. Output directly to std output stream.
// 2. Save results to "list<string>" and "map<string, vector<string> >" respectively.


#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <vector>
#include "..\..\functions.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	// output to ostream
	gen_sentence_iterator(read_grammar(cin), ostream_iterator<string>(cout, " "));
	
	// output to vector<>
	vector<string> sentence;
	gen_sentence_iterator(read_grammar(cin), back_inserter(sentence));
	
	// cout vector<>
	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty())
	{
		cout << *it;
		++it;
	}
	while (it != sentence.end())
	{
		cout << " " << *it;
		++it;
	}
	cout << endl;

	




	return 0;
}

