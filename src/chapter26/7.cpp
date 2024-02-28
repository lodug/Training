//we can let the compiler implicitly specialize Storage<double> from Storage<T>, and provide an explicit specialization of just Storage<double>::print()! 
//Here’s what that looks like:

#include <iostream>

template <typename T>
class Storage
{
private:
    T m_value {};
public:
    Storage(T value)
      : m_value { value }
    {
    }

    void print()
    {
        std::cout << m_value << '\n';
    }
};

template<>
void Storage<double>::print()
{
    std::cout << std::scientific << m_value << '\n';
}

int main()
{
    // Define some storage units
    Storage<int> i { 5 };
    Storage<double> d { 6.7 }; // will cause Storage<double> to be implicitly instantiated

    // Print out some values
    i.print(); // calls Storage<int>::print (instantiated from Storage<T>)
    d.print(); // calls Storage<double>::print (called from explicit specialization of Storage<double>::print())
}