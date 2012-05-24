#ifndef GUARD_functions
#define GUARD_functions

//functions.h

#include <iostream>
#include <string>
#include <vector>
#include <list>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
	double final_grade;
};

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(const Student_info& s);
double median(const std::vector<double>&);
double average(const std::vector<double>&);
bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::istream& cread(std::istream&, std::vector<std::string>&);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);
std::vector<std::string> split(const std::string&);
std::string::size_type width(const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string> vcat(const std::vector<std::string>&, const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&, const std::vector<std::string>&);
void output(std::ostream& os, const std::vector<std::string>&);
std::string randomStrGen(int);
std::vector<Student_info> studentGen(int);
bool is_palindrome(const std::string&);
bool has_asc_desc(const std::string&);

#endif
