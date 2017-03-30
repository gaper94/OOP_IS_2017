#include <cstring>
#include <iostream>
using namespace std;

#ifndef nullptr
#define nullptr NULL
#endif

// Begin String.h
#include <iostream>
#include <cmath>
#include <algorithm>
class String
{
private:
    char* _string;
    size_t _size;
    // int _size;
public:
    String(const char*);
    //String(const char*, size_t);
    String();
    ~String();

    // Getters
    const char* GetString() const;
    size_t GetSize() const;

    // Setters
    void SetString(const char*);
    //void SetSize(size_t);

    // private:
    void copy(const String&);
    void destroy();
};
// End String.h

// Begin String.cpp
String::String(const char* str)
    : _string(nullptr)
{
    SetString(str);
}

String::String()
    : _string(nullptr)
{
    SetString("");
}

String::~String()
{
    delete[] _string;
}

void String::SetString(const char* str)
{
    delete[] _string;
    if(str != nullptr)
    {
        int len = strlen(str);
        if(len > 0 )
        {
            _string = new char[len + 1];
            _size = len;
            strcpy(_string, str);
        }
        else
        {
            _string = new char[1];
            _size = 0;
            *_string = '\0';
        }
    }
    else
    {
        _string = new char[1];
        _size = 0;
        *_string = '\0';
    }
}

size_t String::GetSize() const
{
    return _size;
}

const char* String::GetString() const
{
    return _string;
}

// End String.cpp

// Begin Song.h
class Song
{
public:
    Song(String _title = "", String _artist = "")
    {
        title = _title;
        artist = _artist;
    }

    //Song(const String& _title = "", const String& _artist = "");

    void SetTitle(String newTitle)
    {
        title = newTitle;
    }

    String GetTitle() const
    {
        return title;
    }

    void SetArtist(const String& newTitle)
    {
        title = newTitle;
    }

    const String& GetArtist() const
    {
        return title;
    }
private:
    String title;
    String artist;
};

// End Song.h

int main()
{
    // String examples
    String artist("Foo Figters");
    String songName("The pretender");
    Song pretender(artist, songName);
    {
        Song copySong = pretender;
    }

    {
        String name = pretender.GetArtist();
    }

    songName.destroy();
    songName.SetString("New value");

    // Празен низ

    // Грешно
    //   char* data = nullptr
    //   size_t size = 0

    //   char* data = new char[0]
    //   size_t size = 0

    //   char* data;
    //   strcpy(data, "")
    //   size_t size = 0

    // Правилно
    //   char* data = new char[1];
    //   data[0] = '\0'
    //   size_t size = 0

    //   char* data = new char[1];
    //   strcpy(data, "\0")
    //   size_t size = 0

    // Enum examples
    enum PictureEffect
    {
        Sepia = 1,
        Negativ = 2,
        Blur = 1
    };

    PictureEffect currentEffect = Blur;
    if(currentEffect == Sepia)
    {
        cout << "Sepia" << endl;
    }
    else if(currentEffect == Negativ)
    {
        cout << "Negativ" << endl;
    }
    else if(currentEffect == Blur)
    {
        cout << "Blur" << endl;
    }
    else
    {
        cout << "Undefined effect" << endl;
    }
    return 0;
}
