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

int main()
{
    // Define some storage units
    Storage<int> i { 5 };
    Storage<double> d { 6.7 };

    // Print out some values
    i.print();
    d.print();
}