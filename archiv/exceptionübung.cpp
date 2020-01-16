#include <iostream>

int main(){

    int k;
    std::string test = "35345.3456345.45346k34634.34634";

    int gefunden = test.find('k');
    std::cout << gefunden << std::endl;


    test = test.substr(gefunden+1, test.length());

    std::cout << test << std::endl;


}