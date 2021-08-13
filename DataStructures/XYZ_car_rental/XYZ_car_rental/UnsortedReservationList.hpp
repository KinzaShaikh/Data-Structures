
#ifndef UNSORTEDRESERVATIONLIST_HPP
#define UNSORTEDRESERVATIONLIST_HPP

#include "Reservation.hpp"

#include <iostream>

#define MAX_POS 100

class UnsortedReservationList
{
private:
    int currentPos = 0;
    int length = 0;
    Reservation reservationArray[MAX_POS];

public:
    void AddReservation(Reservation&);
    void DeleteReservation(string);
    void PrintList();
    string FindReservationCar(Reservation);
    Reservation FindReservation(string);
    ~UnsortedReservationList();

};

#endif