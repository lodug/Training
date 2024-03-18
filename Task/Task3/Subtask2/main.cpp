//Task3: subtask2: safe singletone implementation

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>
using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;

//read some data from cars.txt into a database: for us it only makes sense to have one instance of such a database because, 
//don't want to replicate the information again and again, so make a singletone database.

class SingletonDatabaseCar
{
    //a private constructor
    SingletonDatabaseCar()
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

    //we want to get the file, so have an input file stream and then read the data into some sort of map
    //a map from a string to int, called cars (the number of cars of different cars brands)
    map<string, int> cars;  
   
    //just because the constructor is private doesn't mean that cannot be created other instances of the Singleton database.
    //Let's say can be uses the copy constructor or copy assignment. So for both of these operations, at least, what you want to do is you want to delete them.  
    //so make a copy constructor: So make a singleton database which takes another singleton database const reference, and delete this.
    public:
        SingletonDatabaseCar(SingletonDatabaseCar const&) = delete;
        //And in addition, what I'm going to do also is I'm going to delete the copy assignment Operator 
        //so you have operator =, which also takes a const reference and you can delete that as well.
        void operator=(SingletonDatabaseCar const&) = delete;
        //So this ensures that nobody can actually replicate this database in any way, shape or form, thereby wasting valuable resources.   

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

        //And then we want some sort of API for actually getting the number of cars from a particular car brand: a function called get_nbCar:
        // take a string reference, the name of the actual car brand.
        int get_nbCar(const string& name)
        {
            //return the actual number of cars
            return cars[name];
        }

};

int main()
{  
    // for a given car brand: have string car brand equals "Aston Martin".
    string cars = "Aston Martin";
    
    // the Singleton database and now we can actually get the number of cars of a particular car brand:
    cout << cars << " cars number in a city is:  " << 
        SingletonDatabaseCar::get().get_nbCar(cars) << '\n';

}