#define _CRT_SECURE_NO_WARNINGS // uncomment for warning C4996

#include "Product.h"
#include "Student.h"
#include <iostream>

using namespace std;

int main()
{
    Product coke(Drinks, 1.20, 1.0, Date(2018, Date::January, 20));
    
    float grades[5] = { 4.0, 3.0, 6.0, 6.0, 5.0 };
    Student John("John", 1234567890, 12345, 3, grades, 5);
    cout << "John's average is: " << John.GetAverage() << endl;
    cout << "Adding new grade: 6" << endl;
    John.AddGrade(6.0);
    cout << "John's new average is: " << John.GetAverage() << endl;
    
    Student Jane("Jane", 987654310, 54321, 3);
    cout << "Jane adding new grade: 6" << endl;
    Jane.AddGrade(6.0);
    cout << "Jane's new average is: " << Jane.GetAverage() << endl;
    return 0;
}
