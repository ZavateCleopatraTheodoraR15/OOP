#pragma once
#include <iostream>
#include <cstdarg>

using namespace std;

class Sort
{
private:
    int* lista;
    int count;

public:

    Sort(int elements, int minim, int max);
    Sort(int* vector, int elements);
    Sort(int count, ...);
    Sort(const char* values);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print();

    int GetElementsCount();
    int GetElementFromIndex(int index);
};