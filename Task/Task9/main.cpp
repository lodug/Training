// Task9: abstract factory pattern

#include <iostream>

 
// Abstract Product Interface
class Vehicle {
public:
    virtual void drive() = 0;    
};
 
// Concrete HYundai electric vehicle
class HyundaiElectricVehicle : public Vehicle {
public:
    void drive() override
    {
        std::cout << "Driving an electric vehicle Hyundai." << std::endl;
    }  
};
 
// Concrete Hyundai hybrid vehicle
class HyundaiHybridVehicle : public Vehicle {
public:
    void drive() override
    {
        std::cout << "Driving a hybrid vehicle Hyundai." << std::endl;
    }  
};
 
// Concrete Ford electric vehicle
class FordElectricVehicle : public Vehicle {
public:
    void drive() override
    {
        std::cout << "Driving an electric vehicle Ford." << std::endl;
    }  
};
 
// Concrete Ford hybrid vehicle
class FordHybridVehicle : public Vehicle{
public:
     void drive() override
    {
        std::cout << "Driving a hybrid vehicle Ford." << std::endl;
    }  
};
 
// Abstract Factory Interface
class VehicleFactory {
public:
    virtual Vehicle* createElectricVehicle() = 0;
    virtual Vehicle* createHybridVehicle() = 0;
};
 
// Concrete Hyundai Vehicle Factory
class HyundaiVehicleFactory : public VehicleFactory {
public:
    Vehicle* createElectricVehicle() override
    {
        return new HyundaiElectricVehicle();
    }
 
    Vehicle* createHybridVehicle() override
    {
        return new HyundaiHybridVehicle();
    }
};
 
// Concrete Ford Vehicle Factory
class FordVehicleFactory : public VehicleFactory {
public:
    Vehicle* createElectricVehicle() override
    {
        return new FordElectricVehicle();
    }
 
    Vehicle* createHybridVehicle() override
    {
        return new FordHybridVehicle();
    }
};
 
int main()
{
    // Create a Hyundai Vehicle Factory
    VehicleFactory* hyundaiFactory
        = new HyundaiVehicleFactory();
    Vehicle* hyundaiElectricVehicle
        = hyundaiFactory->createElectricVehicle();
    Vehicle* hyundaiHybridVehicle
        = hyundaiFactory->createHybridVehicle();
 
    // Create a Ford Vehicle Factory
    VehicleFactory* fordFactory
        = new FordVehicleFactory();
    Vehicle* fordElectricVehicle
        = fordFactory->createElectricVehicle();
    Vehicle* fordHybridVehicle
        = fordFactory->createHybridVehicle();
 
    // drive vehicle
    hyundaiElectricVehicle->drive();
     
    hyundaiHybridVehicle->drive();
     
    fordElectricVehicle->drive();
     
    fordHybridVehicle->drive();
     
    // Clean up
    delete hyundaiFactory;
    delete hyundaiElectricVehicle;
    delete hyundaiHybridVehicle;
    delete fordFactory;
    delete fordElectricVehicle;
    delete fordHybridVehicle;
 
    return 0;
}