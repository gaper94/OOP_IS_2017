#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#define _CRT_SECURE_NO_WARNINGS // Compiler error 4996
#include <stddef.h> // size_t

enum class ExercisesType
{
    Seminar,
    Praktikum
};

enum class GradePriority
{
    Low, // Homeworks
    High, // Midterm exams
};

struct Grade
{
    unsigned char value; // [0, 100]
    GradePriority ePriority;
    Grade& operator=(const Grade&) = default;
};

class GradeCalculator
{
public:
    GradeCalculator( const char* newStudentName,
                     ExercisesType newExercisesType,
                     Grade* newGrades,
                     size_t newNumberOfGrades);

    GradeCalculator(const GradeCalculator& other);
    ~GradeCalculator();

    GradeCalculator& operator=(const Grade&) = delete;

    // Getters
    const char* GetStudentName() const;
    ExercisesType GetExerciseType() const;
    const Grade* GetGrades() const;
    size_t GetNumberOfGrades() const;
    size_t GetGradesCapacity() const;

    // Setters
    void SetStudentName(const char* newStudentName);
    void SetExercisesType(ExercisesType newExerciseType);
    void SetGrades(Grade* newGrades, size_t newNumberOfGrades);
    void SetGradesCapacity(size_t newCapacity);

    // Grades functionality
    void PrintRequierements() const;
    void PrintGrade() const;
    void AddGrade(const Grade& newGrade);

private:
    char* studentName;
    ExercisesType eExercisesType;
    Grade* grades;
    size_t numberOfGrades;
    size_t gradesCapacity;
};

#endif // GRADE_CALCULATOR_H
