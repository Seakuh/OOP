#include <iostream>


    namespace ip_test {

    void to_ip(std::string testIp, int* erg[4]){
   
    int punkte = 0;
    int zahlen = 0;
    int zwi = 0;
    int loeBis = 0;
    std::string zwi2 = testIp;
    std::string zwiString = testIp;
    testIp += " ";
    for(int j= 0; j<3;j++){
        loeBis = zwi2.find('.')+1;
        if(loeBis > 0){
            zwi2.substr(loeBis,zwi2.length());
            punkte++;

        }
    }

    std::cout << punkte  << "Punkte bei for schleife" << std::endl;


    if(punkte==3){
        for(int i = 0; i<4; i++){
            zahlen = std::stoi(testIp);
            if ((zahlen <= 255) && (zahlen >= 0)){
                (*erg)[i] = zahlen;
                zwiString = std::to_string(zahlen);
                testIp = testIp.substr(zwiString.length() + 1, testIp.length());
            }else{
                  throw "ist keine IP";
                }
        }
    }else{
        throw "ist keine IP";
    }

    
}
    }

    //Aufgabe 1
    
    //a

    void ausgabeInteger(){
    int a;             
    
    std::cout << "Geben Sie eine Zahl ein" << std::endl;
    std::cin >> a;
    std::cout << a << " wurde eingegeben" << std::endl;
    }

    //b

    void ausgabeZweiInteger(){ 
    int b1, b2;

    std::cout << "Geben Sie zwei Zahlen ein (Eingabe -> Enter -> 2.Eingabe -> Enter) " << std::endl;
    std::cin >> b1 >> b2;;
    std::cout << b1 << " und " << b2 << " wurden eingegeben" << std::endl;
    }

    //c 

    void ausgabeIntegerZahl(){

    int c;
    char c1;

    std::cout << "Geben Sie eine Zahl und einen Charakter ein (Eingabe -> Enter -> 2.Eingabe -> Enter) " << std::endl;
    std::cin >> c >> c1;
    std::cout << c << " und " << c1 << " wurden eingegeben" << std::endl;
    }

    //d

    void ausgabeCharFloat(){

    float d;
    char d1;

    std::cout << "Geben Sie eine Kommazahl und einen Charakter ein (Eingabe -> Enter -> 2.Eingabe -> Enter) " << std::endl;
    std::cin >> d >> d1;
    std::cout << d << " und " << d1 << " wurden eingegeben" << std::endl;
    }

    //e

    void ausgabeString(){

    std::string e;

    std::cout << "Geben Sie einen Text ein " << std::endl;
    std::getline(std::cin, e);
    std::cout << e << " wurde eingegeben " << std::endl;

    }


    //Aufgabe 2

    //a

int gcd_iterative(int a, int b){

    a = abs(a);
    b = abs(b);

    if(a==0 && b==0){
        throw "A und B darf nicht 0 sein";
    }
    

        if (b == 0)
        {
            return a;
        }

        while (b != 0)
        {
            if (a > b)
            {
                a -= b;
            }
            else
            {
                b -= a;
            }
        }

        return a;
}

//b

int gcd_rekrusive(int a, int b)
{

    a = abs(a);
    b = abs(b);

    if(a==0 && b==0){
        throw "A und B darf nicht 0 sein";
    }
    
    if(b == 0){
        return 0;
    }
  

    if (b != 0)
    {  
        if (b < a)
        {
            return gcd_rekrusive(b, a);
        }
        else
        {
            return gcd_rekrusive(a, b - a);
        }
    }
    else
    {
        return a;
    }
}

//e

void reduce(int& a, int& b){

    if(b == 1){
        std::cout << a << std::endl;
        }else if((a<0)^(b<0)){

            int r =gcd_iterative(a,b);

            std::cout << a << " / " << b << " = ";
            std::cout << "-" << a/r << " / " << abs(b/r) << std::endl;
            }else if((a<0)&&(b<0)){
                std::cout << a << " / " << b << " = ";
                std::cout << abs(a) << " / " << abs(b) << " = " <<  std::endl;

            }
            else{

            int k =gcd_iterative(a,b);

            std::cout << a << " / " << b << " = ";
            std::cout << a/k << " / " << b/k << std::endl;
            }
}

//Aufgabe 3




int main()
{
    // std::cout << "--- Aufgabe 1 ---" << std::endl;    
    // //ausgabeInteger();
    // //ausgabeZweiInteger();
    // //ausgabeCharFloat();
    // //ausgabeString();

    // //Aufgabe 2
    // std::cout << "--- Aufgabe 2 ---" << std::endl;

    // //e

    // int a = -5;
    // int b = -10;
    // for( int i = 0; i<10; i++){
    // a += i;
    // b += i*2;
    // reduce(a, b);
    // std::cout << std::endl;
    // }

    // //Aufgabe 3

    std::cout << "--- Aufgabe 3 ---" << std::endl;

    std::string testIp1 = "192.33.96.250";
    std::string testIp2 = "1923.33.96.250";
    std::string testIp3 = "192.33.96.250.454";
    std::string testIp4 = "192.133.96.250";

    
    int* spei1 = new int[4];
    int* spei2 = new int[4];
    int* spei3 = new int[4];
    int* spei4 = new int[4];

    try{
    ip_test::to_ip(testIp1, &spei1);
    ip_test::to_ip(testIp2, &spei2);
    ip_test::to_ip(testIp3, &spei3);
    ip_test::to_ip(testIp4, &spei4);
    }catch(const char* e){
        std::cout << e << std::endl;
    }

    std::cout << "  " << std::endl;

    for(int i= 0; i<4; i++){
       std::cout << "Im Array spei1 steht an der " << i << ". Stelle "<< spei1[i] << std::endl;
    }
    std::cout << std::endl;
    for(int i= 0; i<4; i++){
       std::cout << "Im Array spei2 steht an der " << i << ". Stelle "<< spei2[i] << std::endl;
    } 
    std::cout << std::endl;

    for(int i= 0; i<4; i++){
       std::cout << "Im Array spei3 steht an der " << i << ". Stelle "<< spei3[i] << std::endl;
    }  
    std::cout << std::endl;
 
    for(int i= 0; i<4; i++){
       std::cout << "Im Array spei4 steht an der " << i << ". Stelle "<< spei4[i] << std::endl;
    }


}