#include <vector>
#include <stdexcept>
#include "average.h"

using namespace std;

double task47::average(const vector<double>& vec)
{
	if (vec.size() == 0) throw domain_error("Empty vector");
	double summ = 0.0;
	for (vector<double>::size_type i = 0; i < vec.size(); ++i) summ += vec[i];
	return summ / (double)vec.size();
}
