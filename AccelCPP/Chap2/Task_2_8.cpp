// Task_2_8.cpp : Defines the entry point for the console application.
//
// Program to count multiplication of numbers within range [1 to 10).

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;


int main()
{
	std::string name;

	int result = 1;

	for (int i = 1; i < 10; ++i) result *= i;

	cout << "result = " << result << endl;

	cin >> name; //pause console
	
	return 0;
}

