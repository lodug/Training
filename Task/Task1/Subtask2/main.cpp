//subtask2

#include <iostream>
#include <string>

#include "automobil.h"
#include "masina1.h"
#include "masina2.h"

int main()
{
    std::string value= "djdjdjdj";
    std::string* VIN = &value;
	// Masina1 m1{ "benzina", "break", "spate", 56, "a5gh", VIN, "red" };	
 
	//Masina2 m2{ "motorina", "coupe", "fata", 56, "ahdhhd", VIN};	
    Masina2 &mobject1 = Masina2::get_instance("motorina", "coupe", "fata", 56, "ahdhhd", VIN);
    std::cout << "Consumul de combustibil este de: " <<mobject1.consumCombustibil() << "pentru masina 2 cu tractiune: " <<mobject1.getTractiune() << '\n';

    //Tractiunea va ramane tot "fata" ca atributul pnetru mobject1. nu se va afisa "spate", datorita design skeleton pattern care permite restrictia instantierii unei clase la un singur obiect
    Masina2 &mobject2 = Masina2::get_instance("motorina", "coupe", "spate", 56, "ahdhhd", VIN);
    std::cout << "Consumul de combustibil este de: " <<mobject2.consumCombustibil() << "pentru masina 2 cu tractiune: " <<mobject2.getTractiune() << '\n';

	return 0;
}




