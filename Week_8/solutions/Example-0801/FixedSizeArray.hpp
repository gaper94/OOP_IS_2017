#ifndef FIXED_SIZE_ARRAY_H
#define FIXED_SIZE_ARRAY_H

#include "TemplateFunctions.hpp"

namespace Containers
{

// Dynamic allocation version
template<typename T, size_t N>
class FixedSizeArrayDynamic
{
public:
    FixedSizeArrayDynamic()
        : data(new T[N])
    {
    }

    FixedSizeArrayDynamic(const FixedSizeArrayDynamic& other)
    {
        data = new T[N];
        TemplateFunctions::copy(data, other.data, N);
    }

    FixedSizeArrayDynamic& operator=(const FixedSizeArrayDynamic& rhs)
    {
        if (this == &rhs) return *this;

        delete[] data;
        data = new T[N];
        TemplateFunctions::copy(data, rhs.data, N);
        return *this;
    }

    ~FixedSizeArrayDynamic()
    {
        delete[] data;
    }

    T& operator[](size_t idx)
    {
        return data[idx];
    }

    size_t size() const
    {
        return N;
    }
private:
    T* data;
};

// Static version
template<typename T, size_t N>
class FixedcSizeArrayStatic
{
public:
    FixedcSizeArrayStatic()
        : data()
    {
    }

    FixedcSizeArrayStatic(const FixedcSizeArrayStatic& other)
    {
        TemplateFunctions::copy(data, other.data, N);
    }

    FixedcSizeArrayStatic& operator=(const FixedcSizeArrayStatic& rhs)
    {
        if (this == &rhs) return *this;

        TemplateFunctions::copy(data, rhs.data, N);
        return *this;
    }

    ~FixedcSizeArrayStatic() = default;

    T& operator[](size_t idx)
    {
        return data[idx];
    }

    size_t size() const
    {
        return N;
    }
private:
    T data[N];
};

template<typename T>
class CustomContainer
{
public:
    using Condition = bool(*)(const T&);
    CustomContainer() 
        : data(nullptr), size(0)
    {
    }

    CustomContainer(T* source, size_t _size)
    {
        data = new T[size];
        size = _size;
        TemplateFunctions::copy(data, source, size);
    }

    bool find(Condition cn)
    {
        for (size_t i = 0; i < GetSize(); i++)
        {
            if (cn(data[i]) == true)
            {
                return true;
            }
        }
        return false;
    }

    size_t countif(Condition cn)
    {
        size_t cnt = 0;
        for (size_t i = 0; i < GetSize(); i++)
        {
            if (cn(data[i]) == true)
            {
                cnt++;
            }
        }
        return cnt;
    }

    const T* GetData() const
    {
        return data;
    }

    size_t GetSize() const
    {
        return size;
    }

private:
    T* data;
    size_t size;

};

} // Containers

#endif // FIXED_SIZE_ARRAY_H