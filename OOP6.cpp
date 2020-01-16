#include <iostream>
#include <array>
#include <memory>
#include "OOP6.h"

//Aufgabe 1 --------------------------------------------------------------------------------------

double Rectangle::getLength()
{
    return length;
}

double Rectangle::getWidth()
{
    return width;
}

double Rectangle::circumference()
{
    return ((2 * width) + (2 * length));
}

double Rectangle::area()
{
    return width * length;
}

double Cuboid::volume()
{
    return getWidth() * getLength() * height;
}

//Aufgabe 2 --------------------------------------------------------------------------------------

class Base
{
    int valueB;

public:
    void setValueB(int value);
    int getValueB();
};
void Base::setValueB(int value)
{
    this->valueB = value;
}

int Base::getValueB()
{
    return valueB;
}

typedef std::array<int, 1> SingleArray;
class Derived : public Base
{
    SingleArray *array = new SingleArray();

public:
    void setValueD(int value);
    int getValueD();
};
void Derived::setValueD(int value)
{
    (*array)[0] = value;
}
int Derived::getValueD()
{
    return (*array)[0];
}

//Aufgabe 3 ------------------------------------------------------------------------------------------

int Person::getId() const
{
    return id;
}

std::string Person::getLastName() const
{
    return lastName;
}

int Guest::getDays() const
{
    return days;
}
int Guest::getRoomRate() const
{
    return roomRate;
}

int Guest::check() const
{
    return (getDays() * getRoomRate());
}

//Aufgabe 4 ------------------------------------------------------------------------------------------

// int Employee::salary()
// {
//     return 0;
// }

int Worker::salary()
{
    return hourlyRate * hoursWorked;
}

int Seller::salary()
{
    return (pay + commission);
}

int Seller::getPay() const
{
    return pay;
}

int Seller::getCommission() const
{
    return commission;
}

int main()
{
    //Aufgabe 1 Tests---------------------------------------------------------------------------------

    Rectangle rec1(12.34, 13.34);
    Rectangle rec2(34.56, 34.34);

    Cuboid cob1(34.23, 23.34, 23.45);
    Cuboid cob2(34.23, 23.22, 23.23);

    std::cout << "---Coboid ausgaben---" << std::endl;

    std::cout << cob1.getLength() << std::endl;
    std::cout << cob1.getWidth() << std::endl;
    std::cout << cob1.circumference() << std::endl;
    std::cout << cob1.volume() << std::endl;

    //Aufgabe 2 Tests---------------------------------------------------------------------------------

    Derived d0;
    Derived d1;

    Base b2;
    Base b3;

    d0.setValueB(0);
    d1.setValueB(1);

    b2.setValueB(2);
    b3.setValueB(3);

    std::cout << "---Vor zuweisung---" << std::endl;

    std::cout << d0.getValueB() << std::endl;
    std::cout << d1.getValueB() << std::endl;
    std::cout << b2.getValueB() << std::endl;
    std::cout << b3.getValueB() << std::endl;

    d0 = d1;
    b2 = d0; //geht aber keine Methoden, da b2 keine Attribute von d0 besitzt
    //d0=b2;  //Vererbung nicht möglich, da oberklasse
    b2 = b3;

    std::cout << "---Nach zuweisung---" << std::endl;

    std::cout << d0.getValueB() << std::endl;
    std::cout << d1.getValueB() << std::endl;
    std::cout << b2.getValueB() << std::endl;
    std::cout << b3.getValueB() << std::endl;

    //Aufgabe 3 Tests---------------------------------------------------------------------------------

    Person hans(1, "Hans", "Tscho");

    std::cout << "---Ausgabe Hans---" << std::endl;

    std::cout << hans.getId() << std::endl;
    std::cout << hans.getLastName() << std::endl;

    Guest Peter(1, "Peter", "Pit", 31, 40);

    std::cout << Peter.check() << std::endl;

    //Aufgabe 4 Tests---------------------------------------------------------------------------------

    Worker worker1 = Worker(11, "Hannes", "Hann", 13, 30);
    Employee &e = worker1;
    //Employee employee1(22, "Harald", "Hans");

    std::cout << "---Ausgabe Hannes---" << std::endl;

    std::cout << worker1.salary() << std::endl;

    //employee1 = worker1;

    std::cout << e.salary() << std::endl;

    //Aufgabe 7 ---------------------------------------------------------------------------------

    std::cout << "---AufgabenBlatt 7---" << std::endl;

    //auto employee = new Worker(4, "Duck", "Tick");
    std::unique_ptr<Employee> employee;

    auto worker = std::make_shared<Worker>(4, "Duck", "Tick", 9, 40);

    employee = worker;

    std::cout << employee->salary() << std::endl;

    auto seller = std::make_shared<Seller>(5, "Duck", "Trick", 1000, 2000);

    employee = seller;

    std::cout << employee->salary() << std::endl;

    // auto employee = new Worker(4, "Duck", "Tick");
    // std::shared_ptr<Employee>  prt1(employee);
    // auto worker = new Worker(4, "Duck", "Tick", 9, 40);
    // auto seller = new Seller(5, "Duck", "Trick", 1000, 2000);

    //employee = worker;

    //std::cout << employee->salary() << std::endl;

    //employee = seller;

    // std::cout << employee->salary() << std::endl;

    // std::cout << prt1.use_count() << std::endl;

    // prt1->salary();
}