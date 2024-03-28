#pragma once
#include <iostream>
using namespace std;
#include "CustomCar.h"

//IN the CustomCarFactory.h will have a correspoding family of factories

//define the interface for a custom car factory from which Car1Factory and Car2Factory will inherit
struct CustomCarFactory
{
    //a pure virtual method (a factory method called make()), we'll have a unique pointer; an interface member called make
    virtual unique_ptr<CustomCar> make() const = 0;

};

//make a Car1 factory
struct Car1Factory : CustomCarFactory
{
    unique_ptr<CustomCar> make() const override
    {
    return make_unique<Car1>();
    }
};

//make a Car2 factory
struct Car2Factory : CustomCarFactory
{
    unique_ptr<CustomCar> make() const override
    {
    return make_unique<Car2>();
    }
};