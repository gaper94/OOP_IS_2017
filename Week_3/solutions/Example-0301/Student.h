#ifndef STUDENT_H
#define STUDENT_H

#if __cplusplus < 201103L
#ifndef nullptr
#define nullptr NULL
#endif
#endif

class Student
{
public:
    Student( const char* name = "",
             int EGN = 0,
             int facultyNumber = 0,
             int course = 0,
             float* grades = nullptr,
             unsigned short size = 0 );
    ~Student();

    void SetName(const char*);
    const char* GetName() const;

    void SetEGN(int);
    int GetEGN() const;

    void SetFacultyNumber(int);
    int GetFacultyNumber() const;

    void SetCourse(int);
    int GetCourse() const;

    void SetGrades(float*, unsigned short);
    const float* GetGrades() const;

    unsigned short GetNumberOfGrades() const;
    void AddGrade(float);
    double GetAverage() const;

private:
    char* name;
    int EGN;
    int facultyNumber;
    int course;
    float* grades;
    unsigned short numberOfGrades;
};

#endif // STUDENT_H 
