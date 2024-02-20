#include <iostream>

class Something
{
public:
    static int s_value; // declares the static member variable
};

int Something::s_value{ 1 }; // defines the static member variable 

int main()
{
    // note: we're not instantiating any objects of type Something

    Something::s_value = 2;
    //s_value is referenced by class name Something rather than through an object. Note that we have not even instantiated an object of type Something, 
    //but we are still able to access and use Something::s_value. This is the preferred method for accessing static members.
    std::cout << Something::s_value << '\n';
    return 0;
}