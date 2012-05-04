#include "stdafx.h"
#include <vector>
#include <stdexcept>

using namespace std;

double average(const vector<double>& vec)
{
	if (vec.size() == 0) throw domain_error("Empty vector");
	double summ = 0.0;
	for (vector<double>::size_type i = 0; i < vec.size(); ++i) summ += vec[i];
	return summ / (double)vec.size();
}