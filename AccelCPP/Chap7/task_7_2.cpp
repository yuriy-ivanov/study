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

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "..\functions.h"

namespace task72 {

bool compare (const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}

}

int main()
{
	std::vector<Student_info> students;
	Student_info record;
	std::string::size_type max_len = 0;
	// task 7.2. 
	std::map<char, size_t> students_grades; // Key=[A,B,C,D,F], Value=count of students belong to grade range.
	
	while(read(std::cin, record))
	{
		max_len = std::max(max_len, record.name.size());
		students.push_back(record);
	}


	std::sort(students.begin(), students.end(), task72::compare);

	for (std::vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		std::cout << students[i].name << std::string(max_len + 1 - students[i].name.size(), ' ');
		try {
			//not needed, since read() responsible for grade() call
			//double final_grade = grade(students[i]); 

			// task 7.2.
			
			if (students[i].final_grade < 60.0) ++students_grades['F'];
			else if (students[i].final_grade <= 69.9) ++students_grades['D'];
			else if (students[i].final_grade <= 79.9) ++students_grades['Ñ'];
			else if (students[i].final_grade <= 89.9) ++students_grades['B'];
			else ++students_grades['A'];

			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << students[i].final_grade << std::setprecision(prec);
		}
		catch (std::domain_error& e) {
			std::cout << e.what();
		}
		std::cout << std::endl;
		
		// task 7.2.
		for(std::map<char, size_t>::const_iterator it = students_grades.begin(); it != students_grades.end(); ++it)
			std::cout << "Grade " << it->first << " - " << it->second << " students" << std::endl;

		std::cout << std::endl;
	}
	return 0;
}

