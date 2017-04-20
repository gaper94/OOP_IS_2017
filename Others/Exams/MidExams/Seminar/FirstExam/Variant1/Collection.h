#ifndef COLLECTION_H
#define COLLECTION_H

#include "GramophoneRecord.h"

class Collection
{
public:
    // C-tors & D-tors
    Collection(const GramophoneRecord* records, size_t numberOfRecords);
    Collection();
    Collection(const Collection& other);
    ~Collection();
    
    // Getters
    const GramophoneRecord* GetRecords() const;
    size_t GetNumberOfRecords() const;

    // Setters
    void SetRecords(const GramophoneRecord* records, size_t numberOfRecords);

    // Overloaded operators
    Collection& operator=(const Collection& rhs);
    Collection& operator+=(const GramophoneRecord& newRecord);

    // Collection functionality
    void PrintByGenre(GramophoneRecord::Genre eGenre) const;
    const GramophoneRecord* FindByName(const char* name) const;
    void ListenRecords(double time) const;
private:
    void resize(size_t capacity);

    GramophoneRecord* records;
    size_t numberOfRecords;
    size_t recordsCapacity;
};
#endif // #COLLECTION_H