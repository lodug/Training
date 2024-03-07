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

//constructor with parameteres that initializes the Automobil object
	Automobil(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN)
		: m_combustibil{combustibil }
		, m_caroserie{ caroserie }
        , m_tractiune{ tractiune }
        , m_putere{ putere }
        , m_echipare{ echipare }
        , m_VIN { VIN }
	{
		std::cout << "Constructing Automobil " << '\n';
	}	

     virtual ~Automobil()
    {        
        std::cout << "Destructing Automobil " << '\n';        
    }

	const std::string& getCombustibil() const { return m_combustibil; }
	const std::string& getCaroserie() const { return m_caroserie; }
	const std::string& getTractiune() const { return m_tractiune; }	
	int getPutere() const { return m_putere; }
	const std::string& getEchipare() const { return m_echipare; }
	const std::string& getVIN() const { return *m_VIN; }	   
      
    virtual std::string consumCombustibil() const = 0; //consumCombustibil is a pure virtual function	
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

    ////regula celor 3: trebuie sa avem constructor de copiere; destructor; operator =:

    //destructor
    ~Masina1()
    {
        std::cout << "Destructing Masina1" << '\n';
    }
    
    //constructor de copiere   
    Masina1(const Masina1 &m) :  Automobil(m), m_color(m.m_color)
    {  
        std::cout << "constructor de copiere" << '\n';  
    }

    //operatorul=
    Masina1& operator=(const Masina1 &m)
    {  
        if (this != &m)
        {
            Automobil::operator=(m);
            m_color = m.m_color;
        }
        std::cout << "operatorul=" << '\n';  
        return *this;
    }

    //////regula celor 5: trebuie sa avem constructor de copiere; destructor; operator =, move constructor and move assignment operator
    
    //move constructor
    Masina1(Masina1&& m) noexcept : Automobil(std::move(m)), m_color(std::move(m.m_color))
    {  
        std::cout << "Move Constructor" << '\n';         
    }

    //move assignment operator
    Masina1& operator=(Masina1&& m) noexcept
    {  
        if (this != &m)
        {       
            Automobil::operator=(std::move(m));                    
            m_color = std::move(m.m_color);
        }
        std::cout << "MOve assignment operator" << '\n';  
        return *this;        
    }

    const std::string& getColor() const { return m_color; }	
    std::string consumCombustibil() const override { return "5.7l la 100km"; };
};

// Masina2 publicly inheriting Automobil
class Masina2 : public Automobil
{
public:
    Masina2(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN)
        : Automobil{ combustibil, caroserie, tractiune, putere, echipare, VIN } //call 
          //Automobil(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string VIN) 
          //to initialize these fields
        
    {
        std::cout << "Constructing Masina2 " << '\n';
    }

    ~Masina2()
    {
        std::cout << "Destructing Masina2" << '\n';
    }

    std::string consumCombustibil() const override { return "4.7l la 100km"; };

};

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

	return 0;
}