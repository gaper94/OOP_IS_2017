#include <cmath>
#include <iostream>
using namespace std;

namespace CommonDefinitions
{
    struct Point
    {
        double x;
        double y;

        double distanceTo(const Point& otherPoint)
        {
            return sqrt(pow(x - otherPoint.x, 2) + pow(y - otherPoint.y, 2));
        }
    };
}

namespace Structures
{
    using namespace CommonDefinitions;

    struct Rectangle
    {
        Point topLeft;
        Point bottomRight;
    };

    // a)
    double rectWidth(const Rectangle& rec)
    {
        // Translate bottomRight point to have the same y coordinate
        // as topLeft (build the top right point of the rectangle)
        Point tr = rec.bottomRight;
        tr.y = rec.topLeft.y;

        return tr.distanceTo(rec.topLeft);
    }

    // b)
    double rectHeight(const Rectangle& rec)
    {
        // Translate bottomRight point to have the same x coordinate
        // as topLeft (build the bottom left point of the rectangle)
        Point tr = rec.bottomRight;
        tr.x = rec.topLeft.x;

        return tr.distanceTo(rec.topLeft);
	}

    // c)
    bool isSquare(const Rectangle& rec)
    {
        return rectWidth(rec) == rectHeight(rec);
    }
}

// d)
namespace Classes
{
    class Rectangle
    {
    public:
        void SetTopLeft(const CommonDefinitions::Point& topLeft)
        {
            m_topLeft = topLeft;
        }

        void SetBottomRight(const CommonDefinitions::Point& bottomRight)
        {
            m_bottomRight = bottomRight;
        }

        CommonDefinitions::Point GetTopLeft()
        {
            return m_topLeft;
        }

        CommonDefinitions::Point GetBottomRight()
        {
            return m_bottomRight;
        }

        double GetWidth()
        {
            CommonDefinitions::Point tr = m_bottomRight;
            tr.y = m_topLeft.y;
            return tr.distanceTo(m_topLeft);
        }

        double GetHeight()
        {
            CommonDefinitions::Point tr = m_bottomRight;
            tr.x = m_topLeft.x;
            return tr.distanceTo(m_topLeft);
        }

        bool IsSquare()
        {
            return GetWidth() == GetHeight();
        }

    private:
        CommonDefinitions::Point m_topLeft;
        CommonDefinitions::Point m_bottomRight;
    };

}

int main()
{
    // Structures
    Structures::Rectangle rec = { {0, 10}, {5, 0} }; // Using initiliser list
    cout << "The width of rec is : " << Structures::rectWidth(rec) << endl;

    Structures::Rectangle rec2;
    rec2.topLeft     = { 0, 10 };
    rec2.bottomRight = { 15, 0 };
    cout << "The height of rec2 is : " << Structures::rectHeight(rec2) << endl;
    cout << "rec2 " << (Structures::isSquare(rec2) ? "is " : " isnt ") << "square\n";

    // Classes
    using namespace Classes;
    Rectangle cRec;
    CommonDefinitions::Point topL = { 0, 10 };
    CommonDefinitions::Point bottomR = { 10, 0 };
    cRec.SetTopLeft(topL);
    cRec.SetBottomRight(bottomR);
    cout << "The width of cRec is: " << cRec.GetWidth() << endl;

    Rectangle cRec2;
    cRec2.SetTopLeft({ 0, 10 });
    cRec2.SetBottomRight({ 0, 10 });
    cout << "The height of cRec2 is: " << cRec.GetHeight() << endl;
    cout << "cRec2 " << (cRec2.IsSquare() ? "is " : "isnt ") << "square\n";

    return 0;
}