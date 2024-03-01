#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7 };

	auto it{ v.begin() };

	++it; // move to second element
	std::cout << *it << '\n';

	it = v.erase(it); // erase the element currently being iterated over, set `it` to next element

	std::cout << *it << '\n'; // now ok, prints 3

	return 0;
}