// Task_2_9.cpp : Defines the entry point for the console application.
//
// Ask for two numbers, then output bigger one.

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()
{
	string name;

	int number1, number2;

	cout << "Enter first number: ";
	cin >> number1; //not safe input.

	cout << "Enter second number: ";
	cin >> number2; //not safe input.

	if (number1 > number2) cout << "First number is bigger and equals " << number1 << endl;
	else 
		if (number1 < number2) cout << "Second number is bigger and equals " << number2 << endl;
		else 
			cout << "Both are equal and = " << number1 << endl;
	
	cin >> name; //pause console
	
	return 0;
}

