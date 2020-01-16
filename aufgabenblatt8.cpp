#include <iostream>

class Vehicle
{
    const std::string numberPlate;
    const std::string manufacture;

public:
    Vehicle(std::string numberPlate, std::string manufacture) : numberPlate(numberPlate), manufacture(manufacture){};
    virtual void dump() = 0;
    virtual std::string getNumberPlate() = 0;
    virtual std::string getManufacture() = 0;
};

class Van : public Vehicle
{
    const int maxLoad;

public:
    Van(std::string numberPlate, std::string manufacture, int maxLoad) : Vehicle(numberPlate, manufacture), maxLoad(maxLoad){};
    void dump();
    int getMaxLoad();
};

class PassangerCar : public Vehicle
{
    const bool sunRoof;

public:
    PassangerCar(std::string numberPlate, std::string manufacture, bool sunRoof) : Vehicle(numberPlate, manufacture), sunRoof(sunRoof) {}
    void dump();
    bool hasSunRoof();
};

class StationWagon : public PassangerCar, public Van
{
    const int numSeats;

public:
    StationWagon(std::string numberPlate, std::string manufacture, int maxLoad, bool sunRoof, int numSeats) :
};





int main()
{
    Van van = Van("VS XY 42", "BMW", 100);
    van.dump();
    Vehicle &vc = van;
    vc.dump();
}