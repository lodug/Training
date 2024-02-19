#include <iostream>

// class Date // now a class instead of a struct
// {
//     // class members are private by default, can only be accessed by other members
//     int m_year {};     // private by default
//     int m_month {};    // private by default
//     int m_day {};      // private by default

//     void print() const // private by default
//     {
//         // private members can be accessed in member functions
//         std::cout << m_year << '/' << m_month << '/' << m_day;
//     }
// };

// int main()
// {
//     Date today { 2020, 10, 14 }; // compile error: can no longer use aggregate initialization

//     // private members can not be accessed by the public
//     today.m_day = 16; // compile error: the m_day member is private
//     today.print();    // compile error: the print() member function is private

//     return 0;
// }

class Date
{
// Any members defined here would default to private

public: // here's our public access specifier

    void print() const // public due to above public: specifier
    {
        // members can access other private members
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }

private: // here's our private access specifier

    int m_year { 2020 };  // private due to above private: specifier
    int m_month { 14 }; // private due to above private: specifier
    int m_day { 10 };   // private due to above private: specifier
};

int main()
{
    Date d{};
    d.print();  // okay, main() allowed to access public members

    return 0;
}