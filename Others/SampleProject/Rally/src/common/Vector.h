#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <utility>

namespace containers
{

using size_type = size_t;

template<typename T>
class Vector
{
public:
    //
    Vector();
    Vector(const T* data, size_type size);
    Vector(const Vector& other);
    Vector(Vector&& other);
    //
    Vector& operator=(Vector rhs);
    //
    void push_back(const T& value);
    void push_back(T&& value);
    //
    T* data();
    const T* data() const;
    T& operator[](size_type idx);
    const T& operator[](size_type idx) const;
    //
    size_type size() const;
    size_type capacity() const;
    bool empty() const;
    //
    void resize(size_type count);
    void clear();
private:
    T* m_data;
    size_type m_size;
    size_type m_capacity;
    
};

#include "Vector.hpp"

} // containers

#endif // VECTOR_H
