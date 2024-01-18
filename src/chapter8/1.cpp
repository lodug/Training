#include <iostream>

namespace constants 
{
    constexpr int minRideHeightCM {140};
}

int main()
{
    std::cout << "Enter your height in cm: ";
    int x{};
    std::cin >> x;

    if (x >= constants::minRideHeightCM)
       std::cout << "You are tall enough. \n";
    else
        std::cout << "You are not tall enough. \n";
        //NOT GOOD: This makes it clearer that “Too bad!” will always execute.   
        std::cout << "Too bad. \n ";  // !!!!This program doesn’t work as expected because the true_statement and false_statement can only be a single statement

    return 0;
}