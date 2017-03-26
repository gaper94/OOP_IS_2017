#include "Song.h"
#define _CRT_SECURE_NO_WARNINGS // uncomment for warning C4996
#include <cstring>

#if __cplusplus < 201103L
#ifndef nullptr
#define nullptr NULL
#endif // nullptr
#endif // __cplusplus < 201103L

Song::Song(const char* Title, const char* Author, Genre songGenre, double duration)
    : title(nullptr), author(nullptr)
{
    SetTitle(Title);
    SetAuthor(Author);
    SetGenre(songGenre);
    SetDuration(duration);
}

Song::Song(Song& other)
    : title(nullptr), author(nullptr)
{
    SetTitle(other.title);
    SetAuthor(other.author);
    SetGenre(other.eGenre);
    SetDuration(other.duration);
}

Song::~Song()
{
    delete[] title;
    delete[] author;
}

Song& Song::operator=(const Song& rhs)
{
    if (this != &rhs)
    {
        SetTitle(rhs.title);
        SetAuthor(rhs.author);
        SetGenre(rhs.eGenre);
        SetDuration(rhs.duration);
    }
    return *this;
}

const char* Song::GetTitle() const
{
    return title;
}

const char* Song::GetAuthor() const
{
    return author;
}

Genre Song::GetGenre() const
{
    return eGenre;
}

double Song::GetDuration() const
{
    return duration;
}

void Song::SetTitle(const char* newTitle)
{
    delete[] title;
    if (newTitle != nullptr)
    {
        size_t len = strlen(newTitle);
        if (strlen(newTitle) != 0)
        {
            title = new char[len + 1];
            strcpy(title, newTitle);
        }
        else
        {
            title = new char[1];
            title[0] = '\0';
        }
    }
    else
    {
        title = new char[1];
        title[0] = '\0';
    }
}

void Song::SetAuthor(const char* newAuthor)
{
    delete[] author;
    if (newAuthor != nullptr)
    {
        size_t len = strlen(newAuthor);
        if (strlen(newAuthor) != 0)
        {
            author = new char[len + 1];
            strcpy(author, newAuthor);
        }
        else
        {
            author = new char[1];
            author[0] = '\0';
        }
    }
    else
    {
        author = new char[1];
        author[0] = '\0';
    }
}

void Song::SetGenre(Genre newGenre)
{
    eGenre = newGenre;
}

void Song::SetDuration(double newDuration)
{
    duration = newDuration;
}