#include "Canvas.h"
#include <cstdarg>

Canvas::Canvas(int lines, int columns)
{
    this->lines = lines;
    this->columns = columns;

    matrix = new char* [lines];
    for (int i = 0; i < lines; i++)
        matrix[i] = new char[columns];

    clear();
}

Canvas::~Canvas()
{
    for (int i = 0; i < lines; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void Canvas::clear()
{
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = ' ';
}

void Canvas::set_pixel(int x, int y, char value)
{
    if (x >= 0 && x < lines && y >= 0 && y < columns)
        matrix[x][y] = value;
}

void Canvas::set_pixels(int count, ...)
{
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        int value = va_arg(args, int);

        set_pixel(x, y, (char)value);
    }

    va_end(args);
}

void Canvas::print() const
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
            std::cout << matrix[i][j];
        std::cout << std::endl;
    }
}