#include <iostream>


class zahl
{
public:
    int xWert;
    int yWert;
    int zWert;


    zahl vektor(zahl zweiD);
    int addierenX(zahl b);
};

zahl zahl::vektor(zahl zweiD)
{
    zahl vek;

    vek.xWert = zweiD.xWert - xWert ;
    vek.yWert = zweiD.yWert - yWert ; 

    return vek;
}

int zahl::addierenX(zahl b){
    int erg = 0;

    erg = xWert + b.yWert;
}


int main(){

    zahl a;
    zahl b; 

    b.xWert = 5;
    b.yWert = 8;

    a.xWert = 3;
    a.yWert = 4;

    zahl vektor = a.vektor(b);

    std::cout << " /\t" << vektor.xWert << " \t" << (char)92 << std::endl;
    std::cout << "|\t\t" << " |" << std::endl;
    std::cout << " " <<(char)92 << "\t" << vektor.yWert << "\t" << "/" << std::endl;


}

