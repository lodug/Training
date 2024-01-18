#include <iostream>

void print(int x)
{
    std::cout << "int " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    short s { 5 };
    print(s);

    return 0;
}

//THe output is int 5. Converting a short to an int is a numeric promotion, whereas converting a short to a double is a numeric conversion. The compiler will favor the option that is a numeric promotion over the option that is a numeric conversion.