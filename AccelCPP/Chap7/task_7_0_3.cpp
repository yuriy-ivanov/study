// task_7_0_3.cpp : Defines the entry point for the console application.
//
// Original source from chap 7, src#3 (sentence generator)
// +task 7.5. Modify program to use <list> instead of <vector>

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include "..\..\functions.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> sentence = gen_sentence(read_grammar(cin));
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

	//task 7.5. Modify program to use <list> instead of <vector>
	list<string> sentence_list = gen_sentence_list(read_grammar(cin));
	list<string>::const_iterator it_list = sentence_list.begin();
	if (!sentence_list.empty())
	{
		cout << *it_list;
		++it_list;
	}

	while (it_list != sentence_list.end())
	{
		cout << " " << *it_list;
		++it_list;
	}
	cout << endl;

	return 0;
}

