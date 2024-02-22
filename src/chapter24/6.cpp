//classes that use private members, with the BaseballPlayer class calling the appropriate Person constructor 
//to initialize the inherited Person member variables:

#include <iostream>
#include <string>

class Person
{
private:
    std::string m_name;
    int m_age {};

public:
    Person(std::string name = "", int age = 0)
        : m_name{ name }, m_age{ age }
    {

    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{ 
private:
    int m_homeRuns {};

public:
    BaseballPlayer(std::string name = "", int age = 0, int homeRuns = 0)
        : Person{ name, age } // call Person(std::string, int) to initialize these fields
        , m_homeRuns{ homeRuns }
        {

        }

        int getHomeRuns() const { return m_homeRuns; }        
};

int main()
{
    BaseballPlayer pedro{ "Pedro", 32, 42 };

    std::cout << pedro.getName() << '\n';
    std::cout << pedro.getAge() << '\n';   
    std::cout << pedro.getHomeRuns() << '\n';

    return 0;
}