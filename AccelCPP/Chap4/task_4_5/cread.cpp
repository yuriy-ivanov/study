#include "cread.h"

using namespace std;

istream& aux::cread(istream& is, std::vector<string>& vec)
{
		if (is) {
		vec.clear();
		string s;
		while (is >> s) vec.push_back(s);
		is.clear();
	}
	return is;
}
