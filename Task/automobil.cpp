#include <iostream>
#include <string>

class Automobil   //this Automobil is an abtract base class
{
private:
	std::string m_combustibil;
	std::string m_caroserie;
    std::string m_tractiune; 
    int m_putere;
    std::string m_echipare;
    std::string m_VIN;

public:
//constructor that initializes the Automobil object
	Automobil(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string VIN)
		: m_combustibil{ combustibil }
		, m_caroserie{ caroserie }
        , m_tractiune{ tractiune }
        , m_putere{ putere }
        , m_echipare{ echipare }
        , m_VIN { VIN }
	{
		// std::cout << "Constructing Automobil " << '\n';
	}

	// ~Automobil()
    // {
    //     std::cout << "Destructing Automobil" << '\n';
    // }

	const std::string& getCombustibil() const { return m_combustibil; }
	const std::string& getCaroserie() const { return m_caroserie; }
	const std::string& getTractiune() const { return m_tractiune; }	
	int getPutere() const { return m_putere; }
	const std::string& getEchipare() const { return m_echipare; }
	const std::string& getVIN() const { return m_VIN; }	

    virtual std::string consumCombustibil() const = 0; //consumCombustibil is a pure virtual function

    virtual ~Automobil() = default;

	// void print() const
	// {
	// 	std::cout << "Automobil cu urmatoarele caracteristici:\n (" "Combustibil: " << m_combustibil << '\n' << ", " << m_caroserie << ", " << m_tractiune << ", " << m_putere << ", " << m_echipare << ", " << m_VIN <<" )\n";
	// }
};

// Masina1 publicly inheriting Automobil
class Masina1 : public Automobil
{
private:
    std::string m_color {};

public:
    Masina1(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string VIN, std::string color)
        : Automobil{ combustibil, caroserie, tractiune, putere, echipare, VIN } //call 
          //Automobil(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string VIN) 
          //to initialize these fields
        , m_color{ color }

        {
        }

        const std::string& getColor() const { return m_color; }	
        std::string consumCombustibil() const override { return "5.7l la 100km"; };
};

// Masina2 publicly inheriting Automobil
class Masina2 : public Automobil
{
public:
    Masina2(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string VIN)
        : Automobil{ combustibil, caroserie, tractiune, putere, echipare, VIN } //call 
          //Automobil(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string VIN) 
          //to initialize these fields
        
        {
        }

        std::string consumCombustibil() const override { return "4.7l la 100km"; };

};

int main()
{
	Masina1 m1{ "benzina", "break", "spate", 56, "a5gh", "djdjdjdj", "red" };
	// std::cout << "Masina1(" << m1.getCombustibil() << ", " << m1.getCaroserie() << ", " << m1.getTractiune() << ", " << m1.getPutere() 
    //           <<  ", " << m1.getEchipare() << ", " << m1.getVIN() << ", " << m1.getColor() << ')' << '\n';
    std::cout << "Masina1 are un consum de " << m1.consumCombustibil() << " de " << m1.getCombustibil() << '\n';

	// Masina2 m2{ "motorina", "coupe", "fata", 56, "ahdhhd", "bbb"};
	// std::cout << "Masina2(" << m2.getCombustibil() << ", " << m2.getCaroserie() << ", " << m2.getTractiune() << ", " << m2.getPutere() 
    //           <<  ", " << m2.getEchipare() << ", " << m2.getVIN() << ')' << '\n';

	return 0;
}




