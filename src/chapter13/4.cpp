#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

int main()
{
    Employee joe {};

    joe.age = 20;  // use member selection operator (.) to select the age member of variable joe

    std::cout << joe.age << '\n'; // print joe's age

    Employee john {};
    john.age = 20;

    if (joe.age > john.age)
        std::cout << "Joe is older than John\n";
    else if (joe.age < john.age)
        std::cout << "Joe is younger than John\n";
    else
        std::cout << "Joe and John are the same age\n";

    return 0;
}