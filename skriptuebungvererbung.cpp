#include <iostream>
using namespace std;
class Base
{
public:
    virtual ~Base() { cout << "in Base destructor...\n"; }
    virtual void f()
    {
        cout << "ich bin die f funktion" << endl;
    }
};
class Sub : public Base
{
    int y = 324;

public:
    virtual ~Sub() { cout << "in Sub destructor...\n"; }
    virtual void f()
    {
        cout << y << endl;
    }
};

int main()
{
    Base *b = new Sub;

    b->f();

    delete b;

    return 0;
}