#include <cstddef> // for std::size_t
#include <exception> // for std::exception
#include <iostream>
#include <limits>
#include <string> // for this example

int main()
{
    try
    {
        // Your code using standard library goes here
        // We'll trigger one of these exceptions intentionally for the sake of the example
        std::string s;
        s.resize(std::numeric_limits<std::size_t>::max()); // will trigger a std::length_error or allocation exception
    }
    // This handler will catch std::exception and all the derived exceptions too
    catch (const std::exception& exception)
    {
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }
    
    return 0;
}

//The above example should be pretty straightforward. The one thing worth noting is that std::exception has a 
//virtual member function named what() that returns a C-style string description of the exception. 
//Most derived classes override the what() function to change the message.
// Note that this string is meant to be used for descriptive text only -- do not use it for comparisons, as it is not guaranteed to be the same across compilers.