#include "Student.h"

int ComparaNume(const Student& s1, const Student& s2)
{
    if (s1.GetName() == s2.GetName())
        return 0;

    if (s1.GetName() > s2.GetName())
        return 1;

    return -1;
}

int ComparaMate(const Student& s1, const Student& s2)
{
    if (s1.GetNotaMate() == s2.GetNotaMate())
        return 0;

    if (s1.GetNotaMate() > s2.GetNotaMate())
        return 1;

    return -1;
}

int ComparaEngleza(const Student& s1, const Student& s2)
{
    if (s1.GetNotaEngleza() == s2.GetNotaEngleza())
        return 0;

    if (s1.GetNotaEngleza() > s2.GetNotaEngleza())
        return 1;

    return -1;
}

int ComparaIstorie(const Student& s1, const Student& s2)
{
    if (s1.GetNotaIstorie() == s2.GetNotaIstorie())
        return 0;

    if (s1.GetNotaIstorie() > s2.GetNotaIstorie())
        return 1;

    return -1;
}

int ComparaMedie(const Student& s1, const Student& s2)
{
    if (s1.GetMedie() == s2.GetMedie())
        return 0;

    if (s1.GetMedie() > s2.GetMedie())
        return 1;

    return -1;
}