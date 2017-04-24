#include "TemplateFunctions.hpp"
#include "FixedSizeArray.hpp"
#include <iostream>

struct Point
{
    Point(double _x = 0.0, double _y = 0.0) 
    : x(_x), y(_y)
    {
    }

    bool operator>(const Point& rhs)
    {
        return x > rhs.x; // compare only on abscissa
    }

    bool operator<(const Point& rhs)
    {
        return x < rhs.x; // compare only on abscissa
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& rhs)
    {
        os << "(" <<rhs.x << ", " << rhs.y << ")";
        return os;
    }

    double x, y;
};

int main()
{
    int numbers[6] = { 0 };
    int otherNumbers[6] = { 6, 4325, 21, 321, 43, 231 };

    std::cout << "Before copy\n";
    for (size_t i = 0; i < 6; i++)
    {
        std::cout << numbers[i] << ", ";
    }
    std::cout << std::endl;

    TemplateFunctions::copy(numbers, otherNumbers, 6);

    std::cout << "After copy\n";
    for (size_t i = 0; i < 6; i++)
    {
        std::cout << numbers[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << "The biggest number is : " << TemplateFunctions::biggest(numbers, 6) << std::endl;
    Point points[]
    {
        { 1.0, 2.3 },
        { 2.0, 4.6 },
        { 1.9, 3.3 },
        { 2.8, 3.2 },
    };
    std::cout << "The biggest point is : " << TemplateFunctions::biggest(points, 4) << std::endl;

    Containers::FixedSizeArrayDynamic<int, 10> dynamicNumbers;
    for (size_t i = 0; i < 10; i++)
    {
        dynamicNumbers[i] = 34 - i;
    }

    std::cout << "Printing dynamicNumbers:\n";
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << dynamicNumbers[i] << ", ";
    }
    std::cout << std::endl;
    //Containers::FixedSizeArrayDynamic<int, 20> otherDynNumbers(dynNumbers); // Not compiling - FixedSizeArrayDynamic<int, 20> != FixedSizeArrayDynamic<int, 10>
    Containers::FixedSizeArrayDynamic<int, 10> otherDynamicNumbers(dynamicNumbers);
    Containers::FixedSizeArrayDynamic<int, 10> anotherDynamicNumbers;
    anotherDynamicNumbers = otherDynamicNumbers;
    std::cout << "Printing anotherDynamicNumbers:\n";
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << anotherDynamicNumbers[i] << ", ";
    }
    std::cout << std::endl;

    Containers::FixedcSizeArrayStatic<Point, 5> staticPoints;
    staticPoints[0] = { 2.0, 3.5  };
    staticPoints[1] = { 4.0, 1.3  };
    staticPoints[2] = { 1.0, 10.7 };
    staticPoints[3] = { 4.2, 2.23 };
    staticPoints[4] = { 3.9, 1.65 };

    std::cout << "Printing staticPoints:\n";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << staticPoints[i] << ", ";
    }
    std::cout << std::endl;

    Containers::FixedcSizeArrayStatic<Point, 5> otherStaticPoints(staticPoints);
    Containers::FixedcSizeArrayStatic<Point, 5> anotherStaticPoints;
    anotherStaticPoints = otherStaticPoints;
    std::cout << "Printing anotherStaticPoints:\n";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << anotherStaticPoints[i] << ", ";
    }
    std::cout << std::endl;

    Containers::CustomContainer<int> elements(numbers, 6);
    std::cout << "Number of elements bigger than 100: ";
    std::cout << elements.countif(
                                    [](const int& elem)
                                    {
                                        return elem > 100;
                                    }
                                ) << std:: endl;
    return 0;
}