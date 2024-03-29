#include <iostream>
#include <string>

#include "singletone.h"

int main()
{  
    // for a given car brand: have string car brand equals "Aston Martin".
    string carBrand = "Aston Martin";
    
    // the Singleton database and now we can actually get the number of cars of a particular car brand:
    cout << carBrand << " cars number in a city is:  " << 
        SingletonDatabaseCar::get().get_nbCar(carBrand) << '\n';

}