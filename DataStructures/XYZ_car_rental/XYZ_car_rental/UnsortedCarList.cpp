
#include "UnsortedCarList.hpp"

void UnsortedCarList::AddCar(Car addNewCar)
{
    carArray[length] = addNewCar;
    length++;
}
Car& UnsortedCarList::GetCarAtIndex(int index)
{
    return carArray[index - 1];
    throw std::out_of_range("Index Out of Range");
}


void UnsortedCarList::PrintList()
{
    cout << endl << "______________________________" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << "\n-Car " << i + 1 << "-\n" << carArray[i];
    }
    cout << endl << "______________________________" << endl;
}

void UnsortedCarList::ChangeAvailability(string compare)
{
    for (int i = 0; i < length; i++)
    {
        if (carArray[i].GetPlateNumber() == compare)
        {
            cout << carArray[i].GetAvailibility() << endl;
            if (carArray[i].GetAvailibility())
            {
                cout << "car is true!";
                carArray[i].SetAvailable(false);
            }
            else
            {
                cout << "car isfalse!";
                carArray[i].SetAvailable(true);
            }
        }
    }
}

Car UnsortedCarList::FindCar(string compare)
{
    for (int i = 0; i < length; i++)
    {
        if (carArray[i].GetPlateNumber() == compare)
        {
            return carArray[i];
        }
    }
}
void UnsortedCarList::DeleteCar(string compare)
{
    if (length !=0){
        for (int i = 0; i < length; i++)
        {
            if (carArray[i].GetPlateNumber() == compare)
            {
                if (carArray[i].GetAvailibility())
                {
                    carArray[i] = carArray[--length];
                    cout << "Car is Deleted.";
                }
                else
                {
                    cout << "Car is currently in use. No action"<<endl;
                }

                break;
            }

        }

    }
    else
    {
        cout << "Car not found" << endl;

    }
}


UnsortedCarList::~UnsortedCarList() {}