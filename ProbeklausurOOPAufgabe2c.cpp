#include <iostream>
using namespace std;
class Punkt
{
    int x;
    int y;

public:
    Punkt(int x) : x(x), y(0)
    {
        cout << "Punktkonstruktor\n";
    }
    friend void druckePunkt(const Punkt &);
};

void druckePunkt(const Punkt &p)
{
    cout << "x=" << p.x << " y=" << p.y << endl;
}

int main()
{
    druckePunkt(3);
    return 0;
}