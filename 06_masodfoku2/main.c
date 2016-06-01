#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a,b,c,d;
float x1,x2;

int main()
{
    printf("Add meg a masodfoku egyenlet tenyezoit!\n");
    scanf("%i",&a);
    scanf("%i",&b);
    scanf("%i",&c);
    d=b*b-4*a*c;
    if(d<0)
    {   //d negativ
        printf("nincs megoldas");
    }
    else
    {
        //d 0, pozitiv
        x1=0.0+(-b+sqrt(d))/(2*a);
        printf("x1: %f\n",x1);
        if(d>0)
        {
           x2=0.0+(-b-sqrt(d))/(2*a);
           printf("x2: %f",x2);
        }
    }
    return 0;
}
