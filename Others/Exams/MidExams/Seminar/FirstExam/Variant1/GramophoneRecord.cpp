#include "GramophoneRecord.h"

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

GramophoneRecord::GramophoneRecord( int _yearOfProduction,
                                    Genre _eGenre,
                                    const char* _artist,
                                    const char* _albumName,
                                    double _duration)
    : yearOfProduction(_yearOfProduction), eGenre(_eGenre),
      artist(nullptr), albumName(nullptr), duration(_duration)
{
    SetArtist(_artist);
    SetAlbumName(_albumName);
}
GramophoneRecord::GramophoneRecord()
    : yearOfProduction(0), eGenre(GramophoneRecord::Genre::None),
      artist(nullptr), albumName(nullptr), duration(0.0)
{
    SetArtist("");
    SetAlbumName("");
}
GramophoneRecord::GramophoneRecord(const GramophoneRecord& other)
    : yearOfProduction(other.yearOfProduction), eGenre(other.eGenre),
      artist(nullptr), albumName(nullptr), duration(other.duration)
{
    SetArtist(other.artist);
    SetAlbumName(other.albumName);
}

GramophoneRecord::~GramophoneRecord()
{
    delete[] artist;
    delete[] albumName;
}
GramophoneRecord& GramophoneRecord::operator=(const GramophoneRecord& rhs)
{
    if (this == &rhs) return *this;

    SetYearOfProduction(rhs.yearOfProduction);
    SetGenre(rhs.eGenre);
    SetArtist(rhs.artist);
    SetAlbumName(rhs.albumName);
    SetDuration(rhs.duration);
    return *this;
}

int GramophoneRecord::GetYearOfProduction() const
{
    return yearOfProduction;
}

GramophoneRecord::Genre GramophoneRecord::GetGenre() const
{
    return eGenre;
}

const char* GramophoneRecord::GetArtist() const
{
    return artist;
}

const char* GramophoneRecord::GetAlbumName() const
{
    return albumName;
}

double GramophoneRecord::GetDuration() const
{
    return duration;
}

void GramophoneRecord::SetYearOfProduction(int _yearOfProduction)
{
    yearOfProduction = _yearOfProduction;
}

void GramophoneRecord::SetGenre(Genre _eGenre)
{
    eGenre = _eGenre;
}

void GramophoneRecord::SetArtist(const char* _artist)
{
    delete[] artist;
    if (_artist != nullptr)
    {
        size_t len = strlen(_artist);
        if (len > 0)
        {
            artist = new char[len + 1];
            strcpy(artist, _artist);
            return;
        }
    }
    artist = new char[1];
    artist[0] = '\0';
}

void GramophoneRecord::SetAlbumName(const char* _albumName)
{
    delete[] albumName;
    if (_albumName != nullptr)
    {
        size_t len = strlen(_albumName);
        if (len > 0)
        {
            albumName = new char[len + 1];
            strcpy(albumName, _albumName);
            return;
        }
    }
    albumName = new char[1];
    albumName[0] = '\0';
}

void GramophoneRecord::SetDuration(double _duration)
{
    duration = _duration;
}

const char* GetGenreByName(GramophoneRecord::Genre eGenre)
{
    switch (eGenre)
    {
        case  GramophoneRecord::Genre::None:  return  "None";
        case  GramophoneRecord::Genre::Rock:  return  "Rock";
        case  GramophoneRecord::Genre::RnB:	  return  "RnB";
        case  GramophoneRecord::Genre::Metal: return  "Metal";
        case  GramophoneRecord::Genre::Pop:	  return  "Pop";
        case  GramophoneRecord::Genre::Blues: return  "Blues";
        default: return "?????";
    }
    

std::ostream& operator<<(std::ostream& os, const GramophoneRecord& rhs)
{
    os << "Year of production: " << rhs.yearOfProduction << ", "
       << "Genre: " << GetGenreByName(rhs.eGenre) << ", "
       << "Artist: " << rhs.artist << ", "
       << "Album name: " << rhs.albumName << ", "
       << "Duration: " << rhs.duration;
    return os;
}