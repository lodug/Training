// a car factory is a concrete implementation of the abstract factory 
// or in other words, it's a facilitator for actually using all of the different factories that we've
// made and having them in some sort of map and exposing them to whoever is actually interested in customing a car.

#pragma once
#include "CustomCar.h"
#include "CustomCarFactory.h"
#include <map>
#include <functional>
using namespace std;

//a class : to help us costume cars on the basis of the different factories.
class CarFactory
{
    //do a map from the names of the cars to the factories which actually are capable of customing those cars
    //I'm going to have a map from a string to a unique PTR of Custom Car Factory, and I'm going to call them
    //custom factories. So this is going to be a private thing.
    //And then we're going to have a couple of public members.
   
    
    map<string, unique_ptr<CustomCarFactory>> custom_factories;
    public:
        // an empty constructor, so when it is initialized, all those factories can be added into the map.
        CarFactory()
        {
           //custom factories with the name Car1 is equal to make unique.  
           // construct the Car1 factory
           custom_factories["Car1"] = make_unique<Car1Factory>();
           // construct the Car2 factory
           custom_factories["Car2"] = make_unique<Car2Factory>();
           // this polymorphism of the factories is used to kind of keep all the factories in a single collection.
        }

           //When somebody wants a custom car, we can provide an interface for that.
           // have a uniqueptr returning a custom car, a unique custom car
           //We're going to call it custom_car and it's going to take the name of the car that we want to custom.
           unique_ptr<CustomCar> custom_car(const string& name)
           {
                //And here all we have to do is we have to make a lookup into our map and actually custom the car.
                //Auto car equals custom factories, perform the lookup with name and then call the make function on it.               
                auto car = custom_factories[name]->make();    
                // //That's pretty much all that we would generally have to do and then we would custom the car.
                //So car, custom it with a certain colour.
                car->customPaint("blue");
                return car;
           }        
};
