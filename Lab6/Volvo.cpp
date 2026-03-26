#include "Volvo.h"

Volvo::Volvo() {
    setCharacteristics();
}

void Volvo::setCharacteristics() {
    fuelCapacity = 60.0;
    fuelConsumption = 8.5;
    avgSpeedRain = 90.0;
    avgSpeedSunny = 120.0;
    avgSpeedSnow = 70.0;
    name = "Volvo";
}