#ifndef Blatt3_Header_h
#define Blatt3_Header_h

template<class T> class Arraylist
{
private:
    T *arr;
    const int size = 0;

public:
    //Konstruktoren
    Arraylist(const int size1);
    Arraylist(const Arraylist &z);
    ~Arraylist();

    //Funktionen
    T get(int i) const;
    void set(int i, T number);

    //Operatoren
    double operator[](int k);
    friend bool operator==(const Arraylist<T> &diese, const Arraylist<T> &other);
    friend bool operator!=(const Arraylist &diese, const Arraylist &other);
    friend std::ostream &operator<<(std::ostream &os, const Arraylist &other);
};
#endif