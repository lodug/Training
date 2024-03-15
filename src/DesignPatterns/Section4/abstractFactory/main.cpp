//Abstract Factory: it is the idea of families of factories or families of products and corresponding families 
//of factories which use inheritance to actually allow you to polymorphically call on the different factories.

//emulate a simple kind of hot drink machine that can make tea or coffee or something else

#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cmath>
using namespace std;
#include "HotDrinkFactory.h"
#include "DrinkFactory.h"


//define some sort of method which is going to make a drink depending on the name of the drink.
//will have a uniqueptr since all of our factories use smart pointers uniqueptr of hot drink.
//it's going to be make drink and you simply specify the type which is going to be a string.
unique_ptr<HotDrink> make_drink(string type)
{
    //depending on whether you want tea or coffee, you would typically go ahead and just do an if.
    // let's first of all initialize a uniqueptr hot drink and let's call this drink.
    unique_ptr<HotDrink> drink;
    // //if we did not have an abstract factory, we would do like this tea or coffee:
    // if (type == "tea")
    // {
    //     drink  = make_unique<Tea>();
    //     drink->prepare(200);
    // }
    // else
    // {
    //     drink  = make_unique<Coffee>();
    //     drink->prepare(50);
    //    }
    //instead of doing it, we did it in a way more organizez in HotDrinkFactory.h    

    return 0;
};

int main()
{

    //if we did not have an abstract factory, we would do like this tea or coffee:So this would actually work.
    //But we have our abstract factory instead, which kind of takes care of some of these issues at the very least.
    //auto d = make_drink("tea");

    //what we can do is to make a Drink factory ( is something that's actually going to kind of keep track of the kind of stuff
    //that we have, the kind of factories that we have generally.) 
    //So essentially what you do is you make a drink factory.
    //So we we actually use one of these drink factories called DF And then you say DF dot make drink and we make, let's say a coffee.
    //And of course, yes, we do need to include the appropriate header here, but I can say auto C equals coffee and that's it.
    DrinkFactory df;
   auto c =  df.make_drink("coffee");

   return 0;

}