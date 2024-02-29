#include <iostream>

int main()
{
    char ch{};
    while (std::cin >> ch)
    std::cout << ch;

    char ch1{};
    while (std::cin.get(ch1))
    std::cout << ch1;

    char strBuf[11]{};
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n'; 

    return 0;
}