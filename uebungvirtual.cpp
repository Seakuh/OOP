#include <iostream>
using namespace std;
class Base
{
public:
    virtual ~Base() { cout << "in Base destructor...\n"; }
    virtual void f() {}
};
class Sub : public Base
{
    int y;

public:
    virtual ~Sub() { cout << "in Sub destructor...\n"; }
    virtual void f() {}
};
int main()
{
    Base *b = new Sub;
    delete b;
    return 0;
}