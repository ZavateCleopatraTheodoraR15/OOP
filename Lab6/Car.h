#include "Weather.h"
#include <string>

class Car {
protected:
    double fuelCapacity;
    double fuelConsumption;
    double avgSpeedRain;
    double avgSpeedSunny;
    double avgSpeedSnow;
    std::string name;

public:
    Car() : fuelCapacity(0), fuelConsumption(0), avgSpeedRain(0), avgSpeedSunny(0), avgSpeedSnow(0) {}

    virtual ~Car() = default;

    virtual double getFuelCapacity() const { return fuelCapacity; }
    virtual double getFuelConsumption() const { return fuelConsumption; }
    virtual double getAvgSpeed(Weather weather) const {
        switch (weather) {
        case Weather::Rain: return avgSpeedRain;
        case Weather::Sunny: return avgSpeedSunny;
        case Weather::Snow: return avgSpeedSnow;
        default: return avgSpeedSunny;
        }
    }
    virtual std::string getName() const { return name; }

    virtual void setCharacteristics() = 0;
};