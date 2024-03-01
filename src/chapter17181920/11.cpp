#include <algorithm>
#include <array>
#include <iostream>
#include <string>

bool containsNut(std::string str)
{
	return (str.find("nut") != std::string::npos);
}

int main()
{
	std::array<std::string, 5> arr{ "apple", "banana", "walnut", "lemon", "peanut" };

	auto nuts{ std::count_if(arr.begin(), arr.end(), containsNut) };

	std::cout << "Counted " << nuts << " nut(s)\n";

	return 0;
}