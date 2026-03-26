#include "Car.h"
#include "Weather.h"
#include <vector>
#include <string>
#include <utility>

class Circuit {
private:
    double length;
    Weather weather;
    std::vector<Car*> cars;
    std::vector<std::pair<std::string, double>> raceResults;
    std::vector<std::string> didNotFinish;

public:
    Circuit();
    ~Circuit();

    void SetLength(double len);
    void SetWeather(Weather w);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks() const;
    void ShowWhoDidNotFinish() const;
};