#ifndef MASINA2_H
#define MASINA2_H

#include <iostream>
#include <string>

#include "automobil.h"

// Masina2 publicly inheriting Automobil
class Masina2 : public Automobil
{   
private:
    Masina2(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN);

    ~Masina2();

public:
    //static method to acces the singletone instance: in order to not create more than 1 object (design pattern)
    static Masina2& get_instance(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN)
         {
             static Masina2 instance(combustibil, caroserie, tractiune, putere, echipare, VIN );
             return instance;
         }               
    
    std::string consumCombustibil() const override { return "5.7l la 100km"; };
};

#endif