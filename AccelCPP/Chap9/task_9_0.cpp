// task_9_0.cpp : Defines the entry point for the console application.
//
// Task 9.0. Source from chapter 9.
// Task 9.1. Modify Student_info_class to calculate "grade" on student record read,
//			"grade" result should be kept whitin object.
//			Modify grade() to use result kept in object.
// Task 9.4. Modify program to use valid() to fully eliminate exception generation.
// Task 9.5. Modify class with functions to generate marks for students:
//			 -considered marks - midtern and final.
//			 -course passed if average grade is >60.
//			 -report students with ascending names, marks presented as course P(passed) / F(failed).
// Task 9.6. Modify program (by task 9.5.) to report course passed students, then - failed.

// Task 10.1. Rewrite program to output marks as 'A' to 'F'.
// Task 11.5. Instrument the 'Student_info' class to count how often objects are created, copied, assigned, and destroyed.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <exception>
#include "..\functions.h"

using namespace std;

class Student_info_class {
public:
	Student_info_class();
	Student_info_class(istream&);
	Student_info_class(const Student_info_class&);
	~Student_info_class();
	Student_info_class& operator=(const Student_info_class&);

	string name() const { return n; }
	bool valid() const { return !homework.empty(); }
	istream& read(istream&);
	double grade() const;
	bool passed() const; //Task 9.5.
	char final_grade_mark() const; //Task 10.1.

private:
	string n;
	double midterm, final;
	vector<double> homework;
	double final_grade; //Task 9.1.
	mutable bool _passed; //Task 9.6.
	// Task 11.5.
	static size_t created;
	static size_t copied;
	static size_t assigned;
	static size_t destroyed;
};

size_t Student_info_class::created = 0;
size_t Student_info_class::copied = 0;
size_t Student_info_class::assigned = 0;
size_t Student_info_class::destroyed = 0;

Student_info_class::Student_info_class(): midterm(0), final(0) { ++created; }
Student_info_class::Student_info_class(istream& is) { read(is); ++created; }
Student_info_class::Student_info_class(const Student_info_class& rhs): 
	n(rhs.n), midterm(rhs.midterm), final(rhs.final), homework(rhs.homework), final_grade(rhs.final_grade), _passed(rhs._passed) { ++copied; }
	
Student_info_class::~Student_info_class() { ++destroyed; }
Student_info_class& Student_info_class::operator=(const Student_info_class& rhs) {
	if (&rhs == this) return *this;
	++assigned;
	n = rhs.n;
	midterm = rhs.midterm;
	final = rhs.final;
	homework = rhs.homework;
	final_grade = rhs.final_grade;
	_passed = rhs._passed;

	return *this;
}

istream& Student_info_class::read(istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);
	if (valid()) final_grade = ::grade(midterm, final, homework); // Task 9.1. + Task 9.4.
	_passed = ((midterm + final)/2.0 > 60.0); // Task 9.6.
	return in;
}
double Student_info_class::grade() const
{
	// Excluded due to Task 9.1.
	//return ::grade(midterm, final, homework);
	return final_grade; // Task 9.1.
}

bool Student_info_class::passed() const
{
	// Reimplement due to task 9.6.
	// return ((midterm + final)/2.0 > 60.0); // Task 9.5.
	return _passed;
}

char Student_info_class::final_grade_mark() const
{
	static const char letters[] = { 'A', 'B', 'C', 'D', 'F' };
	static const double marks[] = { 90.0, 80.0, 70.0, 60.0, 0.0 };

	for (size_t i = 0; i < (sizeof(marks)/sizeof(*marks)); ++i)
	{
		if (final_grade > marks[i]) return letters[i];
	}
	return '?';
}

bool compare_class(const Student_info_class& x, const Student_info_class& y)
{
	return x.name() < y.name();
}

bool isPassed(const Student_info_class& x)
{
	return x.passed(); // Task 9.6.
}

int main()
{
	vector<Student_info_class> students;
	Student_info_class record;

	string::size_type maxlen = 0;

	while (record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare_class);
	
	for (vector<Student_info_class>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		} catch (domain_error& e) {
			cout << e.what() << endl;
		}
	}
	
	// Task 9.5.
	// Students already sorted by name. Only report here.
	for (vector<Student_info_class>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
		cout << "Course passed?: " << (students[i].passed()? "P" : "F") << endl;
	}

	// Task 9.6.
	partition(students.begin(), students.end(), isPassed); //Partitioning range: Passed, then Failed.
	for (vector<Student_info_class>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
		cout << "Course passed?: " << (students[i].passed()? "P" : "F") << endl;
		cout << "Letter mark: " << students[i].final_grade_mark() << endl; // Task 10.1.
	}
	
	return 0;
}

