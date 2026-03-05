#pragma once
#include <iostream>

class Canvas {
private:
    int lines, columns;
    char** matrix;

public:
    Canvas(int lines, int columns);
    ~Canvas();

    void set_pixel(int x, int y, char value);
    void set_pixels(int count, ...);

    void clear();
    void print() const;
};