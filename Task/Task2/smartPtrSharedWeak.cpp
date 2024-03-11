#include <iostream>
#include <memory> 

//std::shared_ptr - std::weak -> this program demonstrates the circular reference problem

class Automobil
{		
private:
    int m_power;

public:
	Automobil(int power = 0) :
		m_power{ power }
	{
        std::cout << "constructor m_power =" << m_power << '\n';
	}

    ~Automobil()
    {
        std::cout << "destructor m_power =" << m_power << '\n';
    }       
};

int main()
{
    // creating shared pointer
    std::shared_ptr<Automobil> sharedPtr1 = std::make_shared<Automobil>(30);
    std::shared_ptr<Automobil> sharedPtr2 = sharedPtr1;
 
    // creating weak pointer to the previously created shared objects
    std::shared_ptr<Automobil> sharedPtr3 = std::make_shared<Automobil>(50); 
    std::weak_ptr<Automobil> weakPtr = sharedPtr3;
   
 
    // // Access objects using weak_ptr
    // if (!weakObjectAutomobil.expired()) {
    //     std::cout << "The value stored in sharedObjectAutomobil:"
    //          << (*weakObjectAutomobil.lock()).m_power << '\n';
    // }
 
    // // deleting object
    // sharedObjectAutomobil.reset();
    // std::cout << "End of the Program" << '\n';
 
    return 0;
}

//created a shared_ptr with the ownership of a dynamically created object. 
//Then we created a weak_ptr which refers to the same resource as that of shared_ptr. 
//After resetting the shared_ptr, we can see that its is destroyed and deallocated from the memory.

//The primary application of weak_ptr is to prevent circular references. When an object wants to reference another object without owning it, it can use weak_ptr. 
//This ensures that no circular references are created and objects can be safely freed when they are no longer needed.

// // //weak pointer:
//     std::weak_ptr<std::string> weakPtr(sharedPtr2);
//     std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << '\n';
//     std::cout << "sharedPtr2.use_count(): " << sharedPtr2.use_count() << '\n';
//     std::cout << "weakPtr.expired(): " << weakPtr.expired() << '\n';

//     std::cout << '\n';

//     if (std::shared_ptr<std::string> sharedPtr3 = weakPtr.lock())
//     {
//         std::cout << "*sharedPtr2: " << *sharedPtr2 << '\n';
//         std::cout << "sharedPtr3.use_count(): " << sharedPtr3.use_count() << '\n';
//     }
//     else
//     {
//         std::cout << "Don't get the resource " << '\n';
//     }

//     std::cout << '\n';

//     weakPtr.reset();
//     if (std::shared_ptr<std::string> sharedPtr3 = weakPtr.lock())
//     {
//         std::cout << "*sharedPtr2: " << *sharedPtr2 << '\n';
//         std::cout << "sharedPtr3.use_count(): " << sharedPtr3.use_count() << '\n';
//     }
//     else
//     {
//         std::cout << "Don't get the resource! " << '\n';
//     }

//     std::cout << '\n';