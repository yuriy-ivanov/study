// Task_4_6.cpp : Defines the entry point for the console application.
//
// (Original source from book)
// Task: modify struct Student_info for calculate marks instantly and saving final grade only.


#include <algorithm>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include "grade.h"
#include "Student_info.h"

using namespace std;


int main()
{
	vector<task46::Student_info> students;
	task46::Student_info record;
	string::size_type max_len = 0;

	while(task46::read(cin, record))
	{
		max_len = max(max_len, record.name.size());
		students.push_back(record);
	}


	sort(students.begin(), students.end(), task46::compare);

	for (vector<task46::Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		cout << students[i].name << string(max_len + 1 - students[i].name.size(), ' ');
		streamsize prec = cout.precision();
		cout << setprecision(3) << students[i].final_grade << setprecision(prec);
		cout << endl;
	}
	return 0;
}

