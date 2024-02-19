#include <iostream>
#include <string>

// class Employee
// {
// private:
//     std::string m_name{};
//     int m_id{ 0 }; // default member initializer

// public:

//     Employee(std::string name, int id = 0) // default argument for id
//         : m_name{ name }, m_id{ id }
//     {
//         std::cout << "Employee " << m_name << " created\n";
//     }
// };

// int main()
// {
//     Employee e1{ "James" };
//     Employee e2{ "Dave", 42 };
// }

class Employee
{
private:
    static constexpr int default_id { 0 }; // define a named constant with our desired initialization value

    std::string m_name{};
    int m_id{ default_id }; // we can use it here

public:

    Employee(std::string name, int id = default_id) // and we can use it here
        : m_name{ name }, m_id{ id }
    {
        std::cout << "Employee " << m_name << " created\n";
        std::cout << "Employee " << m_id << " created\n";
    }
};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
}