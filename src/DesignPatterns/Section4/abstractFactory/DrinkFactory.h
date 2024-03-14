//  a drink factory is a concrete implementation of the abstract factory.
//Or in other words, it's a facilitator for actually using all of the different factories that we've
//made and having them in some sort of map and exposing them to whoever is actually interested in making a drink.

#pragma once
#include "HotDrink.h"
#include "HotDrinkFactory.h"
#include <map>
#include <functional>
using namespace std;
//this header is for the implentation of the function factory


//a class : to help us construct drinks on the basis of the different factories.
class DrinkFactory
{
    //do a map from the names of the drinks to the factories which actually are capable of producing those drinks
    //I'm going to have a map from a string to a unique PTR of Hot Drink Factory, and I'm going to call them
    //hot factories because who knows, you might have cold drinks as well. So this is going to be a private thing.
    //And then we're going to have a couple of public members.So when we initialize the drink factory, I don't want to, actually, I want to select none.
   
    
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;
    public:
        ////I guess I want an empty constructor here. So when you initialize it, what you can do is you can add all those factories into the map.
        DrinkFactory()
        {
           //hot factories with the name coffee is equal to make unique.  here you would construct the coffee factory
           hot_factories["coffee"] = make_unique<CoffeeFactory>();
           //tea
           hot_factories["tea"] = make_unique<TeaFactory>();
           //we're using this polymorphism of the factories to kind of keep all the factories in a single collection.
        }

           //When somebody wants a drink, we can provide an interface for that.
           //So you can have a uniqueptr returning a hot drink, a unique hot drink
           //We're going to call it make drink and it's going to take the name of the drink that we want to make.
           unique_ptr<HotDrink> make_drink(const string& name)
           {
                //And here all we have to do is we have to make a lookup into our map and actually make the drink.
                //Auto drink equals hot factories, perform the lookup with name and then call the make call the make function on it.               
                auto drink = hot_factories[name]->make();    
                // //That's pretty much all that we would generally have to do and then we would prepare the drink.
                //So drink, prepare with a certain amount.
                drink->prepare(200) ;
                return drink;
           }        
};

// //functional factory video : keep it comment for when there is need of it

// //build a similar kind of factory, but without necessarily relying directly on factories as such.
// //Because instead of these factories, you can have simple lambda functions describing how a particular drink is made.
// //So if you have a class called Drink with Volume Factory, so we're going to provide the volume of the drink that we actually want to make.
// //So we're also going to have a map./ But instead of having a map from the name of the drink to the factory, which actually creates the drink, 
// //what we're going to do is we're going to have a map from the name of the drink. So in this case, that's going to be a string.
// //Once again, we're going to map to a function. And this function will define how a drink is actually made.
// //So instead of using a factory, we're going to basically just use an anonymous function.

// class DrinkWithVolumeFactory
// {
//     //So here I'll define a function which returns a uniqueptr of hot drink and it takes no arguments like so and we're going to call it factories.
//     map<string, function<unique_ptr<HotDrink>()>> factories;
//     //intializes these things
//     public:
//         //when you have a constructor, so you have drink with Volume Factory as a constructor,
//         // what you do is you initialize the factories by just providing the lambda in place.
//         // if you want to specify that when somebody makes tea, you need 200ml and when you make coffee you need 50. You can define it in a lambda.
//         DrinkWithVolumeFactory()
//         {
//              //factories t equals and then here we provide the lambda so you can have some sort of capture list and we're not going to have any arguments really.
//                 //So it's just going to be auto T equals make unique T So you describe the process of making something in a functional way, 
//                 //and here we can call the prepare.  
//                 //call the prepare function with, let's say 200ml and then we can return T like so.
//                 //So this is how you would make a more of a functional factory rather than a factory, depending upon
//                 //this idea of object orientation and inheritance and the abstract factory design pattern.
//                 //the lamdas are from below
//             //     [] 
//             // {               
//             //     auto tea = make_unique<Tea>();
//             //     tea->prepare(200);
//             //     return tea;
//             // };

            
//              //when you provide this lambda, when you are specifying this lambda here, this is the factory method, it's just encapsulated as a standalone function.
//              //And when it comes to making the drink, so you return, so you get the factories, you find the factory 
//              //with a particular name and because it's a function, you simply invoke it with round brackets.      
//              //And this way you end up with a functional factory as opposed to an abstract factory that's based on inheritance.
                
//             factories["tea"] = [] 
//             {               
//                 auto tea = make_unique<Tea>();
//                 tea->prepare(200);
//                 return tea;
//             };
//         }

//         //when it comes to actually serving the drink, you can do something like the following:
//         //you would maybe have a function which returns a uniqueptr of a hot drink. You might call it make drink. It would take the name of the drink as before.
//         //And here you would simply invoke whatever the factory method is.
//         unique_ptr<HotDrink> make_drink(const string& name)
//         {
//             return 0;
//         }
// };




