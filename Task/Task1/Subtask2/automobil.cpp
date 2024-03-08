#include "automobil.h"

//constructor with parameteres that initializes the Automobil object 
	Automobil::Automobil(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN)
		: m_combustibil{ combustibil }
		, m_caroserie{ caroserie }
        , m_tractiune{ tractiune }
        , m_putere{ putere }
        , m_echipare{ echipare }
        , m_VIN { VIN }
	{
		std::cout << "Constructing Automobil " << '\n';
	}	

    Automobil:: ~Automobil()
    {        
        std::cout << "Destructing Automobil " << '\n';        
    }