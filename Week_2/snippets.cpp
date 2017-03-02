#include <iostream>
#include <cstring>
using namespace std;

namespace Constants
{
// Defines
// No symbol with this name, replaced before compiling
// strange compiler error, no symbols during debugging
#define TXT_FIELD_LEN 20

// Constanats
// Entered in symbolic tables - during debugging and compiling
const int txtFieldLen = 20;
const int userNameLen = 20;

// Enum
enum PictureEffect // : type since C++11
{
    Sepia,
    Negativ,
    Retro,
    Sketch,
};

// Since C++11
enum class VideoEffect // : type optional
//ex. enum class VideoEffect : unsigned char
{
    Sepia,
    Negativ,
    Retro,
    Sketch,
};

}

// Defines don't resepct scope - once declared they have scope until symbol is undefined with #undef
// Class constants respect scopes
class Foo
{
public:
    static const int bar = 5; // static const declaration
    static const int chunky;
};

// Getting adress of static variables reqires definiton
const int Foo::bar;
const int Foo::chunky = 10;

// constant pointers
#define COURSE_NAME "OOP_IS_2016"
const char* courseName = "OOP_IS_2016"; // Pointer location can be changed
const char* const constCourseName = "OOP_IS_2016"; // Error when modifying pointer location

// Inline functions & Macros
#define MAX(a, b) a > b ? a : b

inline int intMax(int a, int b)
{
    return a > b ? a : b;
}

struct RGBPixel
{
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
};

class Bar
{
public:
    Bar(); // default c-tor
    Bar(const char* textField, int integerField = 0); // general purpose c-tor with default parameter
    Bar(int* integerField); // int* only c-tor

    char* GetTextField();
    int GetIntegerField();

    void SetTextField(const char* textField);
    void SetIntField(int);
protected:
private:
    static const int txtFieldLen = 20;
    char txtField[txtFieldLen+1];
    int intField;
};

Bar::Bar()
{
    SetTextField("");
    SetIntField(0);
}

Bar::Bar(const char* textField, int integerField)
{
    SetTextField(textField);
    SetIntField(integerField);
}

Bar::Bar(int* integerField)
{
    SetTextField("");
    SetIntField(*integerField);
}

char* Bar::GetTextField()
{
    return txtField;
}

int Bar::GetIntegerField()
{
    return intField;
}

void Bar::SetTextField(const char* textField)
{
    if(strlen(textField) > Bar::txtFieldLen)
    {
        std::cout << "No enough space to store the new string!\n";
        return;
    }
    strcpy(txtField, textField);
}

void Bar::SetIntField(int integerField)
{
    intField = integerField;
}
