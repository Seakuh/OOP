#include <iostream>

int main()
{

    int a = 123;

    int *b = &a;
    int *c = &a;

    *c = *c + 1;

    int *d;

    d = &a;

    std::cout << a << std::endl;
    std::cout << *d << std::endl;
    std::cout << *c << std::endl;

    std::cout << &a << std::endl;
    std::cout << &c << std::endl;
    std::cout << &d << std::endl;
}