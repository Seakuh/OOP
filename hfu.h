#ifndef hfu
#define hfu_h
#include <string>
#include <iostream>

namespace hfu
{

class Book
{

private:
    //Atribute von der Klasse book
    const std::string buchTitel;
    const std::string autor;
    const std::string anschaffungsDatum;
    bool status;
    //Funktionen der Klasse book oeffentlich
public:
    std::string getBuchTitel() const;
    std::string getAutor() const;
    std::string getAnschaffungsDatum() const;
    std::string getStatus() const;
    std::string getToday() const;
    void dump() const;
    void setStatus(bool av);
    void changeAutor(std::string autor);

    //Konstruktoren der Klasse book
    Book();
    Book(const char *autor, const char *titel);
    Book(const char *autor, const char *titel, const char *datum);
    Book(const char *autor, const char *titel, const char *datum, bool status);
};

template <class T>
bool find(const T *arr, const int size, const T &key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }
    return false;
}

//ArrayList -----------------------------------------------------------------------------------------

template <class T, int size>
class Arraylist
{
private:
    T *arr;
    //int size = 0;

public:
    Arraylist();

    //ctor
    Arraylist(const Arraylist &a);

    T operator[](const int &i) const;
    T &operator[](const int &i);
    T operator=(const Arraylist<T, size> &other);
    bool operator!=(const Arraylist<T, size> &diese);
    bool operator==(const Arraylist<T, size> &diese);
    T get(int i) const;
    void set(int i, T number);
    int getSize() const;

    //Aufgabe 5.3 --------------------------------------------------------------------------------------------

    class ArraylistIterator
    {
    private:
        int offset;
        const hfu::Arraylist<T, size> &list;

    public:
        ArraylistIterator(int offset, Arraylist<T, size> &arraylist) : offset(offset), list(arraylist) {}

        ArraylistIterator()
        {
        }

        void operator++()
        {
            offset++;
        }

        T &operator*()
        {
            return list.arr[offset];
        }

        bool operator!=(ArraylistIterator &it)
        {
            if (&it.list == &list)
            {
                return (offset != it.offset);
            }
            else
            {
                return true;
            }
        }
    };

    ArraylistIterator end()
    {
        return ArraylistIterator(size, *this);
    }

    ArraylistIterator begin()
    {
        return ArraylistIterator(0, *this);
    }
};

//Operatoren book------------------------------------------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Book &buch);
bool operator==(const Book &buch1, const Book &book2);
bool operator!=(const Book &buch1, const Book &book2);
bool operator<(const Book &buch1, const Book &book2);

template <class T, int size>
std::ostream &operator<<(std::ostream &os, const Arraylist<T, size> &other)
{
    for (int i = 0; i < other.getSize(); i++)
    {
        os << "[" << other.get(i) << "]\t";
    }
    return os;
}

//Templates ----------------------------------------------------------------------------------------

template <class T, int size>
T &Arraylist<T, size>::operator[](const int &i)
{
    return (this->arr[i]);
}

template <class T, int size>
T Arraylist<T, size>::operator[](const int &i) const
{
    return (this->arr[i]);
}

template <class T, int size>
T Arraylist<T, size>::operator=(const Arraylist<T, size> &other)
{
    if (*this == other)
    {
        return *this;
    }
    delete[] arr;
    size = other.size;
    arr = new T[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = other.arr[i];
    }
    return *this;
}

template <class T, int size>
bool Arraylist<T, size>::operator!=(const Arraylist<T, size> &diese)
{
    if (diese.size != this->size)
    {
        return true;
    }
    for (int i = 0; i < diese.getSize(); i++)
    {
        if (diese.get(i) != this->get(i))
        {
            return true;
        }
    }
    return false;
}

template <class T, int size>
bool Arraylist<T, size>::operator==(const Arraylist<T, size> &diese)
{
    if (diese.size != this->size)
    {
        return false;
    }
    for (int i = 0; i < diese.getSize(); i++)
    {
        if (diese.get(i) != this->get(i))
        {
            return false;
        }
    }
    return true;
}

template <class T, int size>
T Arraylist<T, size>::get(int i) const
{
    //Prüfen ob Eingabe im Arraybereich liegt, sonnst Exception
    if (i <= size && i >= 0)
    {
        return arr[i];
    }
    else
    {
        throw "Index out of bounds";
    }
}

template <class T, int size>
void Arraylist<T, size>::set(int i, T number)
{
    //Prüfen ob größe Arraygröße entspricht, sonnst Exception
    if (i <= size)
    {
        arr[i] = number;
    }
    else
    {
        throw "Index out of bounds";
    }
}

template <class T, int size>
int Arraylist<T, size>::getSize() const
{
    return size;
}

//Template Kontruktor-----------------------------------------------------------------

template <class T, int size>
Arraylist<T, size>::Arraylist()
{
    arr = new T[size];
}

template <class T, int size>
Arraylist<T, size>::Arraylist(const Arraylist &other)
{
    for (int i = 0; i < other.getSize(); i++)
    {
        arr[i] = other.arr[i];
    }
}

}; // namespace hfu

#endif