#include <iostream>
#include <random>

int main()
{
    std::cout << "Zufallszahlen-Test" << std::endl;

    std::random_device seed;

    std::mt19937 engine(seed());

    std::uniform_int_distribution<int> six(1, 6);

    for (int i = 0; i < 3; ++i)
    {
        std::cout << "\tdice[" << i << "]: " << six(engine) << std::endl;
    }


    std::cout << "Test end..." << std::endl;


}