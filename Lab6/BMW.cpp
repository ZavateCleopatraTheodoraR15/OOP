#include "BMW.h"

BMW::BMW() {
    setCharacteristics();
}

void BMW::setCharacteristics() {
    fuelCapacity = 65.0;
    fuelConsumption = 9.0;
    avgSpeedRain = 100.0;
    avgSpeedSunny = 140.0;
    avgSpeedSnow = 80.0;
    name = "BMW";
}