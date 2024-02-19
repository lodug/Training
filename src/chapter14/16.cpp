#include <iostream>
#include <string>

// class Employee
// {
// private:
//     std::string m_name{};
//     int m_id{ 0 };

//     void printCreated() const
//     {
//         std::cout << "Employee " << m_name << " created\n";
//     }

// public:
//     Employee(std::string name)
//         : m_name{ name }
//     {
//         printCreated();
//     }

//     Employee(std::string name, int id)
//         : m_name{ name }, m_id{ id }
//     {
//         printCreated();
//     }
// };

class Employee
{
private:
    std::string m_name{};
    int m_id{ 0 };

public:
    Employee(std::string name)
        : Employee{ name, 1 } // delegate initialization to Employee(std::string_view, int) constructor
    {
    }

    Employee(std::string name, int id)
        : m_name{ name }, m_id{ id } // actually initializes the members
    {
        std::cout << "Employee " << m_name << " created\n";
        std::cout << "ID " << m_id << " created\n";
    }

};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
}