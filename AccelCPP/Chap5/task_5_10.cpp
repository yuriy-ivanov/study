// task_5_10.cpp : Defines the entry point for the console application.
//
// Program to find all and max_lenght palindrome(s) from input / vocab.

#include "stdafx.h"
#include "..\..\functions.h"
#include <string>
#include <vector>
#include <list>

using namespace std;

list<string> find_palindromes(const list<string>& list);

int _tmain(int argc, _TCHAR* argv[])
{
	//input or vocab with data
	list<string> data;

	list<string> palindromes = find_palindromes(data);
	
	cout << "Palindromes found:" << endl;
	for (list<string>::const_iterator i = palindromes.begin(); i != palindromes.end(); ++i) {
		cout << (*i) << endl; 
	}

	palindromes.sort();

	cout << "Max lenght palindrome is: " << *(palindromes.end() - 1);


	return 0;
}

list<string> find_palindromes(const list<string>& lis)
{
	list<string> ret;

	for (list<string>::const_iterator i = lis.begin(); i != lis.end(); ++i) {
		if (is_palindrome(*i)) ret.push_back(*i);
	}
	return ret;
}