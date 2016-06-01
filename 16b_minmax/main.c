#include <stdio.h>
#include <stdlib.h>
int a[5],db=5, osszeg,min,max,i;

int main()
{
    printf("Adj meg egy szamot: ");
    scanf("%i",&a[0]);
    osszeg = a[0];

    min=a[0];
    max=a[0];
    i = 0;
    while(a[i]!= 0 && i<(db-1))
    {
        i = i + 1;
        printf("Adjon meg egy szamot: ");
        scanf("%i",&a[i]);
        if(a[i]!=0 && a[i]<min)
        {
            min=a[i];
        }
        if(a[i]!=0 && a[i]>max)
        {
            max=a[i];
        }

        osszeg = osszeg + a[i];
    }
    if(a[i]!=0)
    {
        i=i+1;
    }
    db=i;
    if (db!=1)
    {
        printf("darab szam:%i \n", db);
        printf("Osszeg:%d\n",osszeg);
        printf("Atlag:%f\n",osszeg/(float)db);
        printf("Min:%i\n",min);
        printf("max:%i\n",max);
        printf("Ezeket adtad meg:");

        i=0;
        while (i<db)
        {
            printf("%i\n",a[i]);
            i=i+1;
        }
        printf("Visszafelé:");

        i=db-1;
        while (i>-1)
        {
            printf("%i\n",a[i]);
            i=i-1;
        }

    }

    return 0;
}
