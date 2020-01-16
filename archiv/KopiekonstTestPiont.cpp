#include <iostream>

class Point
{
    int *c;
    int f();

public:
    Point(const Point &other) : Point(other.c[0], other.c[1])
    {
    }
    Point(const Point &other) = delete;

    Point(int x, int y)
    {
        c = new int[2];
        c[0] = x;
        c[1] = y;
    }
    int getX()
    {
        return c[0];
    }
    void setX(int x)
    {
        c[0] = x;
    }
    int getY()
    {
        return c[1];
    }
    int point::f(Point p)
    {
        return p.getX() + p.getY();
    }
};

int main()
{

    Point p(47, 11);
    int k = f(p);
    // Point p1(47, 11);
    // Point p2 = p1;
    // std::cout << p1.getX() << "    ";
    // p1.setX(23);
    // std::cout << p1.getX() << "\t" << p2.getX() << "\t" << p2.getX() << std::endl;
}