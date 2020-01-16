#include <iostream>

class Point
{
    int x, y;

public:
    Point(int x = 0, int y = 0)
    {
        Point::x = x;
        Point::y = y;
        std::cout << "In constructor: " << x << "\t" << y << std::endl;
    }
};
class Segment
{
    Point p1, p2;

public:
    Segment(int x1, int y1, int x2, int y2)
    {
        p1 = Point(x1, y1);
        p2 = Point(x2, y2);
    }
};
int main()
{
    Segment s(4, 7, 1, 1);
    return 0;
}