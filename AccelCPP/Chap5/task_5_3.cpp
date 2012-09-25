// task_5_3.cpp : Defines the entry point for the console application.
//
// "typedef" used for implementation of vector- and list- based solutions.

#include "stdafx.h"
#include "..\..\..\functions.h"
#include <time.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <ios>
#include <iomanip>
#include <time.h>


using namespace std;

void test_containers_perf(int lenght);

typedef vector<Student_info> students_vector;
typedef list<Student_info> students_list;

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	
	test_containers_perf(10);
	test_containers_perf(1000);
	test_containers_perf(10000);

	return 0;
}

void test_containers_perf(int lenght)
{
	size_t start, end; //for clock ticks

	students_vector students;
	
	try { students = studentGen(lenght);} //generate <lenght> dummy students with marks
	catch (domain_error e) {cout << e.what();}
	
	students_list students_l(students.begin(), students.end());

	start = clock();
	vector<Student_info> failed_students_vector = extract_fails(students);
	end = clock();
	
	cout << "Vector based solution for " << lenght << " records took: " << (double)(end - start)/CLOCKS_PER_SEC << " seconds." << endl;
	
	start = clock();
	list<Student_info> failed_students_list = extract_fails(students_l);
	end = clock();

	cout << "List based solution for " << lenght << " records took: " << (double)(end - start)/CLOCKS_PER_SEC << " seconds." << endl;
}
