#include <iostream>
#include <string>

#include "masina1.h"
#include "automobil.h"

//constructor
Masina1::Masina1(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN, std::string color)
: Automobil{ combustibil, caroserie, tractiune, putere, echipare, VIN }
, m_color{ color }
{
    std::cout << "Constructing Masina1 " << '\n';
}

Masina1::~Masina1()
{
    std::cout << "Destructing Masina1" << '\n';            
}
