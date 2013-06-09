#include <algorithm>
#include <stdexcept>
#include <vector>
#include "median.h"

using namespace std;

double task46::median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0) throw domain_error("Empty vector mediate");

	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid+1]) / 2 : vec[mid];
}
