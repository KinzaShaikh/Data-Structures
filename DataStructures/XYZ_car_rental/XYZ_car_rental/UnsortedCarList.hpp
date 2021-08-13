
#ifndef UNSORTEDCARLIST_HPP
#define UNSORTEDCARLIST_HPP

#include "Car.hpp"

#include <iostream>

#define MAX_POS 100

class UnsortedCarList
{
private:
    int currentPos = 0;
    int length = 0;
    Car carArray[MAX_POS];

public:
    void AddCar(Car);
    void ChangeAvailability(string);
    void DeleteCar(string);
    void PrintList();
    Car FindCar(string);
    Car& GetCarAtIndex(int);
    ~UnsortedCarList();

};

#endif