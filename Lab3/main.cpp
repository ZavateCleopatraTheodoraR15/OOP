#include "Canvas.h"

int main()
{
    Canvas c(40, 20);

    // Draw rectangle
    c.DrawRect(5, 3, 20, 10, '#');
    c.Print();
    c.Clear();

    std::cout << "\n";

    // Fill rectangle
    c.FillRect(5, 3, 20, 10, '*');
    c.Print();
    c.Clear();

    std::cout << "\n";

    // Draw circle
    c.DrawCircle(20, 10, 6, '@');
    c.Print();
    c.Clear();

    std::cout << "\n";

    // Fill circle
    c.FillCircle(20, 10, 6, '+');
    c.Print();
    c.Clear();

    std::cout << "\n";

    // Draw line
    c.DrawLine(0, 0, 30, 15, '/');
    c.Print();
    c.Clear();

    std::cout << "\n";

    // SetPoint example
    c.SetPoint(10, 5, 'X');
    c.Print();
    c.Clear();

    return 0;
}