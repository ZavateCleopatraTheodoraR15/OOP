#include "Math.h"
#include <cstdarg>  
#include <cstring>  
#include <cstdlib> 

int Math::Add(int a, int b) 
{
    return a + b;
}

int Math::Add(int a, int b, int c) 
{
    return a + b + c;
}

int Math::Add(double a, double b) 
{
    return a + b; 
}

int Math::Add(double a, double b, double c) 
{
    return a + b + c;  
}

int Math::Mul(int a, int b) 
{
    return a * b;
}

int Math::Mul(int a, int b, int c) 
{
    return a * b * c;
}

int Math::Mul(double a, double b) 
{
    return a * b; 
}

int Math::Mul(double a, double b, double c) 
{
    return a * b * c;
}

int Math::Add(int count, ...) 
{
    int sum = 0;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i)
        sum += va_arg(args, int);

    va_end(args);
    return sum;
}

char* Math::Add(const char* str1, const char* str2) 
{
    if (str1 == nullptr || str2 == nullptr) 
        return nullptr;

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t length = len1 + len2 + 1;

    char* result = (char*)malloc(length);
    if (result == nullptr) {
        return nullptr;
    }

    strcpy_s(result, length, str1);
    strcat_s(result, length, str2);

    return result;
}
