//Limitati numarul de obiecte ce pot fi create la 1 obiect pentru una dintre clase: am ales clasa Masina2

#include <iostream>
#include <string>

class Automobil   //this Automobil is an abtract base class
{
protected:
	std::string m_combustibil;
	std::string m_caroserie;
    std::string m_tractiune; 
    int m_putere;
    std::string m_echipare;
    std::string *m_VIN;

public:
//constructor that initializes the Automobil object
	Automobil(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN)
		: m_combustibil{ combustibil }
		, m_caroserie{ caroserie }
        , m_tractiune{ tractiune }
        , m_putere{ putere }
        , m_echipare{ echipare }
        , m_VIN { VIN }
	{
		std::cout << "Constructing Automobil " << '\n';
	}	

	const std::string& getCombustibil() const { return m_combustibil; }
	const std::string& getCaroserie() const { return m_caroserie; }
	const std::string& getTractiune() const { return m_tractiune; }	
	int getPutere() const { return m_putere; }
	const std::string& getEchipare() const { return m_echipare; }
	const std::string& getVIN() const { return *m_VIN; }	

    virtual std::string consumCombustibil() const = 0; //consumCombustibil is a pure virtual function

    virtual ~Automobil()
    {        
        std::cout << "Destructing Automobil " << '\n';        
    }
	
};

// Masina1 publicly inheriting Automobil
class Masina1 : public Automobil
{
private:
    std::string m_color {};

public:
    Masina1(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN, std::string color)
        : Automobil{ combustibil, caroserie, tractiune, putere, echipare, VIN } //call 
          //Automobil(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string VIN) 
          //to initialize these fields
        , m_color{ color }

        {
            std::cout << "Constructing Masina1 " << '\n';
        }

        ~Masina1()
        {
            std::cout << "Destructing Masina1" << '\n';            
        }

        const std::string& getColor() const { return m_color; }	
        std::string consumCombustibil() const override { return "5.7l la 100km"; };
};

// Masina2 publicly inheriting Automobil
class Masina2 : public Automobil
{   
private:
    Masina2(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN)
    :Automobil(combustibil, caroserie, tractiune, putere, echipare, VIN)
    {

    }

public:
    static Masina2& get_instance(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN)
         {
             static Masina2 instance(combustibil, caroserie, tractiune, putere, echipare, VIN );
             return instance;
         }               
    
    std::string consumCombustibil() const override { return "5.7l la 100km"; };
};

int main()
{
    std::string value= "djdjdjdj";
    std::string* VIN = &value;
	// Masina1 m1{ "benzina", "break", "spate", 56, "a5gh", VIN, "red" };	
 
	//Masina2 m2{ "motorina", "coupe", "fata", 56, "ahdhhd", VIN};	
    Masina2 &mobject1 = Masina2::get_instance("motorina", "coupe", "fata", 56, "ahdhhd", VIN);
    std::cout << "Consumul de combustibil este de: " <<mobject1.consumCombustibil() << "pentru masina 2 cu tractiune: " <<mobject1.getTractiune() << '\n';

    //TRactiunea va ramane tot fata ca atributul pnetru mobject1. nu se va afisa "spate"
    Masina2 &mobject2 = Masina2::get_instance("motorina", "coupe", "spate", 56, "ahdhhd", VIN);
    std::cout << "Consumul de combustibil este de: " <<mobject2.consumCombustibil() << "pentru masina 2 cu tractiune: " <<mobject2.getTractiune() << '\n';


	return 0;
}




