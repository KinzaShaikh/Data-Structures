
#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <iostream>
#include <string>
using namespace std;

class Reservation
{
private:
    string name;
    string vehicleRented;

public:
    string GetName() const;
    string GetVehicleRented() const;
    void Initialize(string key, string vehiclePlate);
    ~Reservation();
    bool operator== (const Reservation&);
};

std::ostream& operator<<(std::ostream& ostrm, const Reservation& reserv);

#endif