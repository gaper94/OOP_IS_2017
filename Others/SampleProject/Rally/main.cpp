#include "common/Vector.h"
#include <utility>

int main()
{
    int arr[3] = { 1, 2, 3 };
    containers::Vector<int> vec;
    int a = 5;
    vec.push_back(a);
    vec.push_back(std::move(a));
    vec.push_back(5);

    return 0;
}