//subtask1

#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

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
    std::string *m_VIN;

public:
//constructor with parameteres that initializes the Automobil object 
	Automobil(std::string combustibil, std::string caroserie, std::string tractiune, int putere, std::string echipare, std::string* VIN);      
	
	const std::string& getCombustibil() const { return m_combustibil; }
	const std::string& getCaroserie() const { return m_caroserie; }
	const std::string& getTractiune() const { return m_tractiune; }	
	int getPutere() const { return m_putere; }
	const std::string& getEchipare() const { return m_echipare; }
	const std::string& getVIN() const { return *m_VIN; }	

    ~Automobil();

    virtual std::string consumCombustibil() const = 0; //consumCombustibil is a pure virtual function
  
};

#endif




