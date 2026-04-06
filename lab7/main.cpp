#include <iostream>

float operator"" _Kelvin(unsigned long long kelvin);
float operator"" _Fahrenheit(unsigned long long fahrenheit);

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    return 0;
}

float operator"" _Kelvin(unsigned long long kelvin) {
    return static_cast<float>(kelvin - 273.15);
}

float operator"" _Fahrenheit(unsigned long long fahrenheit) {
    return static_cast<float>((fahrenheit - 32) * 5 / 9);
}
