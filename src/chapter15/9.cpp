#include <iostream>

struct Something
{
    static int s_value; // now static; Unlike normal member variables, static member variables are shared by all objects of the class.
    int value{ 1 };
};

int Something::s_value{ 1 }; // initialize s_value to 1

int main()
{
    Something first{};
    Something second{};

    first.s_value = 2;

    std::cout << first.s_value << '\n';
    std::cout << second.s_value << '\n';

    first.value = 2;

    std::cout << first.value << '\n';
    std::cout << second.value << '\n'; 
    //Because s_value is a static member variable, s_value is shared between all objects of the class. Consequently, first.s_value is the same variable as second.s_value
    //Static members are global variables that live inside the scope region of the class.

    return 0;
}