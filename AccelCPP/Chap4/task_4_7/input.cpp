#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

istream& input(istream& is, vector<double>& vec)
{
	if (is) 
	{
		vec.clear();
		double x;
		while (is >> x) vec.push_back(x);
		is.clear();
	}
	return is;

}