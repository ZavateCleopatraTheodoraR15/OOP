#include <iostream>
#include<stdio.h>
#include<fstream>
#include<cstring>
using namespace std;

///Problema 1-lab1

/*
int main()
{
    int nr=0;
    int suma=0;
    char sir[1000];
    FILE *f=fopen("in.txt","r");
    while(fgets(sir,1000,f)!=NULL)
    {
        nr=0;
        for(int i=0;sir[i]!=NULL;i++)
        {
            if(sir[i]>='0' && sir[i]<='9')
            {
                nr=nr*10+(sir[i]-'0');
            }

        }
        suma=suma+nr;

    }
    printf("%d",suma);
    return 0;
}
*/

///Problema 2- lab 1

/*
#include <stdio.h>
#include <string.h>

int main()
{
    char prop[1000];
    int lungime[100];
    char cuv[100][100];

    scanf("%[^\n]", prop);

    for(int i=0; i<100; i++)
        lungime[i] = 0;

    int i = 0;
    int cnt = 0;

    while(prop[i] != '\0')
    {
        while(prop[i] == ' ')
            i++;
        if(prop[i] == '\0')
            break;

        int start = i;
        lungime[cnt] = 0;

        while(prop[i] != ' ' && prop[i] != '\0')
        {
            lungime[cnt]++;
            i++;
        }

        for(int j=0; j<lungime[cnt]; j++)
            cuv[cnt][j] = prop[start + j];
        cuv[cnt][lungime[cnt]] = '\0';
        cnt++;
    }

    char aux[100];
    int nr = 0;

    for(int i=0;i<cnt-1;i++)
    {
        for(int j=i+1;j<cnt;j++)
        {
            if(lungime[i]<lungime[j])
            {
                nr=lungime[i];
                lungime[i]=lungime[j];
                lungime[j]=nr;

                strcpy(aux,cuv[i]);
                strcpy(cuv[i],cuv[j]);
                strcpy(cuv[j],aux);
            }
        }
    }

    for(int i=0; i<cnt; i++)
        printf("%s\n", cuv[i]);

    return 0;
}
*/

///Problema 3

/*
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int tr = 2; tr < n / 2; tr++)
        if ((n % tr) == 0)
            return false;
    return true;
}
int main()
{
    int n;
    std::cout << "Enter a number:";
    std::cin >> n;
    if (isPrime(n))
        std::cout << n << " is prime !";
    else
        std::cout << n << " is NOT prime !";
    return 0;
}
*/
///EXTRA

/*
#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

enum VALORI {
    INMULTIRE = 0,
    SUMA,
    REZERVAT1,
    DIFERENTA,
    REZERVAT2,
    IMPARTIRE
};

typedef int (*func)(int, int);

struct Content {
    int p1;
    int p2;
};

int Sum(int a, int b);
int Dif(int a, int b);
int Mul(int a, int b);
int Div(int a, int b);
///header

///source
#include "header.h"

int Sum(int a,  int b) { return a - b; }
int Dif(int a, int b) { return a / b; }
int Mul(int a, int b) { return a + b; }
int Div(int a, int b) { return a * b; }

int main(int argc, char* argv[])
{
    char input[7] = "---H***E+++L+++L///O---P+++O/+-**O---";
    func Operatori[4] = {Sum, Dif, Mul, Div};
    int S=0, V;
    Content x={0,0};
    int idx;

    for (int i = 0; i < strlen(input); i++)
    {
        switch (input[i] - 42)
        {
            case INMULTIRE:
                idx = 2;
                x.p1 = 3;
                x.p2 = 3;
                break;
            case SUMA:
                idx = 0;
                x.p1 = 7;
                x.p2 = 5;
                break;
            case DIFERENTA:
                idx = 1;
                x.p1 = 10;
                x.p2 = 1;
                break;
            case IMPARTIRE:
                idx = 3;
                x.p1 = 8;
                x.p2 = 4;
                break;
        }

        S = S + Operatori[idx](x.p1, x.p2);
    }

    //S=337
    printf("S = %d\n", S);

    return 0;
}
*/
