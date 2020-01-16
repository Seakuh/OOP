#include <iostream>
using namespace std;
int gibInt(void);
void druckeInt(int);
class Punkt
{
    int x;
    int y;

public:
    Punkt(int x, int y) : x(x), y(y) {}

    friend void druckeInt(Punkt i);
    friend ostream &operator<<(ostream &os, const Punkt &i);
    friend int gibInt();
};
int gibInt()
{
    Punkt p(3, 4);
    return p.x + p.y;
}
void druckeInt(Punkt i)
{
    cout << i.x << i.y << endl;
}

ostream &operator<<(ostream &os, const Punkt &i)
{
    os << '(' << i.x << '|' << i.y << ')' ;
    return os;
}

int main()
{
    Punkt einPunkt(2, 8);
    cout << gibInt() << endl;

    druckeInt(einPunkt);
    cout << einPunkt << endl;
}