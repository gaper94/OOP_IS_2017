#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

// Includes
#include "Person.h"

class LibraryBook
{
public:
    static const int lenISBN = 20;

    enum Genre
    {
        None,
        Fiction,
        Drama,
        Tragedy,
        Fantasy,
        Romance,
    };

    LibraryBook( const char* newName = "", 
                 const Person& auth = Person(),
                 const char* newISBN = "",
                 Genre newGenre = None, 
                 double newPrice = 0.0,
                 int newRenterId = -1);
    LibraryBook(const LibraryBook&);
    ~LibraryBook();

    LibraryBook& operator=(const LibraryBook&);

    // Getters
    const char* GetName() const;
    const Person& GetAuthor() const;
    const char* GetISBN() const;
    Genre GetGenre() const;
    double GetPrice() const;
    int GetRenterId() const;

    // Setters
    void SetName(const char*);
    void SetAuthor(const Person&);
    void SetISBN(const char*);
    void SetGenre(Genre);
    void SetPrice(double);
    void SetRenterId(int);

    static const char* GetGenreAsString(Genre);

private:
    char* name;
    Person author;
    char ISBN[lenISBN + 1];
    Genre eGenre;
    double price;
    int renterId;
};

#endif // LIBRARY_BOOK_H