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
    Masina1(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN, std::string color);
 
    ////regula celor 3: trebuie sa avem constructor de copiere; destructor; operator =:

    //destructor
    ~Masina1();
 
    //constructor de copiere   
    Masina1(const Masina1 &m);
   
    //operatorul=
    Masina1& operator=(const Masina1 &m);

    //////regula celor 5: trebuie sa avem constructor de copiere; destructor; operator =, move constructor and move assignment operator
    
    //move constructor
    Masina1(Masina1&& m) noexcept;
 
    //move assignment operator
    Masina1& operator=(Masina1&& m) noexcept;

    const std::string& getColor() const { return m_color; }	
    std::string consumCombustibil() const override { return "5.7l la 100km"; };
};

#endif