#include "MusicAlbum.h"
#include <cstring>

#if __cplusplus < 201103L
#ifndef nullptr
#define nullptr NULL
#endif // nullptr
#endif // __cplusplus < 201103L

MusicAlbum::MusicAlbum(Song* newSongs, size_t numberOfSongs)
    : songs(nullptr)
{
    SetSongs(newSongs, numberOfSongs);
}

MusicAlbum::MusicAlbum(const MusicAlbum& other)
    : songs(nullptr)
{
    SetSongs(other.songs, other.numberOfSongs);
    SetCapacity(other.capacity);
}

MusicAlbum::~MusicAlbum()
{
    delete[] songs;
}

MusicAlbum& MusicAlbum::operator=(const MusicAlbum& rhs)
{
    if (this != &rhs)
    {
        SetSongs(rhs.songs, rhs.capacity);
        SetCapacity(rhs.capacity);
    }
    return *this;
}

const Song* MusicAlbum::GetSongs() const
{
    return songs;
}

size_t MusicAlbum::GetNumberOfSongs() const
{
    return numberOfSongs;
}

size_t MusicAlbum::GetCapacity() const
{
    return capacity;
}

void MusicAlbum::SetSongs(const Song* newSongs, size_t newNumberOfSongs)
{
    delete[] songs;

    if (newSongs != nullptr && newNumberOfSongs > 0)
    {
        capacity = numberOfSongs = newNumberOfSongs;
        songs = new Song[newNumberOfSongs];
        for (size_t i = 0; i < numberOfSongs; i++)
        {
            songs[i] = newSongs[i];
        }
    }
    else
    {
        songs = nullptr;
        numberOfSongs = 0;
        capacity = 0;
    }
}

void MusicAlbum::SetCapacity(size_t newCapacity)
{
    if (newCapacity > capacity)
    {
        capacity = newCapacity;
        Song* newSongs = new Song[capacity];
        for (size_t i = 0; i < numberOfSongs; i++)
        {
            newSongs[i] = songs[i];
        }
        delete[] songs;
        songs = newSongs;
    }
}

void MusicAlbum::AddSong(const Song& newSong)
{
    if ((numberOfSongs + 1) > capacity)
    {   // Not enough storage, allocate enough memory for the new song
        SetCapacity(numberOfSongs * 2);
    }
    songs[numberOfSongs] = newSong;
    numberOfSongs++;
}

void MusicAlbum::RemoveSongAtIdx(size_t idx)
{
    if (idx < numberOfSongs)
    {
        songs[idx] = Song();
    }
}

double MusicAlbum::TotalLength() const
{
    double totalLen = 0.0;
    for (size_t i = 0; i < numberOfSongs; i++)
    {
        totalLen += songs[i].GetDuration();
    }
    return totalLen;
}

size_t MusicAlbum::CountOfSongsOfGenre(Genre searchedGenre) const
{
    size_t countSongs = 0;
    for (size_t i = 0; i < numberOfSongs; i++)
    {
        if (songs[i].GetGenre() == searchedGenre)
        {
            countSongs++;
        }
    }
    return countSongs;
}

size_t MusicAlbum::CountOfSongsOfArtist(const char* Artist) const
{
    size_t countSongs = 0;

    if (Artist == nullptr)
    {
        return countSongs;
    }

    for (size_t i = 0; i < numberOfSongs; i++)
    {
        if (strcmp(songs[i].GetTitle(), Artist) == 0)
        {
            countSongs++;
        }
    }
    return countSongs;
}