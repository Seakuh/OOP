#include <iostream>

using namespace std;

class B
{
public:
    B() { cout << "In B" << endl; }
};
class B1 : public B
{
public:
    B1() { cout << "In B1" << endl; }
};
class B2 : public B
{
public:
    B2() { cout << "In B2" << endl; }
};
class D : public B1, public B2
{
public:
    D() { cout << "In D" << endl; }
};

int main()
{
    D d;
    return 0;
}
