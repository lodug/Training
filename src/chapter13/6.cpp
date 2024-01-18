#include <iostream>

struct Website
{
    int ads {};
    double Percentage {};
    double averageEarnings {};
};

Website getWeb()
{
    Website info {};
    std::cout << "ads: ";
    std::cin >> info.ads;
    std::cout << "percentage: ";
    std::cin >> info.Percentage;
    std::cout << "average earnings: ";
    std::cin >> info.averageEarnings;

    return info;
}

void printWeb(const Website& web)
{
    std::cout << "ads: " << web.ads << '\n';
    std::cout << "percentage: " << web.Percentage << '\n';
    std::cout << "average earnings: " << web.averageEarnings << '\n';
   
    std::cout << "Total: " <<
        (web.ads * web.Percentage / 100 * web.averageEarnings) << '\n';
}

int main()
{
    // Declare an Website struct variable
    Website web { getWeb() };
    printWeb(web);

    return 0;
}