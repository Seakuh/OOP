#include "DynamicInt.h"
#include <iostream>
namespace hfu
{
DynamicInt::DynamicInt(int number)
{
    pointer = new int;
    *pointer = number;
}

DynamicInt::DynamicInt(const DynamicInt &z)
{
    pointer = new int;
    *pointer = *z.pointer;
}

DynamicInt::~DynamicInt()
{
    delete pointer;
}
int DynamicInt::get() const 
{
    return *pointer;
}

int negative(DynamicInt dynamicInt)
{
    return -dynamicInt.get();
}
} // namespace hfu

int main()
{
    hfu::DynamicInt di1(-4711);
    std::cout << "Get di1:\t\t" << di1.get() << "\n";
    std::cout << "Get di1(negative):\t" << hfu::negative(di1) << "\n";

    hfu::DynamicInt di2(23);
    std::cout << "Get di2:\t\t" << di2.get() << "\n";
    std::cout << "Get di2(negative):\t" << hfu::negative(di2) << "\n";

    std::cout << "Get di1 2nd:\t\t" << di1.get() << "\n";
    std::cout << "Get di1 2nd(negative):\t" << hfu::negative(di1) << "\n";

    std::cout << "Get di2 2nd:\t\t" << di2.get() << "\n";
    std::cout << "Get di2 2nd(negative):\t" << hfu::negative(di2) << "\n";
    return 0;
}