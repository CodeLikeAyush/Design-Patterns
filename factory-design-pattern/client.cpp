#include <iostream>

#include "vehicle_factory.hpp"

int main()
{

    std::string vehicleType;
    std::cout << "Vehicle type?: ";
    std::cin >> vehicleType;

    Vehicle *vehicle = VehicleFactory::getVehicle(vehicleType);
    vehicle->createVehicle();

    return 0;
}