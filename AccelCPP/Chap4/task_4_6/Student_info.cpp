#include <stdexcept>
#include "Student_info.h"
#include "grade.h"

using namespace std;

bool task46::compare(const task46::Student_info& x, const task46::Student_info& y)
{
	return x.name < y.name;
}

istream& task46::read(istream& is, task46::Student_info& s)
{
	double midterm, final;
	is >> s.name >> midterm >> final;

	vector<double> homework;
	task46::read_hw(is, homework);

	try { s.final_grade = task46::grade(midterm, final, homework); }
	catch (domain_error& e) { cout << e.what(); }
	
	return is;
}

istream& task46::read_hw(istream& is, vector<double>& hw)
{
	if (is) {
		hw.clear();

		double x;

		while (is >> x) hw.push_back(x);

		is.clear();
	}
	return is;
}
