//Task3: subtask2: safe singletone implementation

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>
using namespace std;
#include "singletone.h"

#include <boost/lexical_cast.hpp>
using namespace boost;

//read some data from cars.txt into a database: for us it only makes sense to have one instance of such a database because, 
//don't want to replicate the information again and again, so make a singletone database.

SingletonDatabaseCar::SingletonDatabaseCar()
    {
        //cout << "Initializing the database\n";
        //get the input file stream from cars.txt and read the data from it.
        ifstream ifs("cars.txt");         

        //have 2 temporary strings
        string s, s1;

        //while getline input, file stream s, read the line into s and then read the second line
        while (getline(ifs, s))
        {
            getline(ifs, s1);
            int nbCar = lexical_cast<int>(s1);  //convert string into int for the cars number line in cars.txt file
            // put them into the map so I can say cars at s equals the number of cars. That's how the database is read
            cars[s] = nbCar;
        }
    }   
    
        // a static function called "get" is needed which returns a reference to the Singleton database in order to get the singleton
        SingletonDatabaseCar &SingletonDatabaseCar::get()
        {
        //we make a static instance of the database, so static singleton database db:
        static SingletonDatabaseCar db;
       
        //return db
        return db;
        }        
        // That's pretty much all that you need to do in order to provide a singleton. 
        //So somebody has to call get and get the appropriate singleton because it's been constructed statically and this is all completely safe and normal.

        //And then we want some sort of API for actually getting the number of cars from a particular car brand: a function called get_nbCar:
        // take a string reference, the name of the actual car brand.
        int SingletonDatabaseCar::get_nbCar(const string& name)
        {
            //check if the car brand exists in the database and return the number of cars
            if (cars.find(name) != cars.end())
            {                
                //return the actual number of cars
                return cars[name];               
            }
            else
            {
                //return 0 if the car is not in the database
                return 0;
            }
        }

