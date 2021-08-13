
#include "Reservation.hpp"
#include "UnsortedCarList.hpp"
#include "Car.hpp"
#include "UnsortedReservationList.hpp"

#include <iostream>
#include <string>
using namespace std;
static void callMenu() {
    UnsortedCarList* carList = new UnsortedCarList();
    UnsortedReservationList* reservationList = new UnsortedReservationList();

    string plateNo;
    string carMake;
    string carModel;
    int carType;
    double carPrice;

    bool exitFlag = false;
    int switchController;

    string resName;
    int resRent;
    string carRent;

    string removeCar;
    string removeReservation;


    cout << endl << "______XYZ Car Rental System_______" << endl;

    while (!exitFlag)
    {
        cout << endl;
        cout << endl << "Type An Option:" << endl << "1. List All Cars" << endl << "2. Add Car to inventory" << endl << "3. Remove Car From inventory" << endl << "4. List All Reservations" << endl << "5. Add a Reservation" << endl << "6. Cancel a Reservation" << endl << "7. Exit Program\n" << endl;
        cin >> switchController;
        switch (switchController)
        {
        case 1:
        {
            //case 1: to list all cars
            carList->PrintList();
            break;
        }
        case 2:
        {
            //case 2: to add car
            cout << endl << "___Car Information___" << endl << endl;


            cout << "Enter License Plate: " << flush;
            cin >> plateNo;
            cout << "Enter Make: ";
            cin >> carMake;
            cout << "Enter Model: ";
            cin >> carModel;
            cout << "Enter Car Type (1)Sedan (2)SUV (3)Exotic: ";
            cin >> carType;
            cout << "Enter Price Per Day: $";
            cin >> carPrice;

            Car* addNewCar = new Car;
            addNewCar->Initialize(plateNo, carMake, carModel, static_cast<VehicleType>(carType), carPrice); //is this okay?

            carList->AddCar(*addNewCar);
            cout << endl << addNewCar->GetPlateNumber() << " is added and the car is available";

            break;
        }
        case 3:
        {
            //case 3: to remove the car
            cout << endl << "Enter License Plate: " << endl;
            cin >> removeCar;
            carList->DeleteCar(removeCar);

            break;
        }
        case 4:
        {
            //case 4: to list all reservations
            reservationList->PrintList();
            break;
        };
        case 5:
        {
            //case 5 : to add all resevations
            cout << endl << "____Reservation Information____" << endl << endl;

            cout << "Name: " << flush;
            cin >> resName;
            carList->PrintList();
            cout << endl << "Enter 0 To Cancel" << endl << endl << "Number of Car to Rent: " << endl;
            cin >> resRent;

            try
            {
                if (resRent == 0)
                {
                    cout << "Reservation Canceled.";
                    break;
                }

                carRent = carList->GetCarAtIndex(resRent).GetPlateNumber();

                if (carList->FindCar(carRent).GetAvailibility())
                {
                    Reservation* addNewReservation = new Reservation;
                    addNewReservation->Initialize(resName, carRent);
                    reservationList->AddReservation(*addNewReservation);

                    carList->ChangeAvailability(carRent);

                    cout << "New Reservation : " << resName << " is Created.";
                }
                else
                {
                    cout << endl << "Car is currently reserved" << endl;
                }
            }
            catch (std::out_of_range)
            {
                cerr << "Index Out of Range";
            }

            break;
        };
        case 6:
        {
            //case 6: to remove the reservation
            cout << "Enter Name: ";
            cin >> removeReservation;


            carList->ChangeAvailability(reservationList->FindReservationCar(reservationList->FindReservation(removeReservation)));

            reservationList->DeleteReservation(removeReservation);

            cout << "Reservation is deleted and the car is now available";

            break;
        };
        case 7:
        {
            //case 7: to end the program
            cout << endl << "___Program ends___" << endl;
            exitFlag = true;
            break;
        }
        }
    }
}
int main()
{
    callMenu();
}