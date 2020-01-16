#ifndef Blatt3_Header_h
#define Blatt3_Header_h

template <class T>
class Arraylist
{
private:
    T *arr;
    int size = 0;

public:
    //Konstruktor
    Arraylist(const int &size1) : arr(new T[size1]), size(size1){};

    //ctor
    Arraylist(const Arraylist &a) : Arraylist(a.size)
    {

        for (int i = 0; i < a.size; i++)
        {
            arr[i] = a.arr[i];
        }
    }

    ~Arraylist()
    {
        //Destruktor um Speicherplatz wieder freizugeben
        delete[] arr;
    }

    double get(int i) const
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

    void set(int i, T number)
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
    T operator[](int k)
    {
        return get(k);
    }
    bool operator==(const Arraylist<T> &diese)
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

    bool operator!=(const Arraylist<T> &diese)
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

    const T operator[](const int k) const
    {
        return get(k);
    }

    int getSize() const
    {
        return size;
    }

    Arraylist &operator=(const Arraylist &other)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }

        return *this;
    }
};

template <class T>
std::ostream &operator<<(std::ostream &os, const Arraylist<T> &other)
{
    for (int i = 0; i < other.getSize(); i++)
    {
        os << "[" << other.get(i) << "]\t";
    }
    return os;
}

#endif