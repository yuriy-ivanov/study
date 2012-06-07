// task_6_3.cpp : Defines the entry point for the console application.
//
// What does the following code?:
//
// vector<int> u(10, 100);
// vector<int> v;
// copy(u.begin(), u.end(), v.begin());
//
// task_6_4 - implement at least two solutions to copy vector.


#include "stdafx.h"
#include "..\..\functions.h"
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> u(10, 100);
	vector<int> v;
	
	// does not work
	//
	//
	//	template<class InputIterator, class OutputIterator>
	//  OutputIterator copy ( InputIterator first, InputIterator last, OutputIterator result )
	//{
	//  while (first!=last) *result++ = *first++;
	//  return result;
	//}
	//
	// result++ will give out-of-range.
	//
	//
	//copy(u.begin(), u.end(), v.begin());
	copy(u.begin(), u.end(), back_inserter(v)); // works ok.

	// or this solution:
	//v.resize(u.size());
	//copy(u.begin(), u.end(), v.begin());


	for (vector<int>::iterator it = v.begin(); it < v.end(); ++it)
		cout << distance(v.begin(), it) << " " << *it << endl;

	return 0;
}

