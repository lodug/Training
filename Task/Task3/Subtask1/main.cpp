//Task3: implement an Abstract Factory

//Abstract Factory: it is the idea of families of factories or families of products and corresponding families 
//of factories which use inheritance to actually allow you to polymorphically call on the different factories.

//emulate a simple kind of custom car

#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cmath>
using namespace std;
#include "CustomCarFactory.h"
#include "CarFactory.h"


//define some sort of method which is going to custom a car depending on the name of the car
//will have a uniqueptr since all of our factories use smart pointers uniqueptr of custom car.
//it's going to be custom car and you simply specify the type which is going to be a string.
unique_ptr<CustomCar> custom_car(string type)
{
    //depending on whether you want to custom car1 and car2, you would typically go ahead and just do an if, if we did not have an abstract factory
    //instead of doing it, we did it in a way more organizez in CustomCarFactory.h 
    // let's first of all initialize a uniqueptr customcar and let's call this car.
    unique_ptr<CustomCar> car;   

    return 0;
};

int main()
{    
    //what we can do is to custom car factory ( is something that's actually going to kind of keep track of the kind of stuff
    //that we have, the kind of factories that we have generally.) 
    //So essentially what you do is to have a  custom car factory.
    //So we we actually use one of these car factories called CF And then you say cf.custom_car("car1") - custom the car1
    //And of course, yes, we do need to include the appropriate header here, but I can say auto c equals car1 and that's it.
    CarFactory cf;
    auto c =  cf.custom_car("Car2");   

   return 0;

}