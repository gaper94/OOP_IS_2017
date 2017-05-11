#include "Person.h"
#include <cstring>

using std::strlen;
using std::strcpy;

Person::Person()
{
	name = nullptr;
	egn[0] = '\0';
}

Person::Person(const char* name, const char egn[11])
{
	SetName(name);
	SetEGN(egn);
}

Person::Person(const Person& rhs)
{
	SetName(rhs.name);
	SetEGN(rhs.egn);
}

Person::~Person()
{
	delete[] name;
}

Person& Person::operator=(const Person& rhs)
{
	if (this != &rhs)
	{
		SetName(rhs.name);
		SetName(rhs.egn);
	}

	return *this;
}

void Person::SetName(const char* newName)
{
	delete[] name;
	name = new char[strlen(newName) + 1];
	strncpy(this->name, newName, 10);
}

const char* Person::GetName() const
{
	return name;
}

void Person::SetEGN(const char newEGN[])
{
	strcpy(egn, newEGN);
}

const char* Person::GetEGN() const
{
	return egn;
}
