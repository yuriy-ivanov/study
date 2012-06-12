// task_7_2.cpp : Defines the entry point for the console application.
//
// Modify program to assign letters to students depending on grade ranges:
// A - 90-100
// B - 80-89.99
// C - 70-79.99
// D - 60-69.99
// F - <60
//
// Results should contain count of students assigned to each grade range (category).

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "..\..\functions.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Student_info> students;
	Student_info record;
	string::size_type max_len = 0;
	// task 7.2. 
	map<char, size_t> students_grades; // Key=[A,B,C,D,F], Value=count of students belong to grade range.
	
	while(read(cin, record))
	{
		max_len = max(max_len, record.name.size());
		students.push_back(record);
	}


	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		cout << students[i].name << string(max_len + 1 - students[i].name.size(), ' ');
		try {
			//not needed, since read() responsible for grade() call
			//double final_grade = grade(students[i]); 

			// task 7.2.
			
			if (students[i].final_grade < 60.0) ++students_grades['F'];
			else if (students[i].final_grade <= 69.9) ++students_grades['D'];
			else if (students[i].final_grade <= 79.9) ++students_grades['Ñ'];
			else if (students[i].final_grade <= 89.9) ++students_grades['B'];
			else ++students_grades['A'];

			streamsize prec = cout.precision();
			cout << setprecision(3) << students[i].final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
		
		// task 7.2.
		for(map<char, size_t>::const_iterator it = students_grades.begin(); it != students_grades.end(); ++it)
			cout << "Grade " << it->first << " - " << it->second << " students" << endl;

		cout << endl;
	}
	return 0;
}

