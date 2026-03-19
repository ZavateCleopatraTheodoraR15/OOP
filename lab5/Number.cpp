#include "Number.h"
#include <stdio.h>
#include <stdlib.h>

Number::Number(const char* value, int base) {
    this->base = base;
    this->digitCount = 0;

    while (value[this->digitCount] != '\0') {
        this->digitCount++;
    }

    this->value = new char[this->digitCount + 1];
    for (int i = 0; i < this->digitCount; i++) {
        this->value[i] = value[i];
    }
    this->value[this->digitCount] = '\0';
}

Number::Number(int number) {
    this->base = 10;
    this->value = new char[2];
    this->value[0] = '0';
    this->value[1] = '\0';
    this->digitCount = 1;

    this->convertFromBase10(number, 10);
}

Number::~Number() {
    delete[] this->value;
}

Number::Number(const Number& other) {
    this->base = other.base;
    this->digitCount = other.digitCount;

    this->value = new char[this->digitCount + 1];
    for (int i = 0; i <= this->digitCount; i++) {
        this->value[i] = other.value[i];
    }
}

Number::Number(Number&& other) {
    this->value = other.value;
    this->base = other.base;
    this->digitCount = other.digitCount;

    other.value = NULL;
    other.digitCount = 0;
}

Number& Number::operator=(Number&& other) {
    if (this != &other) {
        delete[] this->value;

        this->value = other.value;
        this->base = other.base;
        this->digitCount = other.digitCount;

        other.value = NULL;
        other.digitCount = 0;
    }
    return *this;
}

Number& Number::operator=(int number) {
    this->convertFromBase10(number, this->base);
    return *this;
}

Number& Number::operator=(const char* str) {
    delete[] this->value;

    this->digitCount = 0;
    while (str[this->digitCount] != '\0') {
        this->digitCount++;
    }

    this->value = new char[this->digitCount + 1];
    for (int i = 0; i <= this->digitCount; i++) {
        this->value[i] = str[i];
    }

    return *this;
}

int Number::convertToBase10() const {
    int result = 0;
    for (int i = 0; i < this->digitCount; i++) {
        result = result * this->base;
        if (this->value[i] >= '0' && this->value[i] <= '9') {
            result = result + (this->value[i] - '0');
        }
        else {
            result = result + (this->value[i] - 'A' + 10);
        }
    }
    return result;
}

void Number::convertFromBase10(int number, int newBase) {
    if (number == 0) {
        delete[] this->value;
        this->value = new char[2];
        this->value[0] = '0';
        this->value[1] = '\0';
        this->digitCount = 1;
        this->base = newBase;
        return;
    }

    char* temp = new char[100];
    int tempIndex = 0;
    int num = number;

    while (num > 0) {
        int digit = num % newBase;
        if (digit < 10) {
            temp[tempIndex] = '0' + digit;
        }
        else {
            temp[tempIndex] = 'A' + (digit - 10);
        }
        tempIndex++;
        num = num / newBase;
    }

    delete[] this->value;
    this->value = new char[tempIndex + 1];
    this->digitCount = tempIndex;

    for (int i = 0; i < tempIndex; i++) {
        this->value[i] = temp[tempIndex - 1 - i];
    }
    this->value[tempIndex] = '\0';

    delete[] temp;
    this->base = newBase;
}

void Number::SwitchBase(int newBase) {
    if (this->base == newBase) return;

    int number = this->convertToBase10();
    this->convertFromBase10(number, newBase);
}

void Number::Print() const {
    printf("%s\n", this->value);
}

int Number::GetDigitsCount() const {
    return this->digitCount;
}

int Number::GetBase() const {
    return this->base;
}

char Number::operator[](int index) const {
    if (index >= 0 && index < this->digitCount) {
        return this->value[index];
    }
    return '\0';
}

bool Number::operator>(const Number& other) const {
    return this->convertToBase10() > other.convertToBase10();
}

bool Number::operator<(const Number& other) const {
    return this->convertToBase10() < other.convertToBase10();
}

bool Number::operator>=(const Number& other) const {
    return this->convertToBase10() >= other.convertToBase10();
}

bool Number::operator<=(const Number& other) const {
    return this->convertToBase10() <= other.convertToBase10();
}

bool Number::operator==(const Number& other) const {
    return this->convertToBase10() == other.convertToBase10();
}

bool Number::operator!=(const Number& other) const {
    return this->convertToBase10() != other.convertToBase10();
}

Number operator+(const Number& a, const Number& b) {
    int val1 = a.convertToBase10();
    int val2 = b.convertToBase10();

    int resultBase;
    if (a.base > b.base)
        resultBase = a.base;
    else
        resultBase = b.base;

    Number result("0", 10);
    result.convertFromBase10(val1 + val2, resultBase);
    return result;
}

Number operator-(const Number& a, const Number& b) {
    int val1 = a.convertToBase10();
    int val2 = b.convertToBase10();

    int resultBase;
    if (a.base > b.base)
        resultBase = a.base;
    else
        resultBase = b.base;

    Number result("0", 10);
    if (val1 >= val2) {
        result.convertFromBase10(val1 - val2, resultBase);
    }
    else {
        result.convertFromBase10(0, resultBase);
    }
    return result;
}

Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

Number& Number::operator--() {
    if (this->digitCount <= 1) {
        delete[] this->value;
        this->value = new char[2];
        this->value[0] = '0';
        this->value[1] = '\0';
        this->digitCount = 1;
    }
    else {
        char* newValue = new char[this->digitCount];
        for (int i = 0; i < this->digitCount - 1; i++) {
            newValue[i] = this->value[i + 1];
        }
        newValue[this->digitCount - 1] = '\0';

        delete[] this->value;
        this->value = newValue;
        this->digitCount--;
    }
    return *this;
}

Number Number::operator--(int) {
    Number temp = *this;

    if (this->digitCount <= 1) {
        delete[] this->value;
        this->value = new char[2];
        this->value[0] = '0';
        this->value[1] = '\0';
        this->digitCount = 1;
    }
    else {
        char* newValue = new char[this->digitCount];
        for (int i = 0; i < this->digitCount - 1; i++) {
            newValue[i] = this->value[i];
        }
        newValue[this->digitCount - 1] = '\0';

        delete[] this->value;
        this->value = newValue;
        this->digitCount--;
    }

    return temp;
}