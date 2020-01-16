#include <iostream>

namespace ip_test
{

void to_ip(std::string testIp, int *erg[4])
{

    int punkte = 0;
    int zahlen = 0;
    int zwi = 0;
    bool istIp = true;
    int loeBis = 0;
    std::string zwi2 = testIp;
    std::string zwiString = testIp;
    testIp += " ";

    for (int j = 0; j < 4; j++)
    {
        loeBis = zwi2.find('.') + 1;

        if (loeBis > 0)
        {
            zwi2 = zwi2.substr(loeBis, zwi2.length());
            punkte++;
        }
    }

    if (punkte == 3)
    {
        for (int i = 0; i < 4; i++)
        {
            zahlen = std::stoi(testIp);
            if ((zahlen <= 255) && (zahlen >= 0)) //Gültigkeitsbereich Prüfen
            {
                (*erg)[i] = zahlen; //Zahl in erg schreiben
                zwiString = std::to_string(zahlen);
                testIp = testIp.substr(zwiString.length() + 1, testIp.length()); //test ip 1. integer + . löschen
                std::cout << (*erg)[i] << std::endl;
            }
            else
            {
                throw "Keine IP";
            }
        }
    }
    else
    {
        throw "Keine IP";
    }

    std::cout << "" << std::endl;
}

} // namespace ip_test

int main()
{
    std::cout << "--- Aufgabe 3 ---" << std::endl;

    std::string testIp1 = "192.33.96.250";
    std::string testIp2 = "55.33.-32.250";
    std::string testIp3 = "213.33.0";
    std::string testIp4 = "525.0.0.1.0";

    int *spei1 = new int[4];
    int *spei2 = new int[4];
    int *spei3 = new int[4];
    int *spei4 = new int[4];

    try
    {
        ip_test::to_ip(testIp1, &spei1);
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }

    try
    {
        ip_test::to_ip(testIp2, &spei2);
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }

    try
    {
        ip_test::to_ip(testIp3, &spei3);
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }

    try
    {
        ip_test::to_ip(testIp4, &spei4);
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }
}

// for (int i = 0; i < 4; i++)
// {
//     std::cout << "Im Array spei1 steht an der " << i << ". Stelle " << spei1[i] << std::endl;
// }
// std::cout << std::endl;
// for (int i = 0; i < 4; i++)
// {
//     std::cout << "Im Array spei2 steht an der " << i << ". Stelle " << spei2[i] << std::endl;
// }
// std::cout << std::endl;

// for (int i = 0; i < 4; i++)
// {
//     std::cout << "Im Array spei3 steht an der " << i << ". Stelle " << spei3[i] << std::endl;
// }
// std::cout << std::endl;

// for (int i = 0; i < 4; i++)
// {
//     std::cout << "Im Array spei4 steht an der " << i << ". Stelle " << spei4[i] << std::endl;
// }