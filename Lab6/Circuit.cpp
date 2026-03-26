#include "Circuit.h"
#include <iostream>
#include <algorithm>

Circuit::Circuit() : length(0), weather(Weather::Sunny) {}

Circuit::~Circuit() {
    for (Car* car : cars) {
        delete car;
    }
}

void Circuit::SetLength(double len) {
    length = len;
}

void Circuit::SetWeather(Weather w) {
    weather = w;
}

void Circuit::AddCar(Car* car) {
    cars.push_back(car);
}

void Circuit::Race() {
    raceResults.clear();
    didNotFinish.clear();

    for (Car* car : cars) {
        double speed = car->getAvgSpeed(weather);
        double time = length / speed;

        double fuelNeeded = (car->getFuelConsumption() * length) / 100.0;

        if (car->getFuelCapacity() >= fuelNeeded) {
            raceResults.push_back({ car->getName(), time });
        }
        else {
            didNotFinish.push_back(car->getName());
        }
    }

    std::sort(raceResults.begin(), raceResults.end(),
        [](const std::pair<std::string, double>& a,
            const std::pair<std::string, double>& b) {
                return a.second < b.second;
        });
}

void Circuit::ShowFinalRanks() const {
    for (size_t i = 0; i < raceResults.size(); ++i) {
        std::cout << (i + 1) << ". " << raceResults[i].first
            << " - " << raceResults[i].second << " hours" << std::endl;
    }
}

void Circuit::ShowWhoDidNotFinish() const {
    if (didNotFinish.empty()) {
        std::cout << "All cars finished the race" << std::endl;
    }
    else {
        std::cout << "Cars that did not finish (ran out of fuel):" << std::endl;
        for (const auto& carName : didNotFinish) {
            std::cout << "- " << carName << std::endl;
        }
    }
}