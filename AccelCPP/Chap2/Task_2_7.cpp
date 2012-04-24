// Task_2_7.cpp : Defines the entry point for the console application.
//
// Program to count from 10 to -5.

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;


int _tmain(int argc, _TCHAR* argv[])
{
	string name;

	for (int i = 10; i >= -5; --i) cout << "i = " << i << endl;

	cin >> name; //pause console
	
	return 0;
}

