#include <iostream>

int sumTo(int value)
{
    int total{ 0 };
    for (int i{ 1 }; i <= value; ++i)
        total += i;

    return total;
}

int main()
{	
	std::cout << sumTo(4) << '\n'; 
}