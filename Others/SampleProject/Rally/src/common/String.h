#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <cstring>
#include <utility>

namespace containers
{

using size_type = size_t;

template<typename CharT>
class basic_string
{
public:
	basic_string();
    basic_string(const CharT* s);
	basic_string(const basic_string& other);
    basic_string(basic_string&& other);
	~basic_string();
	//
	basic_string& operator=(basic_string rhs);
	CharT& operator[](size_type pos);
	const CharT& operator[](size_type pos) const;
	CharT* data();
	const CharT* data() const;
	//
	size_type size();
	size_type length();
	bool empty();
private:
	CharT* m_data;
	size_type m_size;
};

#include "String.hpp"

using String = basic_string<char>;

}
#endif // STRING_H
