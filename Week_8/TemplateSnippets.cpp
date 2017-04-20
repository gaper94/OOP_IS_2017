unsigned char max(unsigned char lhs, unsigned char rhs)
{
    return lhs > rhs ? lhs : rhs;
}

unsigned short max(unsigned short lhs, unsigned short rhs)
{
    return lhs > rhs ? lhs : rhs;
}

unsigned int max(unsigned int lhs, unsigned int rhs)
{
    return lhs > rhs ? lhs : rhs;
}

unsigned long long int max(unsigned long long int lhs, unsigned long long int rhs)
{
    return lhs > rhs ? lhs : rhs;
}

float max(float lhs, float rhs)
{
    return lhs > rhs ? lhs : rhs;
}

double max(double lhs, double rhs)
{
    return lhs > rhs ? lhs : rhs;
}

template<typename T>
inline T max(T lhs, T rhs)
{
    return lhs > rhs ? lhs : rhs;
}

#define MAX(a, b) a > b ? a : b

template<typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

#include <stddef.h>
template<typename T>
void sort(T* elems, size_t numberOfElemes)
{
    for (size_t i = 0; i < numberOfElemes - 1; i++)
    {
        bool swapped = false;
        for (size_t j = 0; j < numberOfElemes - 1 - i; j++)
        {
            if (elems[j] > elems[j + 1])
            {
                Swap(elems[j], elems[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}


template<typename T>
void customSort(T* elems, size_t numberOfElements, bool(*functor)(const T&, const T&))
//template<typename T>
//using comparator = bool(*)(const T&, const T&);
//template<typename T>
//void customSort(T* elems, size_t numberOfElemes, comparator<T> functor)
{
    for (size_t i = 0; i < numberOfElements - 1; i++)
    {
        bool swapped = false;
        for (size_t j = 0; j < numberOfElements - 1 - i; j++)
        {
            if (functor(elems[j], elems[j+1]))
            {
                Swap(elems[j], elems[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void oldswap(void** a, void** b)
{
    int temp = *(int*)(*a);
    *(int*)(*a) = *(int*)(*b);
    *(int*)(*b) = temp;
}

bool comp(void* a, void* b)
{
    int* pa = (int*)(a);
    int* pb = (int*)(b);
    return *pa > *pb;
}

//typedef bool(*comparator)(void*, void*);
void oldSort(void** elems, size_t numberOfElements, bool(*func)(void*, void*))
{
    for (size_t i = 0; i < numberOfElements - 1; i++)
    {
        bool swapped = false;
        for (size_t j = 0; j < numberOfElements - 1 - i; j++)
        {
            if(func(&elems[j], &elems[j]))
            {
                oldswap(&elems[j], &elems[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

class IntContainer
{
public:
    IntContainer();
    IntContainer(int*, size_t);
    IntContainer(const IntContainer&);
    IntContainer& operator=(const IntContainer&);

    void SetData(int*, size_t);
    const int* GetData() const;

    void pushBack(int);
    int getAt(size_t) const;

    void clear();
private:
    int* data;
    size_t size;
};

class ByteContainer
{
public:
    using Byte = unsigned char;
    ByteContainer();
    ByteContainer(Byte*, size_t);
    ByteContainer(const ByteContainer&);
    ByteContainer& operator=(const ByteContainer&);

    void SetData(Byte*, size_t);
    const Byte* GetData();

    void pushBack(Byte);
    Byte getAt(size_t) const;

    void clear();
private:
    Byte* data;
    size_t size;
};

template<typename T>
class Container
{
public:
    Container();
    Container(T*, size_t);
    Container(const Container&);
    Container& operator=(const Container&);

    void SetData(T*, size_t);
    const T* GetData();

    void pushBack(T);
    T getAt(size_t) const;

    void clear();
private:
    T* data;
    size_t size;
};

template<typename T, typename K>
struct Pair
{
    Pair(T _first, K _second) : first(_first), second(_second){}
    Pair() = default;
    Pair& operator=(const Pair&) = default;

    T first;
    K second;
};

template<typename T, class S>
class ContainerWithSize
{
public:
    using Byte = unsigned char;
    ContainerWithSize();
    ContainerWithSize(T*, S);
    ContainerWithSize(const ContainerWithSize&);
    ContainerWithSize& operator=(const ContainerWithSize&);

    void SetData(T*, S);
    const T* GetData();

    void pushBack(T);
    T getAt(S) const;

    void clear();
private:
    T* data;
    S size;
};

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

// C++11
//template<typename T, size_t N>
//constexpr size_t arraySize(T(&)[N]) noexcept
//{
//	return N;
//}

// C++98
template<typename T, size_t N>
size_t arraySize(T(&)[N])
{
    return N;
}

//size_t foo(int arr[10])
//{
//	return 10;
//}

#include <iostream>

// C++ 11
//template <int N>
//struct Factorial {
//	static constexpr int value = N * Factorial<N - 1>::value;
//};
//
//template <>
//struct Factorial<0> {
//	static constexpr int value = 1;
//};

// C++ 98
template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};

template <int N>
struct Sum {
    static const int value = N + Sum<N - 1>::value;
};

template <>
struct Sum<0> {
    static const int value = 1;
};

#include <fstream>
class FileWriter
{
public:
    FileWriter(const std::string& name = "") {};

    template<typename T>
    friend FileWriter& operator<<(FileWriter&, const T&);
private:
    std::fstream fs;
};

template<>
FileWriter& operator<<(FileWriter& fw, const int& rhs)
{
    fw.fs << rhs;
    return fw;
}

template<size_t N>
class Bitset
{
public:
    using Bit = bool;
    Bitset() : data() {}
    Bitset(unsigned int number)
    {
        int a = 1;
        for (size_t i = 0; i < N; i++)
        {
            data[i] = (a & number);
            a <<= 1;
        }
    }

    unsigned long long int asLongInt() const
    {
        unsigned long long int res = 0;
        int a = 1;
        for (size_t i = 0; i < N; i++)
        {
            if (data[i] == true)
            {
                res |= a;
            }
            a <<= 1;
        }
        return res;
    }
private:
    bool data[N];
};

template<typename T>
class CustomContainer
{
public:
    using Condition = bool(*)(const T&);
    CustomContainer(T* _data, size_t _size)
    {
        // ....
    }

    void removeAll(Condition cn)
    {
        for (size_t i = 0; i < GetSize(); i++)
        {
            if (cn(data[i]) == true)
            {
                removeAt(i);
            }
        }
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

    size_t GetSize() const
    {
        return size;
    }

private:
    void removeAt(size_t)
    {
        // ....
    }
    T* data;
    size_t size;

};

bool asc(const int& a, const int& b)
{
    return a > b;
}

bool desc(const int& a, const int& b)
{
    return a < b;
}

bool deleter(const int& el)
{
    return el > 10;
}

template<size_t N>
int get(int* arr)
{
    return arr[N];
}

int main()
{
    int aInt = 3;
    int* pa = &aInt;
    int b = 5;
    int* pb = &b;
    oldswap((void**)&pa, (void**)&pb);

    int arr[] = { 6, 1232, 543, 31243, 5435 };

    FileWriter fw;
    fw << 10;
    customSort(arr, arraySize(arr), desc);


    Bitset<sizeof(unsigned int) * 8> bs(14U);
    std::cout << bs.asLongInt();

    CustomContainer<int> fooCnt(nullptr, 0);
    fooCnt.removeAll
    (
            [](const int& el)
            {
                return el == 1;
            }
    );
    fooCnt.removeAll(deleter);

    auto a = get<0>(arr);
    return 0;
}
