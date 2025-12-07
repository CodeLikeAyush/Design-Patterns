# Vehicle Factory Example

This C++ project demonstrates the **Factory Design Pattern** using `Vehicle`, `Car`, and `Bike` classes.  
The Factory Pattern is a **Creational Design Pattern** that decouples object creation from the client code.

---

## **Complete All-in-One Code & Instructions**

```cpp
// vehicle.hpp
#ifndef VEHICLE_HPP
#define VEHICLE_HPP
class Vehicle {
public:
    virtual void createVehicle() = 0; // Pure virtual function
};
#endif

// car.hpp
#ifndef CAR_HPP
#define CAR_HPP
#include "vehicle.hpp"
#include <iostream>
class Car : public Vehicle {
public:
    void createVehicle() {
        std::cout << "Car created!" << std::endl;
    }
};
#endif

// bike.hpp
#ifndef BIKE_HPP
#define BIKE_HPP
#include "vehicle.hpp"
#include <iostream>
class Bike : public Vehicle {
public:
    void createVehicle() {
        std::cout << "Bike created!" << std::endl;
    }
};
#endif

// vehicle_factory.hpp
#ifndef VEHICLE_FACTORY_HPP
#define VEHICLE_FACTORY_HPP
#include <string>
#include "car.hpp"
#include "bike.hpp"
class VehicleFactory {
public:
    static Vehicle* getVehicle(std::string vehicleType) {
        if (vehicleType == "car" || vehicleType == "Car") {
            return new Car();
        } else if (vehicleType == "bike" || vehicleType == "Bike") {
            return new Bike();
        } else {
            return nullptr;
        }
    }
};
#endif

// main.cpp
#include <iostream>
#include "vehicle_factory.hpp"
int main() {
    std::string vehicleType;
    std::cout << "Vehicle type?: ";
    std::cin >> vehicleType;

    Vehicle* vehicle = VehicleFactory::getVehicle(vehicleType);
    if (vehicle) {
        vehicle->createVehicle();
        delete vehicle; // free memory
    } else {
        std::cout << "Invalid vehicle type!" << std::endl;
    }
    return 0;
}

```

## Compilation & Execution Instructions:

1. Compile Car and Bike:
```cpp
g++ -c vehicle_factory.cpp car.cpp bike.cpp
```
2. Create static library:
```cpp
ar ru vehicle_lib.a vehicle_factory.o car.o bike.o
```
3. Compile Main Program with Library:
```cpp
 g++ -o client client.cpp vehicle_lib.a
 ```

4. Run the program:
```cpp
   ./client
   ```

