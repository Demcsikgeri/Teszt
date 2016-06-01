#include <stdio.h>
#include <stdlib.h>

int p, oszt, odb,sz;

int main()
{
    printf("Adj meg egy szamot, eldontjuk, hogy prim-e!\n");
    scanf("%i",&sz);
    p=1;
    while(p<=sz)
    {
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
            printf("%i ",p);
        }
        p=p+1;
    }
    return 0;
}
