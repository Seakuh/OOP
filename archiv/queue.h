#ifndef queue
#define queue_h
class queue
{
public:
    int arr[50];
    int size = 0;
    int *head = &arr[0]; //Der Kopf zeigt auf das Array an der 0. Stelle
    int *tail = &arr[0]; //Das ende ist am Anfang auch 0. Stelle da arr leer ist
    int length = 0;
    int tIndex = 0;
    int hIndex = 0;

    void put(int v);
    int get();
    bool isEmpty();
    int getanStelle(int);
    int getSize();
};

#endif