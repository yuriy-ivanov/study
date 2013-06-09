#ifndef GUARD_Student_info
#define GUARD_Student_info

//Student_info.h

#include <iostream>
#include <string>
#include <vector>

namespace task46 {

struct Student_info {
	std::string name;
	//double midterm, final;
	//std::vector<double> homework;
	double final_grade;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

}

#endif
