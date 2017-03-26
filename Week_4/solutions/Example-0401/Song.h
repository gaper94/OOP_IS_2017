#ifndef SONG_H
#define SONG_H

enum Genre
{
    None,
    Rock,
    Metal,
    Pop,
    Folk,
};

class Song
{
public:
    Song(const char* Title = "", const char* Author = "", Genre songGenre = None, double duration = 0.0);
    Song(Song&);
    ~Song();

    Song& operator=(const Song&);

    // Getters
    const char* GetTitle() const;
    const char* GetAuthor() const;
    Genre GetGenre() const;
    double GetDuration() const;
    
    // Setters
    void SetTitle(const char*);
    void SetAuthor(const char*);
    void SetGenre(Genre);
    void SetDuration(double);

private:
    char* title;
    char* author;
    Genre eGenre;
    double duration;
};

#endif