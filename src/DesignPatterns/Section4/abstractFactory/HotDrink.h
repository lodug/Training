#pragma once
#include <iostream>
using namespace std;
#include <memory>

//make an interface called hotdrink
struct HotDrink
{
    //virtual destructor HotDrink default
    virtual ~HotDrink() = default;

    //virtual method void prepare where prepare the drink with specified volume and it going to be = 0, so pure virtual
    virtual void prepare(int volume) = 0;
};

// a family of different objects (products): a hot drink such as tea or coffee, for example. IN the HotDrinkFactory.h will have a correspoding family of factories
//tea: will inherit from HotDrink
struct Tea : HotDrink
{
    void prepare(int volume) override
    {
        cout << "Take tea bag, boil water, pour " << volume << "ml, add some lemons" << '\n';
    }
};

//coffee : will inherit from HotDrink
struct Coffee : HotDrink
{
    void prepare(int volume) override
    {
        cout << "Grind some beans, boil water, pour " << volume << "ml, add cream, enjoy" << '\n';
    }
};