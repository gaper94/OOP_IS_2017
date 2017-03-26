#ifndef MUSIC_ALBUM_H
#define MUSIC_ALBUM_H

#include "Song.h"

class MusicAlbum
{
public:
    MusicAlbum(Song* newSongs, size_t numberOfSongs);
    MusicAlbum(const MusicAlbum&);
    ~MusicAlbum();

    MusicAlbum& operator=(const MusicAlbum&);

    // Getters
    const Song* GetSongs() const;
    size_t GetNumberOfSongs() const;
    size_t GetCapacity() const;

    // Setters
    void SetSongs(const Song* newSongs, size_t newNumberOfSongs);
    void SetCapacity(size_t newCapacity);

    void AddSong(const Song&);
    void RemoveSongAtIdx(size_t);
    double TotalLength() const;
    size_t CountOfSongsOfGenre(Genre) const;
    size_t CountOfSongsOfArtist(const char*) const;

private:
    Song* songs;
    size_t numberOfSongs;
    size_t capacity;
};

#endif