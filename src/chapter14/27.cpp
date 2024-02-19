#include <iostream>
#include <string>

class Employee
{
private:
    std::string m_name{};

public:
    Employee(std::string name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
};

void printEmployee(Employee e) // has an Employee parameter
{
    std::cout << e.getName();
}

int main()
{
    printEmployee(Employee{"Joe"}); // we're supplying an string literal argument
  
    return 0;
}