#include <iostream>
#include <string>

// Implementati o clasa utilitara ale carei functii sa poata fi apelate fara a folosi un obiect (functii de printare custom, de calcul al mediei etc)

class Automobil  
{
public:
    ////added a method that can be called without using an object: for this there is need of a static member function
	static void calculMedie(double consumZiua1, double consumZiua2)
    {
        std::cout << "Media consumului de combustibil in 2 zile este: " << (consumZiua1 + consumZiua2)/2.0 << '\n';
    }    

    //added a method that can be called without using an object: for this there is need of a static member function
    static void print(const std::string& consumCombustibil)  
    {  
        std::cout <<  consumCombustibil << '\n';
    }  

};

int main()
{
    double consumZiua1 = 34.0;
    double consumZiua2 = 36.7;
    
    Automobil::calculMedie(consumZiua1, consumZiua2);

    Automobil::print("consumul de combustibil");

    return 0;
}
