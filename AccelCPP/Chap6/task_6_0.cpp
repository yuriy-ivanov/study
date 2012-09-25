// task_6_0.cpp : Defines the entry point for the console application.
//
// Original source from book (failing students)

#include "stdafx.h"
#include "..\..\functions.h"
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Student_info> did, didnt;

	// Task 6.7. - Func to read and separate students by whether all homework done or not.
	// Moving commented part to func and call it.
	
	//Student_info student;

	//while (read(cin, student)) {
	//	if (did_all_hw(student))
	//		did.push_back(student);
	//	else 
	//		didnt.push_back(student);
	//}

	//if (did.empty()) {
	//	cout << "No one student did complete any of homework!" << endl;
	//	return 1;
	//}

	//if (didnt.empty()) {
	//	cout << "All of students did homework!" << endl;
	//	return 1;
	//}

	read_and_separate(did, didnt); // Call to func (Task 6.7.)

	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	// Task 6.5. - Write "optimistic_median_analysis" function
	write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt); 
	

	// Task 6.6. - Now using common_analysis func
	common_write_analysis(cout, "median", grade_aux, did, didnt);
	common_write_analysis(cout, "aerage", average_grade, did, didnt);
	common_write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);

	//Task 8.1. - Write template function parametrized by final grade function type.
	//Use this new function.
	common_write_analysis_g(cout, "median", grade_aux, did, didnt);

	return 0;
}

