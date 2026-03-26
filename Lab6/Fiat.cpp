#include "Fiat.h"

Fiat::Fiat() {
    setCharacteristics();
}

void Fiat::setCharacteristics() {
    fuelCapacity = 45.0;
    fuelConsumption = 6.5;
    avgSpeedRain = 80.0;
    avgSpeedSunny = 105.0;
    avgSpeedSnow = 60.0;
    name = "Fiat";
}