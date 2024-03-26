//the goal of the observer design pattern is to get notifications of particular changes in the system or just particular events happening in the system.
//in this case, we want to track every single instance when somebody changes the age
//So we're going to implement this by using the observer design pattern, which has two components to it: the observer and the observer role.
//So the observer is that thing which wants to monitor something and the observable is the component that is to be monitored.
//So in this case our person is the observable and the observer is something that we're going to build.

#include "Headers.h"
#include <string>
#include "Observer.h"

using namespace std;

class Person : //observable
{
    int age;
    
public:
    //getter
    int get_age() const
    {
        return age;
    }

    //setter
    void set_age(int age)
    {
        Person::age = age;
    }
};

// observer & observable
//make an observer which prints stuff to the console: implement the observer of person interface
struct ConsolePersonObserver 
    : public Observer<Person>
{
    private:
    void Observer::field_changed(Person &source, const std::string &field_name) override
    {
        cout << "Person's " << field_name << " has changed to ";
        if (field_name == "age") cout << source.get_age();        
            cout << ".\n";
    }
};

int main(int ac, char* av[])
{
    return 0;
}