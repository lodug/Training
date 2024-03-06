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
	// allocate a Resource object and have it owned by std::shared_ptr
	Resource* res { new Resource };
	std::shared_ptr<Resource> ptr1{ res };
	{
		std::shared_ptr<Resource> ptr2 { ptr1 }; // make another std::shared_ptr pointing to the same thing

		std::cout << "Killing one shared pointer\n";
	} // ptr2 goes out of scope here, but nothing happens

	std::cout << "Killing another shared pointer\n";

	return 0;
} // ptr1 goes out of scope here, and the allocated Resource is destroyed

//created a dynamic Resource object, and set a std::shared_ptr named ptr1 to manage it. 
//Inside the nested block, we use the copy constructor to create a second std::shared_ptr (ptr2) 
//that points to the same Resource. When ptr2 goes out of scope, the Resource is not deallocated, 
//because ptr1 is still pointing at the Resource. When ptr1 goes out of sco
// it deallocates the Resource.