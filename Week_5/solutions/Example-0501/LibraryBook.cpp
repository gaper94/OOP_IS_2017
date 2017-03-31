#include "LibraryBook.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

LibraryBook::LibraryBook( const char* newName,
                          const Person& auth,
                          const char* newISBN,
                          Genre newGenre,
                          double newPrice,
                          int newRenterId)
    : name(nullptr), author(auth), eGenre(newGenre), price(newPrice), renterId(newRenterId)
{
    SetName(newName);
    SetISBN(newISBN);
}

LibraryBook::LibraryBook(const LibraryBook& other)
    : name(nullptr)
{
    SetName(other.name);
    SetAuthor(other.author);
    SetISBN(other.ISBN);
    SetGenre(other.eGenre);
    SetPrice(other.price);
    SetRenterId(other.renterId);
}

LibraryBook::~LibraryBook()
{
    delete[] name;
}

LibraryBook& LibraryBook::operator=(const LibraryBook& rhs)
{
    if (this != &rhs)
    {
        SetName(rhs.name);
        SetAuthor(rhs.author);
        SetISBN(rhs.ISBN);
        SetGenre(rhs.eGenre);
        SetPrice(rhs.price);
        SetRenterId(rhs.renterId);
    }
    return *this;
}

const char* LibraryBook::GetName() const
{
    return name;
}

const Person& LibraryBook::GetAuthor() const
{
    return author;
}

const char* LibraryBook::GetISBN() const
{
    return ISBN;
}

LibraryBook::Genre LibraryBook::GetGenre() const
{
    return eGenre;
}

double LibraryBook::GetPrice() const
{
    return price;
}

int LibraryBook::GetRenterId() const
{
    return renterId;
}

void LibraryBook::SetName(const char* newName)
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

void LibraryBook::SetAuthor(const Person& newAuthor)
{
    author = newAuthor;
}

void LibraryBook::SetISBN(const char* newISBN)
{
    if (newISBN != nullptr)
    {
        if (strlen(newISBN) <= lenISBN)
        {
            strcpy(ISBN, newISBN);
        }
        else
        {
            cout << "Not enough storage for the new ISBN! - " << newISBN << endl;
        }
    }
    else
    {
        ISBN[0] = '\0';
    }
}

void LibraryBook::SetGenre(Genre newGenre)
{
    eGenre = newGenre;
}

void LibraryBook::SetPrice(double newPrice)
{
    price = newPrice;
}

void LibraryBook::SetRenterId(int newRenterId)
{
    renterId = newRenterId;
}

const char* LibraryBook::GetGenreAsString(LibraryBook::Genre eGenre)
{
    switch (eGenre)
    {
        case None:    return "None";
        case Fiction: return "Fiction";
        case Drama:   return "Drama";
        case Tragedy: return "Tragedy";
        case Fantasy: return "Fantasy";
        case Romance: return "Romance";
        default:      return "???????";
    }
}