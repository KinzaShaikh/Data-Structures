#include "Car.hpp"


void Car::Initialize(string key, string carMake, string carModel, VehicleType Cartyp, double carPrice)
{
    pricePerDay = carPrice;
    plateNumber = key;
    make = carMake;
    model = carModel;
    type = Cartyp;
}

string Car::GetPlateNumber() const
{
    return plateNumber;
}

string Car::GetMake() const
{
    return make;
}

VehicleType Car::GetVehicleTypeEnum() const
{
    return type;
}

double Car::GetPricePerDay() const
{
    return pricePerDay;
}

string Car::GetVehicleType() const
{
    return typeArray[int(type)];
}

string Car::GetModel() const
{
    return model;
}

void Car::SetAvailable(bool availableControl)
{
    isAvailable = availableControl;
}


bool Car::GetAvailibility() const
{
    return isAvailable;
}



//overloading operators + deconstructor

std::ostream& operator<<(std::ostream& ostrm, const Car& x) {
    ostrm << "License Plate: " << x.GetPlateNumber() <<endl<<"Make: " << x.GetMake() <<endl<< "Model: " << x.GetModel() <<endl<< "Type: " << x.GetVehicleType() <<endl<< "Price Per Day: $" << x.GetPricePerDay() << endl<<endl;
    return ostrm;
}

void Car::operator= (const Car& compare)
{
    plateNumber = compare.GetPlateNumber();
    make = compare.GetMake();
    model = compare.GetModel();
    type = compare.GetVehicleTypeEnum();
    pricePerDay = compare.GetPricePerDay();

}

Car::~Car() {};

bool Car::operator== (const Car& compare)
{
    return plateNumber == compare.GetPlateNumber();
}