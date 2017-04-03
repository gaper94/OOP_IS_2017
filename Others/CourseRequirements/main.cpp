#include "GradeCalculator.h"
#include <iostream>

int main()
{
    {
        Grade gradesSeminarSG[5] =
        {
            // Project grades
            { 100, GradePriority::Low }, // First iteration
            { 100, GradePriority::Low }, // Second iteration
            { 100, GradePriority::Low }, // Third iteration
            // Midterm exams
            { 100, GradePriority::High }, // First midterm exam
            { 100, GradePriority::High }, // Second midterm exam
        };
        GradeCalculator seminar("SG", ExercisesType::Seminar, gradesSeminarSG, sizeof(gradesSeminarSG) / sizeof(gradesSeminarSG[0]));
        seminar.PrintRequierements();
        seminar.PrintGrade();
    }

    std::cout << "\n";

    {
        Grade gradesPraktikumSG[7] =
        {
            // Homeworks grades
            { 100, GradePriority::Low }, // First homework
            { 100, GradePriority::Low }, // Second homework
            { 100, GradePriority::Low }, // Third homework
            { 100, GradePriority::Low }, // Fourth homework
            { 100, GradePriority::Low }, // Fifth homework
            // Midterm exams
            { 100, GradePriority::High }, // First midterm exam
            { 100, GradePriority::High }, // Second midterm exam
        };
        
        GradeCalculator praktikum("SG", ExercisesType::Praktikum, gradesPraktikumSG, sizeof(gradesPraktikumSG) / sizeof(gradesPraktikumSG[0]));
        praktikum.PrintRequierements();
        praktikum.PrintGrade();
    }
    return 0;
}
