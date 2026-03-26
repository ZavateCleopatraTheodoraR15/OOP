#include "RangeRover.h"

RangeRover::RangeRover() {
    setCharacteristics();
}

void RangeRover::setCharacteristics() {
    fuelCapacity = 85.0;
    fuelConsumption = 12.0;
    avgSpeedRain = 95.0;
    avgSpeedSunny = 115.0;
    avgSpeedSnow = 85.0;
    name = "RangeRover";
}