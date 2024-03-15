//singletone implementation

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>
using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;

 //read some data from capitals.txt into a database: for us it only makes sense to have one instance of such a database because, 
//don't want to replicate the information again and again, so make a singletone database.

class SingletonDatabase
{
    //a private constructor
    SingletonDatabase()
    {
        //cout << "Initializing the database\n";
        //get the input file stream from capitals.txt and read the data from it.
        ifstream ifs("capitals.txt");  
       

        //have 2 temporary strings
        string s, s2;

        //while getline input, file stream s, read the line into s and then read the second line
        while (getline(ifs, s))
        {
            getline(ifs, s2);
            int pop = lexical_cast<int>(s2);  //convert string into int for the population number line in .txt file
            // I can put them into the map so I can say capitals at s equals the population. That's how you would read the database.
            capitals[s] = pop;
        }

    }
     //we want to get the file, so have an input file stream and then read the data into some sort of map
    //a map from a string to int, called capitals (the population of different capitals)
    map<string, int> capitals;  
   
    //just because the constructor is private doesn't mean that cannot be created other instances of the Singleton database, because if they get one instance they can use.
    //Let's say they can use the copy constructor or copy assignment.So for both of these operations, at least, what you want to do is you want to delete them.
    //Now in the modern C plus plus variety, we can use the delete keyword.
    // so make a copy constructor:So make a singleton database which takes another singleton database const reference, and I delete this.
    public:
        SingletonDatabase(SingletonDatabase const&) = delete;
        //And in addition, what I'm going to do also is I'm going to delete the copy assignment Operator 
        //so you have operator =, which also takes a const reference and you can delete that as well.
        void operator=(SingletonDatabase const&) = delete;
        //So this ensures that nobody can actually replicate this database in any way, shape or form, thereby wasting valuable resources.   

        //how to get the singleton? need a static function called get which returns a reference to the Singleton database
        static SingletonDatabase& get()
        {
        //we make a static instance of the database, so static singleton database db
        static SingletonDatabase db;
        //return db
        return db;
        }
        // That's pretty much all that you need to do in order to provide a singleton. 
        //So somebody has to call, get and they get the appropriate singleton because it's been constructed statically and this is all completely safe and normal.

        //And then we want some sort of API for actually getting the population from a particular city.So we'll have a function called Get Population.
        //We'll take a string reference, the name of the actual city.
        int get_population(const string& name)
        {
            //return the actual population
            return capitals[name];
        }

};

int main()
{

    // we're going to have our singleton database and to get an instance of it:
    //auto db = SingletonDatabase::get();
    //the copy constructor is deleted, so I notice I'm using the equals here for assignment. But of course your you're not allowed to do that.

    // for a given city, actually let's have string city equals Tokyo.
    string city = "Paris";
    
    //Unfortunately, you can only work with the Singleton database directly, so you're not going to be able
    //to sort of perform a copy anywhere.so we have the Singleton database and now we can actually get the population of a particular city like Tokyo:
    cout << city << " has a population " << 
        SingletonDatabase::get().get_population(city) << '\n';

}