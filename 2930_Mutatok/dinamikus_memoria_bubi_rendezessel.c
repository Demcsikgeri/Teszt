#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <mem.h>
#include <stdlib.h>

void bubi(int *z, int elemszam)
{
    int i,j;
    /*
    5314
    3514
    3154
    314,5

    134,5
    134,5

    13,45
    13,45

    1,345

    1345
    */



    for (i=0; i<elemszam-1; i++)
        for (j=0; j<elemszam-1-i; j++)
            if (z[j]<z[j+1])
            {
                int megegyvaltozo=z[j];
                z[j]=z[j+1];
                z[j+1]=megegyvaltozo;
            }
}

int main()
{
    int *t=NULL;

    int szam;
    int visszateresi_ertek;

    int i=0;

    do
    {
        printf("Adjon meg egy számot:");
        visszateresi_ertek=scanf("%i",&szam);
        if (visszateresi_ertek==1)
        {
            // itt van szam

            int *tmp=(int *)realloc(t,(i+1)*sizeof(int));
            if (tmp==NULL)
            {
                printf("Baj van!");
                exit(1);
            }

            t=tmp;

            t[i]=szam;
            i+=1;
        }
    }
    while(visszateresi_ertek==1);

    bubi(t,i);

    int ize;

    for (ize=0; ize<i;ize+=1)
        printf("%i,",t[ize]);


    getch();
    return 0;
}
