#include "Student.h"
#include <cstring>

Student::Student( const char* name,
                  int EGN,
                  int facultyNumber,
                  int course,
                  float* grades,
                  unsigned short size )
    : name(nullptr), grades(nullptr)
{
   SetName(name);
   SetEGN(EGN);
   SetFacultyNumber(facultyNumber);
   SetCourse(course);
   SetGrades(grades, size);
}

Student::~Student()
{
    delete[] name;
    delete[] grades;
}

void Student::SetName(const char* newName)
{
    delete[] name;
    if(name != nullptr)
    {
        int len = strlen(newName);
        if(len > 0 )
        {
            name = new char[len + 1];
            strcpy(name, newName);
        }
        else
        {
            name = new char[1];
            *name = '\0';
        }
    }
    else
    {
        name = new char[1];
        *name = '\0';
    }
}

const char* Student::GetName() const
{
    return name; 
}

void Student::SetEGN(int newEGN)
{
    EGN = newEGN;
}

int Student::GetEGN() const
{
    return EGN;
}

void Student::SetFacultyNumber(int newFacultyNumber)
{
    facultyNumber = newFacultyNumber;
}

int Student::GetFacultyNumber() const
{
    return facultyNumber;
}

void Student::SetCourse(int newCourse)
{
    course = newCourse;
}

int Student::GetCourse() const
{
    return course;
}

void Student::SetGrades(float* newGrades, unsigned short newNumberOfGrades)
{
    delete[] grades;
    if(newGrades != nullptr && newNumberOfGrades != 0)
    {
        numberOfGrades = newNumberOfGrades;
        grades = new float[numberOfGrades];
        for(unsigned short i = 0; i < numberOfGrades; i++)
        {
            grades[i] = newGrades[i];
        }
    }
    else
    {
        grades = nullptr;
        numberOfGrades = 0;
    }
}

const float* Student::GetGrades() const
{
    return grades;
}

unsigned short Student::GetNumberOfGrades() const
{
    numberOfGrades;
}

void Student::AddGrade(float newGrade)
{
    if(grades != nullptr)
    {
        // Try to think more optimal way of adding new grade ?
        float* oldMemory = grades; // Keep pointer to old memory
        grades = new float[numberOfGrades + 1]; // Plus one for the new grade
        for(int i = 0; i < numberOfGrades; i++)
        {
            grades[i] = oldMemory[i]; // Copy old data
        }
        grades[numberOfGrades] = newGrade; // Store new grade;
        numberOfGrades++; // We have one new grade
        delete[] oldMemory; // Release old memory
    }
    else
    {
        // No allocated memory, this will be the first grade
        grades = new float[1];
        numberOfGrades = 1;
        grades[0] = newGrade;
    }
}

double Student::GetAverage() const
{
    double average = 0.0;
    if(grades != nullptr && numberOfGrades != 0)
    {
        for(unsigned short i = 0; i < numberOfGrades; i++)
        {
            average += grades[i];
        }
        average /= numberOfGrades;
    }
    return average;
}
