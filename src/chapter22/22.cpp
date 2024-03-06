#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
	std::shared_ptr<Resource> m_ptr {}; // initially created empty

	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	auto ptr1 { std::make_shared<Resource>() };

	ptr1->m_ptr = ptr1; // m_ptr is now sharing the Resource that contains it

	return 0;
}

//when ptr1 goes out of scope, the Resource is not deallocated because the Resource’s m_ptr is sharing the Resource. At that point, the only way for the Resource to be released would be to set m_ptr to something else (so nothing is sharing the Resource any longer). But we can’t access m_ptr because ptr1 is out of scope, so we no longer have a way to do this. 
//The Resource has become a memory leak.
//see next file a code that behaves properly