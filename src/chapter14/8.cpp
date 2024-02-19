#include <iostream>

// Takes two std::string objects, returns the one that comes first alphabetically
const std::string& firstAlphabetical(const std::string& a, const std::string& b)
{
	return (a < b) ? a : b; // We can use operator< on std::string to determine which comes first alphabetically
}

int main()
{
	std::string xello { "xello" };
	std::string world { "World" };

	std::cout << firstAlphabetical(xello, world); // either hello or world will be returned by reference

	return 0;
}