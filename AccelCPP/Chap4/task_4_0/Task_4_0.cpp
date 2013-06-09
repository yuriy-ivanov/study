// Task_4_0.cpp : Defines the entry point for the console application.
//
// Original source from book


#include <algorithm>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include "../../functions.h"

using namespace std;

namespace aux {
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

}

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type max_len = 0;

	while(read(cin, record))
	{
		max_len = max(max_len, record.name.size());
		students.push_back(record);
	}


	sort(students.begin(), students.end(), aux::compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		cout << students[i].name << string(max_len + 1 - students[i].name.size(), ' ');
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error& e) {
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}

