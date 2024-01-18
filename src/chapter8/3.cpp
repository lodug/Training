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
    //However, it’s common to want to execute multiple statements based on some condition. 
    //To do so, we can use a compound statement (block):
    //Remember that blocks are treated as a single statement, so this now works as expected:
    {//ADDITION OF BLOCK HERE
        std::cout << "You are not tall enough to ride.\n";
        std::cout << "Too bad!\n";
    }

    return 0;
}