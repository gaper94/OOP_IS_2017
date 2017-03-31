#ifndef PERSON_H
#define PERSON_H

#if __cplusplus < 201103L
typedef unsigned long long int uint64;
#else
using uint64 = unsigned long long int;
#endif // __cplusplus < 201103L

enum Gender
{
    None,
    Male,
    Female,
};

class Person
{
public:
    Person(const char* newName = "", uint64 newEGN = 0, Gender newGender = None);
    Person(const Person&);
    ~Person();

    Person& operator=(const Person&);

    // Getters
    const char* GetName() const;
    uint64 GetEGN() const;
    Gender GetGender() const;

    // Setters
    void SetName(const char*);
    void SetEGN(uint64);
    void SetGender(Gender);

private:
    char* name;
    uint64 EGN;
    Gender eGender;
};

#endif // PERSON_H