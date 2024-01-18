#include <iostream>
#include <string>

void printValue(std::string y)
{
    std::cout << y << '\n';
} // y is destroyed here

void printValueRef(std::string& y) // type changed to std::string&
{
    std::cout << y << '\n';
} 

int main()
{
    std::string x { "Hello, world!" }; // x is a std::string

    printValue(x); // x is passed by value (copied) into parameter y (expensive)
    printValueRef(x); // x is now passed by reference into reference parameter y (inexpensive)

    return 0;
}