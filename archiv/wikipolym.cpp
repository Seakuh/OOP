#include <iostream>
#include <cstdlib>
#include <vector>
#include <typeinfo>

using namespace std;

class A
{
private:
public:
    virtual int getStatus() = 0;
};

class B : public A
{
private:
    int status;

public:
    B(int status)
    {
        this->status = status;
    }
    int getStatus()
    {
        return this->status;
    }
    // ... weitere Methoden
};

class C : public A
{
private:
    int status;

public:
    C(int status)
    {
        this->status = status;
    }
    int getStatus()
    {
        return this->status;
    }
    // ... weitere Methoden
};

int main(void)
{
    vector<A *> vec;
    int i;

    // A *a = new A(1); // geht nicht da A abstrakt ist
    B *b = new B(2);
    A *ab = new B(3);
    C *c = new C(4);

    vec.push_back(b);
    vec.push_back(ab);
    vec.push_back(c);

    for (i = 0; i < vec.size(); i++)
    {
        A *tmp = vec.at(i);
        cout << "Value: " << tmp->getStatus() << " Klasse: " << typeid(*tmp).name() << endl;
    }

    delete b;
    delete ab;
    delete c;

    cin.get();
    return EXIT_SUCCESS;
}