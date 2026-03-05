#include "Canvas.h"
#include <cmath>
#include <iostream>

Canvas::Canvas(int width, int height)
{
    this->width = width;
    this->height = height;

    matrix = new char* [height];
    for (int i = 0; i < height; i++)
    {
        matrix[i] = new char[width];
    }

    Clear();
}

Canvas::~Canvas()
{
    for (int i = 0; i < height; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void Canvas::Clear()
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            matrix[i][j] = ' ';
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
        matrix[y][x] = ch;
}

void Canvas::Print()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            std::cout << matrix[i][j];
        std::cout << std::endl;
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = left; i <= right; i++)
    {
        SetPoint(i, top, ch);
        SetPoint(i, bottom, ch);
    }

    for (int i = top; i <= bottom; i++)
    {
        SetPoint(left, i, ch);
        SetPoint(right, i, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int y = top; y <= bottom; y++)
        for (int x = left; x <= right; x++)
            SetPoint(x, y, ch);
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < 360; i++)
    {
        double rad = i * 3.14159 / 180;
        int px = x + ray * cos(rad);
        int py = y + ray * sin(rad);
        SetPoint(px, py, ch);
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = -ray; i <= ray; i++)
        for (int j = -ray; j <= ray; j++)
            if (i * i + j * j <= ray * ray)
                SetPoint(x + j, y + i, ch);
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (true)
    {
        SetPoint(x1, y1, ch);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}