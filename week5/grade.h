#pragma once
// grade.h

#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"

using std::vector;;//추가

double grade(double, double, double);
double grade(double, double, vector<double>&);
double grade(const Student_info&);

bool fgrade(const Student_info&);
vector<Student_info> extract_fails(vector<Student_info>&)

#endif
