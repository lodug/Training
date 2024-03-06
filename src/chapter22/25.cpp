#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	auto ptr1{ std::make_shared<Resource>() };
	auto ptr2{ ptr1 };

	return 0;
}

//modified the program below to be best practices compliant
// #include <iostream>
// #include <memory> // for std::shared_ptr

// class Resource
// {
// public:
// 	Resource() { std::cout << "Resource acquired\n"; }
// 	~Resource() { std::cout << "Resource destroyed\n"; }
// };

// int main()
// {
// 	auto* res{ new Resource{} };
// 	std::shared_ptr<Resource> ptr1{ res };
// 	std::shared_ptr<Resource> ptr2{ res };

// 	return 0;
// }

//ptr2 was created from res instead of from ptr1. 
//This means that you now have two std::shared_ptr each independently trying to manage the 
//Resource (they are not aware of each other). 
//When one goes out of scope, the other will be left with a dangling pointer.

//ptr2 should be copied from ptr1 instead of from res, and std::make_shared() should be used