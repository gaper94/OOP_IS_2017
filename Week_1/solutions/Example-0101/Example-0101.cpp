#include <cmath>
#include <iostream>
using namespace std;

struct Point
{
    double x;
    double y;

    // b)
    double distanceTo(const Point& otherPoint)
    {
        return sqrt(pow(x - otherPoint.x, 2) + pow(y - otherPoint.y, 2));
    }
};

// a)
double distanceTwoPoints(const Point& p1, const Point& p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main()
{
    Point p1;
    p1.x = 1.0;
    p1.y = 2.0;
    Point p2 = { 3.0, 2.0 };
    cout << "Distance between p1 and p2 is: " << distanceTwoPoints(p1, p2) << endl;
    cout << "Distance from p1 to p2 is: " << p1.distanceTo(p2);
    return 0;
}