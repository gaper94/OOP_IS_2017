#ifndef _PERSON_H_
#define _PERSON_H_

class Person
{
public:
	Person();
	Person(const char* name, const char egn[11]);
	Person(const Person& rhs);
	~Person();
	Person& operator=(const Person& rhs);

	void SetName(const char* newName);
	const char* GetName() const;

	void SetEGN(const char newEGN[11]);
	const char* GetEGN() const;

private:
	char* name;
	char egn[11];
};

#endif
