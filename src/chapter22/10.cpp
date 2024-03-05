#include <iostream>
#include <string>

class Name
{
private:
    std::string m_name {};

public:
    Name(std::string name) : m_name{ name }
    {
    }

    Name(const Name& name) = delete;
    Name& operator=(const Name& name) = delete;

    // Create our own swap friend function to swap the members of Name
    friend void swap(Name& a, Name& b) noexcept
    {
        // We avoid recursive calls by invoking std::swap on the std::string member,
        // not on Name
        std::swap(a.m_name, b.m_name);
    }

    Name(Name&& name)
    {
        std::cout << "Move ctor\n";

        swap(*this, name); // Now calling our swap, not std::swap
    }

    Name& operator=(Name&& name)
    {
        std::cout << "Move assign\n";

        swap(*this, name); // Now calling our swap, not std::swap

        return *this;
    }

    const std::string& get() const { return m_name; }
};

int main()
{
    Name n1{ "Alex" };
    n1 = Name{"Joe"}; // invokes move assignment

    std::cout << n1.get() << '\n';

    return 0;
}

//The rule of five says that if the copy constructor, copy assignment, move constructor, 
//move assignment, or destructor are defined or deleted, then each of those functions should be defined or deleted.

//You can delete the move constructor and move assignment using the = delete syntax in the exact same way you can delete 
//the copy constructor and copy assignment.

