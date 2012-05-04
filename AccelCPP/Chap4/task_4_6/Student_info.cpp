#include "stdafx.h"
#include "Student_info.h"
#include "grade.h"

using namespace std;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
	double midterm, final;
	is >> s.name >> midterm >> final;

	vector<double> homework;
	read_hw(is, homework);

	try { s.final_grade = grade(midterm, final, homework); }
	catch (domain_error e) { cout << e.what(); }
	
	return is;
}

istream& read_hw(istream& is, vector<double>& hw)
{
	if (is) {
		hw.clear();

		double x;

		while (is >> x) hw.push_back(x);

		is.clear();
	}
	return is;
}