
#include "Reservation.hpp"

void Reservation::Initialize(string key, string plate)
{
    name = key;
    vehicleRented = plate;
}


string Reservation::GetVehicleRented() const
{
    return vehicleRented;
}

string Reservation::GetName() const
{
    return name;
}


Reservation::~Reservation() {}
//overloading
std::ostream& operator<<(std::ostream& ostrm, const Reservation& reserv) {
    ostrm << "Name: " << reserv.GetName() << endl << "Vehicle for Rent: " << reserv.GetVehicleRented();
    return ostrm;
}

bool Reservation::operator== (const Reservation& compare)
{
    return name == compare.GetName();
}
