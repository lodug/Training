#include <iostream>

class Simple
{
private:
    int m_id{};

public:
    Simple(int id)
        : m_id{ id }
    {
    }

    int getID() { return m_id; }
    void setID(int id) { m_id = id; }

    void print() { std::cout << this->m_id; } // use `this` pointer to access the implicit object and operator-> to select member m_id
    //We use -> to select a member from a pointer to an object. this->m_id is the equivalent of (*this).m_id.
    //void print() { std::cout << m_id; }       // implicit use of this
    //void print() { std::cout << this->m_id; } // explicit use of this
    //The hidden this pointer: Inside every member function, the keyword this is a const pointer that holds the address of the current implicit object.Most of the time, we don’t mention this explicitly, but just to prove we can:
};

int main()
{
    Simple simple{ 1 };
    simple.setID(2);

    simple.print();

    return 0;
}