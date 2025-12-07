#ifndef vehicle_factory_hpp
#define vehicle_factory_hpp

#include <string>
#include "car.hpp"
#include "bike.hpp"

class VehicleFactory
{
public:
    static Vehicle *getVehicle(std::string vehicleType);
};

#endif