#include "GradeCalculator.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

#define SEMINAR_REQUIERMENTS \
        "1. Two mid-exams, coefficent 2.5\n" \
        "2. Project, separated in three iterations, each with coefficent 1\n"

const char* PraktikumRequirements = 
        "1. Two mid-exams, with coefficent 2.5\n"
        "2. Five homeworks, with coefficent 1\n";

GradeCalculator::GradeCalculator( const char* newStudentName,
                                  ExercisesType newExercisesType,
                                  Grade* newGrades,
                                  size_t newNumberOfGrades)
    : studentName(nullptr), eExercisesType(newExercisesType), grades(nullptr), numberOfGrades(newNumberOfGrades)
{
    SetStudentName(newStudentName);
    SetGrades(newGrades, numberOfGrades);
}

GradeCalculator::GradeCalculator(const GradeCalculator& other)
    : studentName(nullptr), eExercisesType(other.eExercisesType), grades(nullptr), numberOfGrades(other.numberOfGrades)
{
    SetStudentName(other.studentName);
    SetGrades(other.grades, other.numberOfGrades);
    SetGradesCapacity(other.gradesCapacity);
}

GradeCalculator::~GradeCalculator()
{
    delete[] studentName;
    delete[] grades;
}

const char* GradeCalculator::GetStudentName() const
{
    return studentName;
}

ExercisesType GradeCalculator::GetExerciseType() const
{
    return eExercisesType;
}

const Grade* GradeCalculator::GetGrades() const
{
    return grades;
}

size_t GradeCalculator::GradeCalculator::GetNumberOfGrades() const
{
    return numberOfGrades;
}

size_t GradeCalculator::GetGradesCapacity() const
{
    return gradesCapacity;
}

void GradeCalculator::SetStudentName(const char* newStudentName)
{
    delete[] studentName;
    if(newStudentName != nullptr)
    {
        size_t len = strlen(newStudentName);
        if(len != 0)
        {
            studentName = new char[len + 1];
            strcpy(studentName, newStudentName);
            return;
        }
    }

    studentName = new char[1];
    studentName[0] = '\0';
}

void GradeCalculator::SetExercisesType(ExercisesType newExerciseType)
{
    eExercisesType = newExerciseType;
}

void GradeCalculator::SetGrades(Grade* newGrades, size_t newNumberOfGrades)
{
    delete[] grades;
    if(newGrades != nullptr && numberOfGrades != 0)
    {
        numberOfGrades = gradesCapacity = newNumberOfGrades;
        grades = new Grade[numberOfGrades];
        for(size_t i = 0; i < numberOfGrades; i++)
        {
            grades[i] = newGrades[i];
        }
    }
    else
    {
        grades = nullptr;
        numberOfGrades = gradesCapacity = 0;
    }
}

void GradeCalculator::SetGradesCapacity(size_t newCapacity)
{
    if(newCapacity > gradesCapacity && grades != nullptr)
    {
        gradesCapacity = newCapacity;
        Grade* newGrades = new Grade[gradesCapacity];
        for(size_t i = 0; i < numberOfGrades; i++)
        {
            newGrades[i] = grades[i];
        }
        delete[] grades;
        grades = newGrades;
    }
}

void GradeCalculator::PrintRequierements() const
{
    switch(eExercisesType)
    {
        case ExercisesType::Seminar:
        {
            std::cout << SEMINAR_REQUIERMENTS;
            break;
        }
        case ExercisesType::Praktikum:
        {
           std::cout << PraktikumRequirements;
           break;
        }
        default:
        {
           std::cout << "Invalid exercises type!!\n";
           break;
        }
    }
}

void GradeCalculator::PrintGrade() const
{
    switch(eExercisesType)
    {
        case ExercisesType::Seminar:
        case ExercisesType::Praktikum:
        {
            size_t sumOfGrades = 0;
            size_t divisor = 0;
            for(size_t i = 0; i < numberOfGrades; i++)
            {
                switch(grades[i].ePriority)
                {
                    case GradePriority::Low:
                    default:
                    {
                        sumOfGrades += grades[i].value * 10;
                        divisor += 10;
                        break;
                    }
                    
                    case GradePriority::High:
                    {
                        sumOfGrades += grades[i].value * 25;
                        divisor += 25;
                        break;
                    }
                }
                sumOfGrades += grades[i].value; 
            }
            break;
        }
        default:
        {
           std::cout << "Unknown exercises type!\n";
           break;
        }
    }
}

void GradeCalculator::AddGrade(const Grade& newGrade)
{
    if( (numberOfGrades + 1) > gradesCapacity )
    {
        SetGradesCapacity(gradesCapacity * 2);
    }

    grades[numberOfGrades] = newGrade;
    numberOfGrades++;
}


