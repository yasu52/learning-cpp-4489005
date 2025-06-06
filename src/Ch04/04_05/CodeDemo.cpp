// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

int main(){
    float GPA = 0.0f;
    int id;
    
    std::vector<Student> students = {Student(1, "George P. Burdell"),
                                    Student(2, "Nancy Rhodes")};

    std::vector<Course> courses = {Course(1, "Algebra", 5),
                                Course(2, "Physics", 4),
                                Course(3, "English", 3),
                                Course(4, "Economics", 4)};

    std::vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                                Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    // Calculate the GPA for the selected student.
    float total_credits = 0.0f;
    for (int i = 0; i < grades.size(); i++) {
        int student_id = grades[i].get_student_id();
        if (id != student_id) continue;

        int target_course_id = grades[i].get_course_id();
        char grade = grades[i].get_grade();
        float grade_point;
        switch (grade) {
            case 'A':
                grade_point = 4.0f;
                break;
            case 'B':
                grade_point = 3.0f;
                break;
            case 'C':
                grade_point = 2.0f;
                break;
            case 'D':
                grade_point = 1.0f;
                break;
            case 'F':
                grade_point = 0.0f;
                break;
            default:
                grade_point = 0.0f;
                break;
        }
        for (int i = 0; i < courses.size(); i++){
            int course_id = courses[i].get_id();
            if (course_id == target_course_id) {
                GPA += (grade_point * courses[i].get_credits());
                total_credits += courses[i].get_credits();
            }
        }
    }
    GPA /= total_credits;

    std::string student_str;
    student_str = students[id-1].get_name(); // Change this to the selected student's name

    std::cout << "The GPA for " << student_str << " is " << GPA << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
