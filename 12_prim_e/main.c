#include <stdio.h>
#include <stdlib.h>

int p, oszt, odb;

int main()
{
    printf("Adj meg egy szamot, eldontjuk, hogy prim-e!\n");
    scanf("%i",&p);
    odb=0;
    oszt=2;
    while(oszt<=(p/2) && odb==0)
    {
       if(p%oszt==0)
       {
         odb=1;
       }
       oszt=oszt+1;
    }
    if(odb==0)
    {
        printf("prim");
    }
    else
    {
        printf("nem prim");
    }
    return 0;
}
