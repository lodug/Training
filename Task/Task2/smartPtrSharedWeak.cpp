#include <iostream>
#include <memory> 

//std::shared_ptr - std::weak -> this program demonstrates the circular reference problem

class Automobil
{		   
public:

    int m_power;

	Automobil(int power = 0) :
		m_power{ power }
	{
        std::cout << "object created with value: " << m_power << '\n';
	}

    ~Automobil()
    {
        std::cout << "object destroyed with value: " << m_power << '\n';
    }       
};

int main()
{
    // creating shared pointer which is pointing to object holding 30
    std::shared_ptr<Automobil> sharedPtr = std::make_shared<Automobil>(30);

    // creating am weak pointer by assign it a shared pointer: weak pointer references to an object which is managed by shared pointer
    // to create a weak pointer there is need of a shared pointer
    std::weak_ptr<Automobil> weakPtr(sharedPtr);   
    // //can be also written like this the row above
    // std::weak_ptr<Automobil> weakPtr = sharedPtr; 
 
    // Access objects using weak_ptr
    if (!weakPtr.expired()) {
        std::cout << "The value stored in ssharedPtr:"
             << (*weakPtr.lock()).m_power << '\n';
    }
 
    // deleting object
    sharedPtr.reset();
    std::cout << "End of the Program" << '\n';
 
    return 0;
}

//created a shared_ptr with the ownership of a dynamically created object. 
//Then we created a weak_ptr which refers to the same resource as that of shared_ptr. 
//After resetting the shared_ptr, we can see that its is destroyed and deallocated from the memory.

//unique pointer is for unique ownership 
// shared pointer for shared ownership
// weak pointre if for non ownership: it references to an object managed by shared pointer (created as a copy of shared_ptr), used to remove 
//The primary application of weak_ptr is to prevent circular references. When an object wants to reference another object without owning it, it can use weak_ptr. 
//This ensures that no circular references are created and objects can be safely free when they are no longer needed.