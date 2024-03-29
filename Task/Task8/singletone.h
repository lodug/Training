#ifndef SINGLETONE_H
#define SINGLETONE_H

#include <string>
#include <map>

using namespace std;

class SingletonDatabaseCar
{
    private:
        SingletonDatabaseCar();

        map<string, int> cars; 

    public:
        SingletonDatabaseCar(SingletonDatabaseCar const&) = delete;
        //And in addition, what I'm going to do also is I'm going to delete the copy assignment Operator 
        //so you have operator =, which also takes a const reference and you can delete that as well.
        void operator=(SingletonDatabaseCar const&) = delete;
        //So this ensures that nobody can actually replicate this database in any way, shape or form, thereby wasting valuable resources.   

        static SingletonDatabaseCar& get();

        int get_nbCar(const string& name);

};

#endif

