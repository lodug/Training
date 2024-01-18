#include <iostream>

// x and y are out parameters
void getXY(int a, int& x, int& y)
{        
    int sum  = a * 3;
    x = sum + 3;
    y = sum + 5;
}

int main()
{
    int x { 2 };
    int y { 3};

    int a {};
    std::cout << "Enter a: ";
    std::cin >> a;

    // getXY will return the x and y in variables x and y
    getXY(a, x, y);
    std::cout << "x is " << x << '\n';
    std::cout << "y is " << y << '\n';

    return 0;
}

//Using pass by address instead of pass by reference can in some case help make out-parameters more obvious by requiring the caller to pass in the address of objects as arguments.