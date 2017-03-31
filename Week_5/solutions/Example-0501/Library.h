#ifndef LIBRARY_H
#define LIBRARY_H

#include "LibraryBook.h"
#include "Person.h"

class Library
{
public:
    Library( const LibraryBook* books,
             size_t newNumberOfBooks,
             const Person* users,
             size_t newNumberOfUsers,
             double startBalance);
    Library(const Library&);
    ~Library();

    Library& operator=(const Library&);

    // Getters
    const LibraryBook* GetBooks() const;
    size_t GetNumberOfBooks() const;
    size_t GetBooksCapacity() const;
    
    const Person* GetUsers() const;
    size_t GetNumberOfUsers() const;
    size_t GetUsersCapacity() const;

    static double GetUserTax();
    double GetCurrentBalance() const;
    
    // Setters
    void SetBooks(const LibraryBook* newBooks, size_t newNumberOfBooks);
    void SetBooksCapacity(size_t newCapacity);

    void SetUsers(const Person* newUsers, size_t newNumberOfUsers);
    void SetUsersCapacity(size_t newCapacity);

    void AddBook(const LibraryBook&);
    void AddUser(const Person&);
    void RentBook(const Person&, const LibraryBook&);
    void ReturnBook(const LibraryBook&);
    void RegisterLostBook(const LibraryBook&);
    void PrintInfoForAllBooksRentedByUser(const Person&);

private:
    LibraryBook* books;
    size_t numberOfBooks;
    size_t booksCapacity;

    Person* users;
    size_t numberOfUsers;
    size_t usersCapaciy;

    static const double userTax;
    double currentBalance;
};

#endif // LIBRARY_H