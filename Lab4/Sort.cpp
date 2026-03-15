#include <iostream>
#include "Sort.h"

using namespace std;

Sort::Sort(int elements, int minim, int maxim)
{
    count = elements;
    lista = new int[count];

    for (int i = 0; i < count; i++)
        lista[i] = minim + rand() % (maxim - minim + 1);
}

Sort::Sort(int* vector, int elements)
{
    count = elements;
    lista = new int[count];

    for (int i = 0; i < count; i++)
        lista[i] = vector[i];
}

Sort::Sort(int count, ...)
{
    this->count = count;
    lista = new int[count];

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
        lista[i] = va_arg(args, int);

    va_end(args);
}

Sort::Sort(const char* values)
{
    count = 1;
    int i = 0;

    while (values[i] != '\0')
    {
        if (values[i] == ',')
            count++;
        i++;
    }

    lista = new int[count];

    int index = 0;
    int number = 0;

    for (i = 0; ; i++)
    {
        if (values[i] == ',' || values[i] == '\0')
        {
            lista[index] = number;
            index++;
            number = 0;

            if (values[i] == '\0')
                break;
        }
        else
        {
            number = number * 10 + (values[i] - '0');
        }
    }
}

void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < count; i++)
    {
        int key = lista[i];
        int j = i - 1;

        if (ascendent)
        {
            while (j >= 0 && lista[j] > key)
            {
                lista[j + 1] = lista[j];
                j--;
            }
        }
        else
        {
            while (j >= 0 && lista[j] < key)
            {
                lista[j + 1] = lista[j];
                j--;
            }
        }

        lista[j + 1] = key;
    }
}

void Sort::QuickSort(bool ascendent)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (ascendent)
            {
                if (lista[i] > lista[j])
                {
                    int aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
            else
            {
                if (lista[i] < lista[j])
                {
                    int aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
    }
}

void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (ascendent)
            {
                if (lista[j] > lista[j + 1])
                {
                    int aux = lista[j];
                    lista[j] = lista[j + 1];
                    lista[j + 1] = aux;
                }
            }
            else
            {
                if (lista[j] < lista[j + 1])
                {
                    int aux = lista[j];
                    lista[j] = lista[j + 1];
                    lista[j + 1] = aux;
                }
            }
        }
    }
}

void Sort::Print()
{
    for (int i = 0; i < count; i++)
        cout << lista[i] << " ";

    cout << endl;
}

int Sort::GetElementsCount()
{
    return count;
}

int Sort::GetElementFromIndex(int index)
{
    if (index < 0 || index >= count)
        return -1;

    return lista[index];
}