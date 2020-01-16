#include <iostream>
#include <string>

class Point
{
    int x;
    int y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    void print()
    {
        std::cout << "x=" << x << " y=" << y << std::endl;
    }

    Point &add(const Point &other)
    {
        Point *result = new Point(x + other.x, y + other.y);
        return *result;
    }
    friend std::ostream& operator<<(std::ostream& os, const Point& course)
    {
        os << course.x; //etc..
        return os;
    }
};

main()
{
    Point p(47, 11);
    auto q = p;
    std::cout << p << " " << q << " " << p.add(q) << std::endl;
}