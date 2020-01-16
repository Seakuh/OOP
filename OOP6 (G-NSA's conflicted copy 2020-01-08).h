#ifndef OOP6
#define OOP6_h
#include <string>
#include <iostream>

//Aufgabe 1 --------------------------------------------------------------------------------------

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(int length, int width) : length(length), width(width){};

    double getLength();
    double getWidth();

    double circumference();
    double area();
};

class Cuboid : public Rectangle
{
private:
    double height;

public:
    Cuboid(double length, double width, double height) : Rectangle(length, width), height(height){};

    double volume();
};

//Aufgabe 3 --------------------------------------------------------------------------------------

class Person
{
private:
    int id;
    std::string lastName;
    std::string firstName;

public:
    Person(int id, std::string lastName, std::string firstName) : id(id), lastName(lastName), firstName(firstName){};

    int getId() const;
    std::string getLastName() const;
};

class Guest : public Person
{
private:
    const int days;
    const int roomRate;

public:
    Guest(int id, std::string lastName, std::string firstName, int days, int roomRate) : Person(id, lastName, firstName), days(days), roomRate(roomRate){};
    int getDays() const;
    int getRoomRate() const;
    int check() const;
};

//Aufgabe 4 --------------------------------------------------------------------------------------

class Employee : public Person
{
public:
    Employee(int id, std::string lastName, std::string firstName) : Person(id, lastName, firstName){};
    virtual int salary() const
    {
        return 0;
    }
};

class Worker : public Employee
{
private:
    const int hourlyRate;
    int hoursWorked;

public:
    Worker(int id, std::string lastName, std::string firstName, int hourlyRate, int hoursWorked) : Employee(id, lastName, firstName), hourlyRate(hourlyRate), hoursWorked(hoursWorked){};
    virtual int salary() const
    {
        return hourlyRate * hoursWorked;
    }
};

class Seller : public Employee
{
private:
    const int pay;
    const int commission;

public:
    Seller(int id, std::string lastName, std::string firstName, int pay, int commision) : Employee(id, lastName, firstName), pay(pay), commission(commission){};
    virtual int salary() const;
    int getPay() const;
    int getCommission() const;
};

#endif