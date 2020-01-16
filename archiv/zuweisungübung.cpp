#include <iostream>
using namespace std;

class Point
{
    const int x, y;

public:
    Point(int x, int y) : x(x), y(y) {}
    void print() { cout << "x=" << x << " y=" << y << endl; }
};
int main()
{
    Point aPoint(47, 11);
    Point otherPoint = aPoint;
    otherPoint.print();
}