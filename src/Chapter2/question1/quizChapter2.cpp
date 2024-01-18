#include <iostream>

int readNumber() 
{
    std::cout << "Get an integer: ";
    int x{};
    std::cin >> x;

    return x;
}

void writeAnswer(int value) 
{
    std::cout << "the sum is: " << value << '\n';
}

int main() 
{
    int first { readNumber() };
    int second { readNumber() };
    writeAnswer(first + second);
    return 0;

}