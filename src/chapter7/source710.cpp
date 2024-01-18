#include <iostream>

int generateID()
{
    static int s_itemID{ 0 };
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}

void incrementAndPrint()
{
    static int s_value{ 1 }; // static duration via static keyword.  This initializer is only executed once.
    ++s_value;
    std::cout << s_value << '\n';
} // s_value is not destroyed here, but becomes inaccessible because it goes out of scope

void incrementPrint()
{
    int value{ 1 }; // automatic duration by default
    ++value;
    std::cout << value << '\n';
} // value is destroyed here


int main()
{
    std::cout << "print: " << generateID() << '\n';
    std::cout << "print: " << generateID() << '\n';
    std::cout << "print: " << generateID() << '\n';
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();
    incrementPrint();
    incrementPrint();
    incrementPrint();
    return 0;
}