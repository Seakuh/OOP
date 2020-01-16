#include <iostream>
#include "letzteaufg copy.h"

int main()
{
    double k = 50;
    double j = 0.5;
    Arraylist<double> neu = Arraylist<double>(k);
    Arraylist<double> vergleich = Arraylist<double>(7);

    Arraylist<double> zuweisen = Arraylist<double>(7);
    Arraylist<double> zuweisen1 = Arraylist<double>(7);
    Arraylist<float> zuweisen3 = Arraylist<float>(7);

    //Zuweisungsoperator Test

    try
    {
        for (int i = 0; i < 7; i++)
        {
            zuweisen.set(i, i);
        }
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    };

    std::cout << zuweisen1 << std::endl;

    zuweisen1 = zuweisen;

    std::cout << "Zuweisen Test" << std::endl;

    std::cout << zuweisen << std::endl;

    std::cout << zuweisen1 << std::endl;


}
