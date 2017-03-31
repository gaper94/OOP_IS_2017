#include "Person.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>

#if __cplusplus < 201103L
#ifndef nullptr
#define nullptr NULL
#endif // nullptr
#endif // __cplusplus < 201103L

Person::Person(const char* newName, uint64 newEGN, Gender newGender)
: name(nullptr), EGN(newEGN), eGender(newGender)
{
    SetName(newName);
}

Person::Person(const Person& rhs)
    : name(nullptr), EGN(rhs.EGN), eGender(rhs.eGender)
{
    SetName(rhs.name);
}

Person::~Person()
{
    delete[] name;
}

Person& Person::operator = (const Person& rhs)
{
    if (this != &rhs)
    {
        SetName(rhs.name);
        EGN = rhs.EGN;
        eGender = rhs.eGender;
    }
    return *this;
}

const char* Person::GetName() const
{
    return name;
}

uint64 Person::GetEGN() const
{
    return EGN;
}

Gender Person::GetGender() const
{
    return eGender;
}

void Person::SetName(const char* newName)
{
    delete[] name;
    if (newName != nullptr)
    {
        size_t len = strlen(newName);
        if (len != 0)
        {
            name = new char[len + 1];
            strcpy(name, newName);
            return;
        }
    }

    // In all other cases make empty string
    name = new char[1];
    name[0] = '\0';
}

void Person::SetEGN(uint64 newEGN)
{
    EGN = newEGN;
}

void Person::SetGender(Gender newGender)
{
    eGender = newGender;
}