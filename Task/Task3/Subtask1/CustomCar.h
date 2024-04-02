#pragma once
#include <iostream>
using namespace std;
#include <memory>

//make an interface called CustomCar
struct CustomCar
{
    //virtual destructor CustomCar default
    virtual ~CustomCar() = default;

    //virtual method void paint where paint the car with specified color and it going to be = 0, so pure virtual
    virtual void customPaint(std::string color) = 0;
};

// a family of different objects (products): a custom car such as Car1 or Car2, for example. 
//IN the CustomCarFactory.h will have a correspoding family of factories; 
//car1: will inherit from CustomCar
struct Car1 : CustomCar
{
    void customPaint(std::string color) override
    {
        cout << "Custom car1 paint in " << color << '\n';
    }
};

//car2: will inherit from CustomCar
struct Car2 : CustomCar
{
    void customPaint(std::string color) override
    {
        cout << "Custom car2 paint in " << color << '\n';
    }
};