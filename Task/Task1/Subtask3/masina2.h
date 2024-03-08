#ifndef MASINA2_H
#define MASINA2_H

#include <iostream>
#include <string>

#include "automobil.h"

// Masina2 publicly inheriting Automobil
class Masina2 : public Automobil
{
public:
    Masina2(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN);
 
    ~Masina2();

    std::string consumCombustibil() const override { return "4.7l la 100km"; };

};

#endif