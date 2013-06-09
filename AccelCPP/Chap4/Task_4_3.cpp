// Task_4_3.cpp : Defines the entry point for the console application.
//
//

#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
	unsigned int val = 0;
	
	for(; val < 1000; ++val)
	{
		cout << setw(1) << val << ' '; //Gives no cut for an output larger that cout.width
		cout << setw(4) << val*val << endl;
		cout.width(0);
	}
	
	return 0;
}


