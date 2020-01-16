#include <iostream>
#include <array>
#include <random>
#include <map>

void increment(int &i)
{
    ++i;
}

int main()
{
    std::random_device seed;
    std::multimap<int, std::string> vorkommen;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<int> six(0, 9);
    std::map<std::string, int> buch;

    std::array<std::string, 10> words = {"Hei", "wie", "gehts", "Elefant", "T-Rex", "Regex", "Praktikum", "Schnee", "Publikum", "Festival"};

    std::cout << "---Textausgabe---" << std::endl;

    for (int i = 0; i < 100; i++)
    {
        std::string randword = words[six(engine)];
        buch[randword]++;
        std::cout << randword << " ";
    }
    std::cout << std::endl;
    std::cout << "---Anzahl unsortiert---" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << words[i] << ":\t\t" << buch[words[i]] << " mal enthalten" << std::endl;
    }

    for (auto elem : buch)
    {
        vorkommen.emplace(elem.second, elem.first);
    }

    std::cout << "---Alphabetisch sortiert---" << std::endl;

    for (std::map<std::string, int>::const_iterator i = buch.begin(); i != buch.end(); ++i)
    {
        std::cout << i->first << ":\t" << i->second << std::endl;
    }

    std::cout << "---Anzahl sortiert---" << std::endl;

    for (auto elem : vorkommen)
    {
        std::cout << elem.first << ":\t" << elem.second << std::endl;
    }

    return 0;
}