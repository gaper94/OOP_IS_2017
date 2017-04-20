#ifndef GRAMOPHONE_RECORD_H
#define GRAMOPHONE_RECORD_H

#include <iosfwd>

class GramophoneRecord
{
public:
    enum class Genre
    {
        None,
        Rock,
        RnB,
        Metal,
        Pop,
        Blues,
    };

    // C-tors & D-tors
    GramophoneRecord( int yearOfProduction,
                      Genre eGenre,
                      const char* artist,
                      const char* albumName,
                      double duration );
    GramophoneRecord();
    GramophoneRecord(const GramophoneRecord& other);
    ~GramophoneRecord();
    GramophoneRecord& operator=(const GramophoneRecord& rhs);

    // Getters
    int GetYearOfProduction() const;
    Genre GetGenre() const;
    const char* GetArtist() const;
    const char* GetAlbumName() const;
    double GetDuration() const;

    // Setters
    void SetYearOfProduction(int yearOfProduction);
    void SetGenre(Genre eGenre);
    void SetArtist(const char* artist);
    void SetAlbumName(const char* albumName);
    void SetDuration(double duration);

    friend std::ostream& operator<<(std::ostream& os, const GramophoneRecord& rhs);
private:
    int yearOfProduction;
    Genre eGenre;
    char* artist;
    char* albumName;
    double duration;
};
#endif // GRAMOPHONE_RECORD_H