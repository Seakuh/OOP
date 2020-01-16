#ifndef schlange_h
#define schlange_h
class Queue
{

public:
    int* schlange;
    int size = 0;
    int tail = 0;
    int head = 0;
    int length = 0;

     //Konstruktor
    Queue(const int size);

    int getSize();
    int getanStelle(int j);  
    bool isEmpty();
    int get();
    void put(int v);
};
#endif