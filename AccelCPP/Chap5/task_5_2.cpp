// task_5_2.cpp : Defines the entry point for the console application.
//
// Program to extract failing students using <vector> and <list> containers.
// Compare performance for vector and list solutions for students record sizes: 10, 1000 and 10000

#include "..\functions.h"
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

int main()
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

	vector<Student_info> students;
	
	try { students = studentGen(lenght);} //generate <lenght> dummy students with marks
	catch (domain_error& e) {cout << e.what();}
	
	list<Student_info> students_l(students.begin(), students.end());

	start = clock();
	vector<Student_info> failed_students_vector = extract_fails(students);
	end = clock();
	
	cout << "Vector based solution for " << lenght << " records took: " << (double)(end - start)/CLOCKS_PER_SEC << " seconds." << endl;
	
	start = clock();
	list<Student_info> failed_students_list = extract_fails(students_l);
	end = clock();

	cout << "List based solution for " << lenght << " records took: " << (double)(end - start)/CLOCKS_PER_SEC << " seconds." << endl;
}
