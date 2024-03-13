//subtask3

#include <iostream>
#include <string>

#include "masina1.h"
#include "automobil.h"

//constructor
Masina1::Masina1(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN, std::string color)
    : Automobil{ combustibil, caroserie, tractiune, putere, echipare, VIN } //call 
    , m_color{ color }

{
    std::cout << "Constructing Masina1 " << '\n';
}

////regula celor 3: trebuie sa avem constructor de copiere; destructor; operator =:

//destructor
Masina1::~Masina1()
{
    std::cout << "Destructing Masina1" << '\n';
}
    
//constructor de copiere   
Masina1::Masina1(const Masina1 &m) :  Automobil(m), m_color(m.m_color)
{  
    std::cout << "constructor de copiere" << '\n';  
}

//operatorul=
Masina1 &Masina1::operator=(const Masina1 &m)
{  
    if (this != &m)
    {
        Automobil::operator=(m);
        m_color = m.m_color;
    }
    std::cout << "operatorul=" << '\n';  
    return *this;
}

//////regula celor 5: trebuie sa avem constructor de copiere; destructor; operator =, adica regula 3 + move constructor and move assignment operator
    
 //move constructor
Masina1::Masina1(Masina1&& m) noexcept : Automobil(std::move(m)), m_color(std::move(m.m_color))
{  
    std::cout << "Move Constructor" << '\n';         
}

//move assignment operator
Masina1 &Masina1::operator=(Masina1&& m) noexcept
{  
    if (this != &m)
    {       
        Automobil::operator=(std::move(m));                    
        m_color = std::move(m.m_color);
    }
    std::cout << "MOve assignment operator" << '\n';  
    return *this;        
}
