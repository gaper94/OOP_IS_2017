#include "ComplexNumber.h"
#include <iostream>
using namespace std;

int main()
{
    ComplexNumber cn1;
    ComplexNumber cn2(3, 4);
    cn1 += cn2;
    cout << cn1 << endl;
    cn1 -= ComplexNumber(3, 0);
    cout << cn1++ << endl;
    cout << (cn1 ^ 1) << endl;
    cout << boolalpha << "cn1 == cn2: " << (cn1 == cn2) << endl;
    cout << boolalpha << "cn2 != ComplexNumber(3, 4): " << (cn2 != ComplexNumber(3, 4)) << endl;
    return 0;
}
