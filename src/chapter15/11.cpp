#include <iostream>

class Something
{
private:
    static inline int s_idGenerator { 1 };
    int m_id {};

public:
    // grab the next value from the id generator
    Something() : m_id { s_idGenerator++ }
    {
    }

    int getID() const { return m_id; }
};

int main()
{
    Something first{};
    Something second{};
    Something third{};

    std::cout << first.getID() << '\n';
    std::cout << second.getID() << '\n';
    std::cout << third.getID() << '\n';
    return 0;
}

//Because s_idGenerator is shared by all Something objects, when a new Something object is created, the constructor initializes 
//m_id with the current value of s_idGenerator and then increments the value for the next object. 
//This guarantees that each instantiated Something object receives a unique id (incremented in the order of creation).