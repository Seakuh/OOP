#include <iostream>


int main(){

    int i=75;
    int *iz = NULL;
    iz = &i;

    std::cout << "i=" << i << std::endl;
    std::cout << "Die Variable i hat den Wert " << i << " und ist auf der Speicheradresse " << *iz << " abgelegt" << std::endl;

    *iz *= 2;

    std::cout << *iz << std::endl;
    std::cout << i << std::endl;

    double v[3] = { 1.1, 1.5, 2.4 };
    double* z=&v[0];
    std::cout << "v[0]=" << *z << std::endl;
    z = z+1;
    *z = 454;
    std::cout << "v[1]=" << *z << std::endl;
    z = z+1;
    std::cout << "v[2]=" << *z << std::endl;

    int u = 1, i12 = 2;
    int& w = u;
    w = i12;
    std::cout << u << " " << v[1] << "  "<< w <<"\n";







    return 0;
}