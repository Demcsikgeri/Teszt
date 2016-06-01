#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int szamok[100][100];

void general()
{
    int x,y;

    for (y=0; y<100; y+=1)
        for (x=0; x<100; x+=1)
            szamok[y][x]=(rand()%(1456-123))+123;
}

float avg()
{
    int osszeg=0;

    int x,y;

    for (y=0; y<100; y+=1)
        for (x=0; x<100; x+=1)
            osszeg=osszeg+szamok[y][x];

    return osszeg/(100.0*100.0);
}

float min()
{
    int z=szamok[0][0];

    int x,y;

    for (y=0; y<100; y+=1)
        for (x=0; x<100; x+=1)
            if (szamok[y][x]<z)
                z=szamok[y][x];

    return z;
}

float max()
{
    int z=szamok[0][0];

    int x,y;

    for (y=0; y<100; y+=1)
        for (x=0; x<100; x+=1)
            if (szamok[y][x]>z)
                z=szamok[y][x];

    return z;
}

int kisebbmint(int szam)
{
    int z=0;

    int x,y;

    for (y=0; y<100; y+=1)
        for (x=0; x<100; x+=1)
            if (szamok[y][x]<szam)
                z+=1;

    return z;
}

int paros()
{
    int z=0;

    int x,y;

    for (y=0; y<100; y+=1)
        for (x=0; x<100; x+=1)
            if ((szamok[y][x]%2) == 0)
                z+=1;

    return z;
}

int main()
{
    srand(time(NULL));

    general();

    printf("AVG:%f",avg());
    printf("MIN:%f",min());
    printf("MAX:%f",max());

    getch();
    return 0;
}
