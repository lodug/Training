#include <iostream>
#include <string>

#include "masina2.h"
#include "automobil.h"

//constructor
    Masina2::Masina2(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN)
        : Automobil{ combustibil, caroserie, tractiune, putere, echipare, VIN }         
    {
        std::cout << "Constructing Masina2 " << '\n';
    }

//destructor
    Masina2::~Masina2()
    {
        std::cout << "Destructing Masina2" << '\n';
    }

   