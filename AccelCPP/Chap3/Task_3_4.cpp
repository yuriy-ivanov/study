// Task_3_4.cpp : Defines the entry point for the console application.
//
// Program to track marks for several students.

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::setprecision;
using std::sort; using std::streamsize; using std::string; using std::vector;

typedef struct student {
	string name;
	double midterm, final;
	vector<double> homework;
} student_str;

typedef vector<double>::size_type vec_sz;
typedef vector<student_str>::size_type student_str_sz;

double final_mark(student_str);
student_str student_input(void);


int main()
{
	
	vector<student_str> students;


	while (1) {
		students.push_back(student_input());
		cout << endl << "Enter \"stop\" to finish students input, or whatever to continue" << endl;
		cin.clear();
		string flag;
		cin >> flag;
		cin >> flag; //bullshit solution :)
		if (flag == "stop") break;
	};
		
	
	student_str_sz size = students.size();
	if (size == 0) {
		cout << endl << "No students enterd. Try again." << endl;
		return 1;
	}
	
	for (student_str_sz i = 0; i < size; ++i) {
		streamsize prec = cout.precision();
		cout << "Student [" << students[i].name << "] has final mark " <<setprecision(3) << final_mark(students[i]) << setprecision(prec) << endl;
	}
	
	cin.clear();
	string name;
	cin >> name; //pause console
		
	return 0;
}

double final_mark(student_str student) {
	vec_sz size = student.homework.size();

	if (size == 0) {
		cout << endl << "Student name: " << student.name << endl << "Homework marks required. Try again." << endl;
		return 1;
	}

	std::sort(student.homework.begin(), student.homework.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (student.homework[mid] + student.homework[mid+1]) / 2 : student.homework[mid];
}

student_str student_input(void) {

	student_str student;
	
	cin.clear();
	cout << endl << "Enter student name: ";
	cin >> student.name;
	
	cout << "Enter midterm and final exam marks: ";
	cin >> student.midterm >> student.final;

	cout << "Enter all homework marks (terminating with EOF): ";
	double x;
	while (cin >> x) student.homework.push_back(x); // Crtl + D for EOF in win.
	cin.clear();

	return student;
}
