//subtask3

#include <iostream>
#include <string>

#include "../include/automobil.h"
#include "../include/masina1.h"
#include "../include/masina2.h"


int main()
{
    std::string value= "djdjdjdj";
    std::string* VIN = &value;
	Masina1 m1{ "benzina", "break", "spate", 56, "a5gh", VIN, "red" };	
 
	Masina2 m2{ "motorina", "coupe", "fata", 56, "ahdhhd", VIN};	

    //apel constructor de copiere
    Masina1 m3(m1);    
    // saul apeleaza astfel:
    Masina1 m4 = m1;

    Masina1 m5{ "benzina", "break", "spate", 50, "a5gh", VIN, "white" };
    //apel operatorul=
    m5 = m4;

    //apel move constructor:
    Masina1 m6 = std::move(m5);

    //create an object using Move assignment operator
    Masina1 m7("benzina", "break", "fata", 60, "a5gh", VIN, "blue");
    m7 = std::move(m6);   

    // //some testing
    // std::cout << "Masina1(" << m7.getCombustibil() << ", " << m7.getCaroserie() << ", " << m7.getTractiune() << ", " << m1.getPutere() 
    //           <<  ", " << m7.getEchipare() << ", " << m7.getVIN() << ", " << m7.getColor() << ')' << '\n';

    // std::cout << "Masina1(" << m7.getCombustibil() << ", " << m7.getCaroserie() << ", " << m7.getTractiune() << ", " << m3.getPutere() 
    //           <<  ", " << m7.getEchipare() << ", " << m7.getVIN() << ", " << m7.getColor() << ')' << '\n';

    // std::cout << "Masina1(" << m7.getCombustibil() << ", " << m7.getCaroserie() << ", " << m7.getTractiune() << ", " << m7.getPutere() 
    //           <<  ", " << m7.getEchipare() << ", " << m7.getVIN() << ", " << m7.getColor() << ')' << '\n';

    // std::cout << "Masina1(" << m7.getCombustibil() << ", " << m7.getCaroserie() << ", " << m7.getTractiune() << ", " << m5.getPutere() 
    //           <<  ", " << m7.getEchipare() << ", " << m7.getVIN() << ", " << m7.getColor() << ')' << '\n';

    // std::cout << "Masina1(" << m7.getCombustibil() << ", " << m7.getCaroserie() << ", " << m7.getTractiune() << ", " << m6.getPutere() 
    //           <<  ", " << m7.getEchipare() << ", " << m7.getVIN() << ", " << m7.getColor() << ')' << '\n';

    // std::cout << "Masina1(" << m7.getCombustibil() << ", " << m7.getCaroserie() << ", " << m7.getTractiune() << ", " << m4.getPutere() 
    //           <<  ", " << m7.getEchipare() << ", " << m7.getVIN() << ", " << m7.getColor() << ')' << '\n';                          

	return 0;
}