#include <iostream>
using namespace std;
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
        cout << "x=" << x << " y=" << y << endl;
    }

    void change(Point &x)
    {
        x.x = 45;
        x.y = 34;
    }
    void change2()
    {
        this->x = 45;
        this->y = 34;
    }
    // ~point(){

    // }
};
int main()
{
    Point *p1 = new Point(1, 2);
    Point *p2 = new Point(1, 2);
    p2->change2();
    p2->print();
}