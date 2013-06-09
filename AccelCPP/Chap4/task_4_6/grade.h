#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h

#include <vector>
#include "Student_info.h"

namespace task46 {

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
//double grade(const task46::Student_info&);

}

#endif
