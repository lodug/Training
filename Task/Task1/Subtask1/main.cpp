#include <iostream>
#include <string>

#include "automobil.h"
#include "masina1.h"
#include "masina2.h"


int main()
{
    std::string value= "djdjdjdj";
    std::string* VIN = &value;
	Masina1 m1{ "benzina", "break", "spate", 56, "a5gh", VIN, "red" };	
 
	Masina2 m2{ "motorina", "coupe", "fata", 56, "ahdhhd", VIN};	

	return 0;
}




