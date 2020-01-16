#include <iostream>
#include "queue.h"


int queue::getanStelle(int k)
{

        int stelle = *head + k;
        return stelle;
}

int queue::getSize()
{
        return this->size;
}

bool queue::isEmpty()
{
        if (this->size == 0)
        {
            std::cout << "List is empty" << std::endl;
            return true;
        }
        else
        {
            std::cout << "List has elements" << std::endl;
            return false;
        }
    }


void queue::put(int v)
{
    if (tIndex == 49 && hIndex != 0)
    {

        tIndex = 0;
        tail = &arr[0];
    }
    if (tIndex + 1 == hIndex)
    {

        tail = &arr[0];
        head = &arr[0];
        length = 0;
        tIndex = 0;
        size = 0;
    }
    if (tIndex - 49 == hIndex)
    {
        tail = &arr[0];
        head = &arr[0];
        length = 0;
        tIndex = 0;
        size = 0;
    }

    *tail = v;
    std::cout << "Put:\t\t\t" << *tail << std::endl;
    *tail++;
    size++;
    length++;
    std::cout << "Array Index:\t\t" << tIndex << std::endl;
    tIndex++;
    std::cout << "leange: \t\t" << length << std::endl;
    std::cout << "Anzahl der Elemente:\t" << size << std::endl;

    std::cout << " " << std::endl;
    std::cout << "Pos h:\t\t\t" << hIndex << std::endl;
    std::cout << "Pos t:\t\t\t" << tIndex << std::endl;
    std::cout << " " << std::endl;
}

int queue::get()
{

    int r = *head;
    std::cout << "Get: \t\t\t" << r << std::endl;
    head = head + 1;
    length--;
    size--;
    std::cout << "leange:\t\t\t" << length << std::endl;
    std::cout << "Anzahl der Elemente:\t" << size << std::endl;
    std::cout << "Array Index:\t\t" << hIndex << std::endl;
    hIndex++;

    std::cout << " " << std::endl;

    return r;
}

int main()
{

    queue test;

    std::cout << "\n--- put elements ---\n"
              << std::endl;

    try
    {

        for (int i = 0; i < 40; i++)
        {
            test.put(i);
        }

        for (int j = 0; j < 20; j++)
        {
            test.get();
        }
        for (int i = 0; i < 60; i++)
        {
            test.put(i);
        }

        std::cout << test.getanStelle(5) << std::endl;

        std::cout << "\n"
                  << test.isEmpty() << std::endl;
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }
}
