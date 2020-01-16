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

    std::cout << "Der Vekor ist x: " << vektor.xWert << "\nDer Vekor ist y: " << vektor.yWert << std::endl;


}

