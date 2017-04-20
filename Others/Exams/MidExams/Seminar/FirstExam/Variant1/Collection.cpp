#include "Collection.h"
#include <iostream>
using namespace std;

Collection::Collection(const GramophoneRecord* records, size_t numberOfRecords)
    : records(nullptr)
{
    SetRecords(records, numberOfRecords);
}

Collection::Collection()
    : records(nullptr), numberOfRecords(0), recordsCapacity(0)
{
}

Collection::Collection(const Collection& other)
    : records(nullptr)
{
    SetRecords(other.records, other.numberOfRecords);
    resize(other.recordsCapacity);
}

Collection::~Collection()
{
    delete[] records;
}

const GramophoneRecord* Collection::GetRecords() const
{
    return records;
}
size_t Collection::GetNumberOfRecords() const
{
    return numberOfRecords;
}

void Collection::SetRecords(const GramophoneRecord* _records, size_t _numberOfRecords)
{
    delete[] records;
    if (_records != nullptr && _numberOfRecords > 0)
    {
        numberOfRecords = recordsCapacity = _numberOfRecords;
        records = new GramophoneRecord[numberOfRecords];
        for (size_t i = 0; i < numberOfRecords; i++)
        {
            records[i] = _records[i];
        }
        return;
    }
    records = nullptr;
    numberOfRecords = recordsCapacity = 0;
}

Collection& Collection::operator=(const Collection& rhs)
{
    if (this == &rhs) return *this;
    
    SetRecords(rhs.records, rhs.numberOfRecords);
    resize(rhs.recordsCapacity);
    return *this;
}

Collection& Collection::operator+=(const GramophoneRecord& newRecord)
{
    if (records == nullptr)
    {
        std::cout << "Trying to add new record, but recrods is nullptr!\n";
        return *this;
    }
    if ((numberOfRecords + 1) > numberOfRecords)
    {
        resize((numberOfRecords + 1) * 2);
    }
    records[numberOfRecords] = newRecord;
    numberOfRecords++;
    return *this;
}

void Collection::PrintByGenre(GramophoneRecord::Genre eGenre) const
{
	if (records == nullptr)
	{
		std::cout << "Trying to read nullptr!\n";
		return;
	}

	for (size_t i = 0; i < numberOfRecords; i++)
	{
		if (records[i].GetGenre() == eGenre)
		{
			std::cout << records[i] << endl;
		}
	}
}

const GramophoneRecord* Collection::FindByName(const char* name) const
{
	if (records == nullptr)
	{
		std::cout << "Trying to read nullptr!\n";
		return nullptr;
	}

	for (size_t i = 0; i < numberOfRecords; i++)
	{
		if (strcmp(name, records[i].GetAlbumName()) == 0)
		{
			return &records[i];
		}
	}
	return nullptr;
}

void Collection::ListenRecords(double time) const
{
	if (records == nullptr)
	{
		std::cout << "Trying to read nullptr!\n";
		return;
	}

	for (size_t i = 0; i < numberOfRecords; i++)
	{
		if (time > records[i].GetDuration())
		{
			cout << "Listening to :" << records[i] << endl;
			time -= records[i].GetDuration();
		}
	}
}

void Collection::resize(size_t capacity)
{
	recordsCapacity = capacity;
	if (records == nullptr)
	{
		records = new GramophoneRecord[recordsCapacity];
		return;
	}

	GramophoneRecord* temp = new GramophoneRecord[recordsCapacity];
	for (size_t i = 0; i < numberOfRecords; i++)
	{
		temp[i] = records[i];
	}
	delete[] records;
	records = temp;
}