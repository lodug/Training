#include <iostream>

// struct Employee
// {
//     int id {};
//     int age {};
//     double wage {};
// };

// struct Company
// {
//     int numberOfEmployees {};
//     Employee CEO {}; // Employee is a struct within the Company struct
// };


// OR

struct Company
{
    struct Employee // accessed via Company::Employee
    {
        int id{};
        int age{};
        double wage{};
    };

    int numberOfEmployees{};
    Employee CEO{}; // Employee is a struct within the Company struct
};

int main()
{
    Company myCompany{ 7, { 1, 32, 55000.0 } }; // Nested initialization list to initialize Employee
    std::cout << myCompany.CEO.wage << '\n'; // print the CEO's wage
    std::cout << myCompany.numberOfEmployees << '\n'; // print the CEO's wage

    ++myCompany.numberOfEmployees; //a new employee joined the company
    std::cout << myCompany.numberOfEmployees << '\n'; // print the CEO's wage

    return 0;
}