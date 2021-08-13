#include "UnsortedReservationList.hpp"

void UnsortedReservationList::AddReservation(Reservation& addNewReservation)
{
    reservationArray[length] = addNewReservation;
    length++;
}

void UnsortedReservationList::PrintList()
{
    cout << endl << "____________________________________" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << "\n-Reservation " << i + 1 << "-\n" << reservationArray[i] << endl;
    }
    cout << endl << "____________________________________" << endl;

}
string UnsortedReservationList::FindReservationCar(Reservation compare)
{
    return compare.GetVehicleRented();
}

Reservation UnsortedReservationList::FindReservation(string compare)
{
    for (int i = 0; i < length; i++)
    {
        if (reservationArray[i].GetName() == compare)
        {
            return reservationArray[i];
        }
    }
}

void UnsortedReservationList::DeleteReservation(string compare)
{
    for (int i = 0; i < length; i++)
    {
        if (reservationArray[i].GetName() == compare)
        {
            reservationArray[i] = reservationArray[--length];
        }
    }
}

UnsortedReservationList::~UnsortedReservationList() {}