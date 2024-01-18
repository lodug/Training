#include <iostream>

// int main()
// {
//     int i { 3.5 }; // won't compile

//     return 0;
// }

int main()
{
    double d { 3.5 };

    // static_cast<int> converts double to int, initializes i with int result
    int i { static_cast<int>(d) };

    return 0;
}