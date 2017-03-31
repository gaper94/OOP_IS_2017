#include "Library.h"
#include <iostream>
using namespace std;

// Static members definition
const double Library::userTax = 20.0;

Library::Library( const LibraryBook* books,
                  size_t newNumberOfBooks,
                  const Person* users,
                  size_t newNumberOfUsers,
                  double startBalance)
    : books(nullptr), users(nullptr), currentBalance(startBalance)
{
    SetBooks(books, newNumberOfBooks);
    SetUsers(users, newNumberOfUsers);
}

Library::Library(const Library& other)
    : books(nullptr), users(nullptr), currentBalance(other.currentBalance)
{
    SetBooks(other.books, other.numberOfBooks);
    SetBooksCapacity(other.booksCapacity);
    SetUsers(other.users, other.numberOfUsers);
    SetUsersCapacity(other.usersCapaciy);
}

Library::~Library()
{
    delete[] books;
    delete[] users;
}

Library& Library::operator=(const Library& rhs)
{
    if (this != &rhs)
    {
        SetBooks(rhs.books, rhs.numberOfBooks);
        SetUsers(rhs.users , rhs.numberOfUsers);
    }
    return *this;
}

const LibraryBook* Library::GetBooks() const
{
    return books;
}

size_t Library::GetNumberOfBooks() const
{
    return numberOfBooks;
}

size_t Library::GetBooksCapacity() const
{
    return booksCapacity;
}

const Person* Library::GetUsers() const
{
    return users;
}

size_t Library::GetNumberOfUsers() const
{
    return numberOfUsers;
}

size_t Library::GetUsersCapacity() const
{
    return usersCapaciy;
}

double Library::GetUserTax()
{
    return userTax;
}

double Library::GetCurrentBalance() const
{
    return currentBalance;
}

void Library::SetBooks(const LibraryBook* newBooks, size_t newNumberOfBooks)
{
    delete[] books;
    if (newBooks != nullptr && newNumberOfBooks != 0)
    {
        booksCapacity = numberOfBooks = newNumberOfBooks;
        books = new LibraryBook[numberOfBooks];
        for (size_t i = 0; i < numberOfBooks; i++)
        {
            books[i] = newBooks[i];
        }
    }
    else
    {
        books = nullptr;
        usersCapaciy = numberOfBooks = 0;
    }
}

void Library::SetBooksCapacity(size_t newCapacity)
{
    if (newCapacity > booksCapacity)
    {
        booksCapacity = newCapacity;
        LibraryBook* newBooks = new LibraryBook[booksCapacity];
        for (size_t i = 0; i < numberOfBooks; i++)
        {
            newBooks[i] = books[i];
        }
        delete[] books;
        books = newBooks;
    }
}

void Library::SetUsers(const Person* newUsers, size_t newNumberOfUsers)
{
    delete[] users;
    if (newUsers != nullptr && newNumberOfUsers != 0)
    {
        usersCapaciy = numberOfUsers = newNumberOfUsers;
        users = new Person[numberOfUsers];
        for (size_t i = 0; i < numberOfUsers; i++)
        {
            users[i] = newUsers[i];
        }
    }
    else
    {
        users = nullptr;
        usersCapaciy = numberOfUsers = 0;
    }
}

void Library::SetUsersCapacity(size_t newCapacity)
{
    if (newCapacity > usersCapaciy)
    {
        usersCapaciy = newCapacity;
        Person* newUsers = new Person[usersCapaciy];
        for (size_t i = 0; i < numberOfUsers; i++)
        {
            newUsers[i] = users[i];
        }
        delete[] users;
        newUsers = users;
    }
}

void Library::AddBook(const LibraryBook& newBook)
{
   if (newBook.GetPrice() > currentBalance)
   {
       cout << "Not enough balance to buy this book! ISBN: " << newBook.GetISBN() << endl;
       return;
   }

   // First subtract book price from current balance
   currentBalance -= newBook.GetPrice();

   // Check if enough storage for the new book
   if ( (numberOfBooks + 1) >= booksCapacity)
   {   // Not enough storage, allocate memory for the new book
       SetBooksCapacity(booksCapacity * 2);
   }

   // Add new book
   books[numberOfBooks] = newBook;
   numberOfBooks++;
}

void Library::AddUser(const Person& newUser)
{
    // First add tax for the new user
    currentBalance += userTax;

    // Check if enough storage for the new user
    if ( (numberOfUsers + 1) >= usersCapaciy)
    {   // Not enough storage, allocate memory for the new user
        SetUsersCapacity(usersCapaciy * 2);
    }

    // Add new user
    users[numberOfUsers] = newUser;
    numberOfUsers++;
}

void Library::RentBook(const Person& renter, const LibraryBook& rentedBook)
{
    bool bookIsFound = false;
    size_t bookIndex = 0;
    for (size_t i = 0; i < numberOfBooks; i++)
    {
        if (strcmp(books[i].GetISBN(), rentedBook.GetISBN()) == 0)
        {
            bookIndex = i;
            bookIsFound = true;
            break;
        }
    }

    if (bookIsFound == false)
    {
        return; // This book is not present in the library
    }

    // Set renter id for the book
    for (size_t i = 0; i < numberOfUsers; i++)
    {
        if (users[i].GetEGN() == renter.GetEGN())
        {
            books[bookIndex].SetRenterId(i);
            break;
        }
    }
}
void Library::ReturnBook(const LibraryBook& rentedBook)
{
    for (size_t i = 0; i < numberOfBooks; i++)
    {
        if (strcmp(books[i].GetISBN(), rentedBook.GetISBN()) == 0)
        {
            books[i].SetRenterId(-1);
            break;
        }
    }
}

void Library::RegisterLostBook(const LibraryBook& lostBook)
{
    for (size_t i = 0; i < numberOfBooks; i++)
    {
        if (strcmp(books[i].GetISBN(), lostBook.GetISBN()) == 0)
        {
            books[i] = LibraryBook();
            break;
        }
    }
}

void Library::PrintInfoForAllBooksRentedByUser(const Person& renter)
{
    // First check if user is from this library
    size_t userIndex = 0;
    bool userIsFound = false;
    for (size_t i = 0; i < numberOfUsers; i++)
    {
        if (users[i].GetEGN() == renter.GetEGN())
        {
            userIndex = i;
            userIsFound = true;
            break;
        }
    }

    if (false == userIsFound)
    {
        cout << "No such user in the library!" << endl;
        return;
    }

    cout << "Books rented by " << renter.GetName() << endl;
    int counter = 1;
    for (size_t i = 0; i < numberOfBooks; i++)
    {
        if (books[i].GetRenterId() == userIndex)
        {
            cout << "Book[" << counter++
                << "]: ISBN: " << books[i].GetISBN()
                << ", Name: " << books[i].GetName()
                << ", Genre: " << LibraryBook::GetGenreAsString(books[i].GetGenre())
                << ", Price: " << books[i].GetPrice() << endl;
        }
    }
}