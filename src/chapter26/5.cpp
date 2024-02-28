//Class template specialization allows us to specialize a template class for a particular data type (or data types, if there are multiple template parameters). 
//In this case, we’re going to use class template specialization to write a customized version of Storage8<bool> that will take precedence over the generic Storage8<T> class.

//Class template specializations are treated as completely independent classes, even though they are allocated in the same way as the templated class. 
//This means that we can change anything and everything about our specialization class, 
//including the way it’s implemented and even the functions it makes public, just as if it were an independent class. 
//Note that a class template specialization requires the class that it is specializing to be defined first.

#include <cstdint>
#include <iostream>

// First define our non-specialized class template
template <typename T>
class Storage8
{
private:
    T m_array[8];

public:
    void set(int index, const T& value)
    {
        m_array[index] = value;
    }

    const T& get(int index) const
    {
        return m_array[index];
    }
};

// Now define our specialized class template
template <> // the following is a template class with no templated parameters
class Storage8<bool> // we're specializing Storage8 for bool
{
// What follows is just standard class implementation details

private:
    std::uint8_t m_data{};

public:
    // Don't worry about the details of the implementation of these functions
    void set(int index, bool value)
    {
        // Figure out which bit we're setting/unsetting
        // This will put a 1 in the bit we're interested in turning on/off
        auto mask{ 1 << index };

        if (value)  // If we're setting a bit
            m_data |= mask;   // use bitwise-or to turn that bit on
        else  // if we're turning a bit off
            m_data &= ~mask;  // bitwise-and the inverse mask to turn that bit off
	}

    bool get(int index)
    {
        // Figure out which bit we're getting
        auto mask{ 1 << index };
        // bitwise-and to get the value of the bit we're interested in
        // Then implicit cast to boolean
        return (m_data & mask);
    }
};

int main()
{
    // Define a Storage8 for integers (instantiates Storage8<T>, where T = int)
    Storage8<int> intStorage;

    for (int count{ 0 }; count < 8; ++count)
    {
        intStorage.set(count, count);
	}

    for (int count{ 0 }; count < 8; ++count)
    {
        std::cout << intStorage.get(count) << '\n';
    }

    // Define a Storage8 for bool  (instantiates Storage8<bool> specialization)
    Storage8<bool> boolStorage;

    for (int count{ 0 }; count < 8; ++count)
    {
        boolStorage.set(count, count & 3);
    }

	std::cout << std::boolalpha;

    for (int count{ 0 }; count < 8; ++count)
    {
        std::cout << boolStorage.get(count) << '\n';
    }

    return 0;
}