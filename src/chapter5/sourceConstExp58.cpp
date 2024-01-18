#include <iostream>

//A constexpr function is a function whose return value may be computed at compile-time. 
//To make a function a constexpr function, we simply use the constexpr keyword in front of the return type. 
constexpr int greater(int x, int y) // now a constexpr function
{
    return (x > y ? x : y);
}

int main()
{
    constexpr int x{ 5 };
    constexpr int y{ 6 };

    // We'll explain why we use variable g here later in the lesson
    constexpr int g { greater(x, y) }; // will be evaluated at compile-time

    std::cout << g << " is greater!\n";

    return 0;
}