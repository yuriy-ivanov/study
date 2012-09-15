// 
//
// Task 10.3. Verify median() function modified by tasks 10.2 and 10.3.

#include "stdafx.h"
#include "..\..\functions.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const size_t arr_size = 11;

	int int_arr[arr_size];
	long long_arr[arr_size];
	double double_arr[arr_size];
	vector<int> int_vec(arr_size, 100);
	vector<long> long_vec(arr_size, 100);
	vector<double> double_vec(arr_size, 100);

	for (size_t i = 0; i < arr_size; ++i) cout << (int_arr[i] = rand()) << endl;
	cout << "-------------------------" << endl;
	cout << "Median: " << median2(int_arr, int_arr + arr_size) << endl;
	cout << "-------------------------" << endl;
	for (size_t i = 0; i < arr_size; ++i) cout << int_arr[i] << endl;
	cout << "-------------------------" << endl;
	cout << median2(long_arr, long_arr + arr_size) << endl;
	cout << median2(double_arr, double_arr + arr_size) << endl;
	cout << median2(int_vec.begin(), int_vec.end()) << endl;
	cout << median2(long_vec.begin(), long_vec.end()) << endl;
	cout << median2(double_vec.begin(), double_vec.end()) << endl;

	int *e = 0;
	int *f = e + 100;

	try {
		median2(f, e);
	} catch (domain_error e) {
		cout << e.what();
	}

	return 0;
}

