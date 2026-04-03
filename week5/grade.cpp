// grade.cpp
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include <vector>
#include <stdexcept>

// 중간시험 점수, 기말시험 점수, 종합 과제 점수에서
// 학생의 종합 점수를 가함
double grade(double mt, double ft, double hw) {
    return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}

// 중간시험 점수, 기말시험 점수, 과제 점수의 백터로
// 학생의 종합 점수를 가함.
// 이 함수는 인수를 복사하기 않고 median 함수가 해당 작업을 실행.
double grade(double mt, double ft, vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("No homework!");

    return grade(mt, ft, median(hw));
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info&) 
{
    return grade(s) < 60;
}
vector<Student_info> extract_fails(vector<Student_info>&)
{
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0;

    //불변성: students 백터의 [0,i) 범위에 있는
    //요소들은 과목을 통과한 학생들의 정보
    while (i != students.size())
    {
        if (fgrade(students[i]))
        {
            fail.push_back(students[i]);
            students.erase(students.begin() + i); //i번째 제거
        }
        else
        {
            i++;
        }
        
    }
    return fail;
}
