#include <utility>
#include "common/Vector.h"
#include "String.h"
#include <iostream>
using namespace std;

int main()
{
    int arr[3] = { 1, 2, 3 };
    containers::Vector<int> vec;
    int a = 5;
    vec.push_back(a);
    vec.push_back(std::move(a));
    vec.push_back(5);
    containers::String test("Hello");
    containers::String test_one(containers::String("Hello"));
    //cout << test.data() << endl;

    return 0;
}
