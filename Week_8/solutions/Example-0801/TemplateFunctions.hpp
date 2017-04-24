#ifndef TEMPLATE_FUNCTIONS_H
#define TEMPLATE_FUNCTIONS_H

namespace TemplateFunctions
{

template<typename T>
void copy(T* destination, const T* source, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}

template<typename T>
inline T max(T lhs, T rhs)
{
    return lhs > rhs ? lhs : rhs;
}

template<typename T>
T biggest(const T* source, size_t size)
{
    T ret = source[0];
    for (size_t i = 1; i < size; i++)
    {
        ret = max(source[i], ret);
    }
    return ret;
}

} // TemplateFunctions

#endif // TEMPLATE_FUNCTIONS_H