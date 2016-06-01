#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fej.h"

int main()
{
    setlocale(LC_ALL, "");
    // Első variáció
    int a=5;
    int b=6;
    int temp;

    temp=a;
    a=b;
    b=temp,

    printf("a=%d , b=%d\n",a,b);

    // Második variáció
    int c=3;
    int d=4;

    c=c+d;
    d=c-d;
    c=c-d;

    printf("c=%d , d=%d\n",c,d);
    return 0;
}
