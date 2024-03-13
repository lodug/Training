//subtask1

#ifndef MASINA1_H
#define MASINA1_H

#include <iostream>
#include <string>

#include "automobil.h"

// Masina1 publicly inheriting Automobil
class Masina1 : public Automobil
{
private:
    std::string m_color {};

public:
    //constructor
    Masina1(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN, std::string color);

    ~Masina1();
        
    const std::string& getColor() const { return m_color; }	
    std::string consumCombustibil() const override { return "5.7l la 100km"; };
};

#endif



