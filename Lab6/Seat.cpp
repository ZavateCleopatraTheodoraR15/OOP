#include "Seat.h"

Seat::Seat() {
    setCharacteristics();
}

void Seat::setCharacteristics() {
    fuelCapacity = 55.0;
    fuelConsumption = 7.5;
    avgSpeedRain = 85.0;
    avgSpeedSunny = 110.0;
    avgSpeedSnow = 65.0;
    name = "Seat";
}