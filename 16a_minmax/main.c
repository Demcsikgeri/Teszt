#include <stdio.h>
#include <stdlib.h>
int a, db, osszeg,min,max;
int main()
{
    printf("Adj meg egy szamot: ");
    scanf("%i",&a);
    osszeg = a;
    db=1;
    min=a;
    max=a;
    while(a!= 0)
    {
        printf("Adjon meg egy szamot: ");
        scanf("%i",&a);
        if(a!=0 && a<min)
        {
            min=a;
        }
        if(a!=0 && a>max)
        {
            max=a;
        }
        db=db+1;
        osszeg = osszeg + a;
    }
    if (db!=1)
    {
        printf("darab szam:%i \n", db-1);
        printf("Osszeg:%d\n",osszeg);
        printf("Atlag:%f\n",osszeg/(float)(db-1));
        printf("Min:%i\n",min);
        printf("max:%i\n",max);


    }

    return 0;
}
