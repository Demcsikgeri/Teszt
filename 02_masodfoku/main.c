#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a,b,c;
float x1,x2;

int main()
{
    printf("Add meg a masodfoku egyenlet tenyezoit!\n");
    scanf("%i",&a);
    scanf("%i",&b);
    scanf("%i",&c);
    x1=0.0+(-b+sqrt(b*b-4*a*c))/(2*a);
    x2=0.0+(-b-sqrt(b*b-4*a*c))/(2*a);
    printf("x1: %f\n",x1);
    printf("x2: %f",x2);
    return 0;
}
