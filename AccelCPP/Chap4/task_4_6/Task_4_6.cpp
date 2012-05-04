// Task_4_6.cpp : Defines the entry point for the console application.
//
// (Original source from book)
// Task: modify struct Student_info for calculate marks instantly and saving final grade only.


#include "stdafx.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	vector<Student_info> students;
	Student_info record;
	string::size_type max_len = 0;

	while(read(cin, record))
	{
		max_len = max(max_len, record.name.size());
		students.push_back(record);
	}


	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		cout << students[i].name << string(max_len + 1 - students[i].name.size(), ' ');
		streamsize prec = cout.precision();
		cout << setprecision(3) << students[i].final_grade << setprecision(prec);
		cout << endl;
	}
	return 0;
}

