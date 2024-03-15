#pragma once
#include <iostream>
using namespace std;
#include "HotDrink.h"

//IN the HotDrinkFactory.h will have a correspoding family of factories

//define the interface for a hot drink factory from which TeaFactrory and CoffeeFactory will inherit
struct HotDrinkFactory
{
    //a pure virtual method (a factory method called make()), we'll have a unique pointer; an interface member called make
    virtual unique_ptr<HotDrink> make() const = 0;

};


//make a tea factory
struct TeaFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override
    {
    return make_unique<Tea>();
    }
};

//make a coffee factory
struct CoffeeFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override
    {
    return make_unique<Coffee>();
    }
};