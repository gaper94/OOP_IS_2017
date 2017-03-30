#ifndef STRING_H
#define STRING_H

class String
{
public:
    String(const char*);
    String();
    String(const String& owner);
    ~String();
    String& operator=(const String&);

    // Getters
    const char* GetData() const;
    size_t GetLength() const;

    // Setters
    void SetData(const char*);
private:
    char* data;
    size_t length;
};
#endif