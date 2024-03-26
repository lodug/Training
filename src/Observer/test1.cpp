//TASK 6: Observer pattern: the implementation of observer has been added in the Task3/singleton code

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include <vector>

using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;

// read data from a database cars.txt (also modifiy it)

//Observer interface
class DatabaseCarObserver
{
    public:
        virtual void DatabaseUpdate(const string& carBrand, int nbCars) = 0;
};

class SingletonDatabaseCar
{
    //a private constructor
    SingletonDatabaseCar()
    {
        //initialize database
        reloadDatabase();
    }

    //we want to get the file, so have an input file stream and then read the data into some sort of map
    //a map from a string to int, called cars (the number of cars of different cars brands)
    map<string, int> cars;  

    vector<DatabaseCarObserver*> observers;
    
    public:
      
        // a static function called "get" is needed which returns a reference to the Singleton database in order to get the singleton
        static SingletonDatabaseCar& get()
        {
            //we make a static instance of the database, so static singleton database db:
            static SingletonDatabaseCar db;
            //return db
            return db;
        }        
        // That's pretty much all that you need to do in order to provide a singleton. 
        //So somebody has to call get and get the appropriate singleton because it's been constructed statically and this is all completely safe and normal.
        
        //register observer
        void registerObserver(DatabaseCarObserver* observer)
        {
            observers.push_back(observer);
        }    

        //notify observers
        void notifyObservers(const string& carBrand, int nbCars ) 
        {
            for (DatabaseCarObserver* observer : observers) 
            {
                observer->DatabaseUpdate(carBrand, nbCars);
            }
        }

        //And then we want some sort of API for actually getting the number of cars from a particular car brand: a function called get_nbCar:
        // take a string reference, the name of the actual car brand.
        int get_nbCar(const string& name)
        {
            //return the actual number of cars
            return cars[name];
        }

        // initialize database
        void reloadDatabase()
        {
        //clear existing database
         cars.clear();
        
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

        //notify observers about the change in database
        for (const auto& CarsAdd : cars)
            {
                notifyObservers(CarsAdd.first, CarsAdd.second);
            }
        }

        //modifiy database (cars.txt) and notify observer
        void modifyDatabase(const string& carBrand, int newNbCars)
        {
            cars[carBrand] = newNbCars;
        
            //update txt file
            ofstream ofs("cars.txt"); 

            //notify observers about the change in database
            for (const auto& addition : cars)
            {
            ofs <<  addition.first << endl;
            ofs <<  addition.second << endl;
            }
            ofs.close();

            notifyObservers(carBrand, newNbCars);
        }
};

//concrete observer
class ConcreteDatabaseCarObserver : public DatabaseCarObserver
{
    public:        
        void DatabaseUpdate(const string& carBrand, int nbCars) override
        {                                
            cout << "Observer: update -> " << " number of cars " << carBrand << " in the city is now: " 
            << nbCars << endl;
               
        }
};

int main()
{  
    // for a given car brand: have string car brand equals "Aston Martin".
    //string cars = "Aston Martin";

    //create observer
    ConcreteDatabaseCarObserver observer;

    //register observer
    SingletonDatabaseCar& database = SingletonDatabaseCar::get();
    database.registerObserver(&observer);

    database.reloadDatabase();

    //uodate the cars.txt file   
    string carBrand = "Aston Martin";
    int newNbCars = 13;
    database.modifyDatabase(carBrand, newNbCars);  
   
    //if the database was updated, notify it   
    cout << " after changes in database" << endl;
    database.reloadDatabase();

}