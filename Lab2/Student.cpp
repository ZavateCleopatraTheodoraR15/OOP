#include "Student.h"
#include<iostream>
using namespace std;
void Student::SetName(const string& n)
{
	name = n;
}
string Student::GetName() const
{
	return name;
}

bool Student::SetNotaMate(float grade)
{
    if (grade < 1 || grade > 10)
        return false;
    Nota_Mate = grade;
    return true;
}
float Student::GetNotaMate() const
{
    return Nota_Mate;
}

bool Student::SetNotaEngleza(float grade)
{
    if (grade < 1 || grade > 10)
        return false;
    Nota_Engleza = grade;
    return true;
}
float Student::GetNotaEngleza() const
{
    return Nota_Engleza;
}

bool Student::SetNotaIstorie(float grade)
{
    if (grade < 1 || grade > 10)
        return false;
    Nota_Istorie = grade;
    return true;
}
float Student::GetNotaIstorie() const
{
    return Nota_Istorie;
}

float Student::GetMedie() const
{
    return (Nota_Mate + Nota_Engleza + Nota_Istorie) / 3;
}
