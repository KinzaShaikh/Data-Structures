#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include <string>
using namespace std;

enum VehicleType { SEDAN = 1, SUV, EXOTIC };

class Car
{
private:
    bool isAvailable=true;
    string plateNumber;
    string make;
    string model;
    VehicleType type;
    double pricePerDay;
    string typeArray[4] = { "Error", "Sedan", "SUV", "Exotic" };
 
public:
    string GetPlateNumber() const;
    string GetMake() const;
    string GetModel() const;
    VehicleType GetVehicleTypeEnum() const;
    string GetVehicleType() const;
    double GetPricePerDay() const;
    void Initialize(string pltKey, string mke, string mdl, VehicleType typ, double ppd);
    void SetAvailable(bool availability); //dont know if this works
    bool GetAvailibility() const;
    ~Car();
    bool operator== (const Car&);
    void operator= (const Car&);

};

std::ostream& operator<<(std::ostream& ostrm, const Car& x);

#endif