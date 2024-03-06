#include <iostream>
#include <memory> // for std::shared_ptr and std::weak_ptr

class Resource
{
public:
	std::weak_ptr<Resource> m_ptr {}; // use std::weak_ptr so m_ptr doesn't keep the Resource alive

	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	auto ptr1 { std::make_shared<Resource>() };

	ptr1->m_ptr = ptr1; // m_ptr is now sharing the Resource that contains it

	return 0;
}

//Fix the program below
//so that the Resource is properly deallocated. Do not alter the code in main(): 

// #include <iostream>
// #include <memory> // for std::shared_ptr

// class Resource
// {
// public:
// 	std::shared_ptr<Resource> m_ptr {}; // initially created empty

// 	Resource() { std::cout << "Resource acquired\n"; }
// 	~Resource() { std::cout << "Resource destroyed\n"; }
// };

// int main()
// {
// 	auto ptr1 { std::make_shared<Resource>() };

// 	ptr1->m_ptr = ptr1; // m_ptr is now sharing the Resource that contains it

// 	return 0;
// }