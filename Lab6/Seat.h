#include "Car.h"

class Seat : public Car {
public:
    Seat();
    void setCharacteristics() override;
};